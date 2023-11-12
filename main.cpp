#include <bits/stdc++.h>
using namespace std;

string decToHex(string n){

    string hexDeciNum;
    int z = stoi(n);
    int i = 0;

    while(z != 0){

        int temp;
        temp = z % 16;

        if(temp < 10){
            hexDeciNum.push_back(temp + 48);
            i++;
        }

        else{
            hexDeciNum.push_back(temp + 55);
            i++;
        }

        z /= 16;
    }

    reverse(hexDeciNum.begin() , hexDeciNum.end());
    return hexDeciNum;
}

int hexToDec(string hex){

    int len = hex.size();
    int base = 1;
    int dec = 0;

    for (int i = len - 1; i >= 0 ; --i) {

        if(hex[i] >= '0' && hex[i] <= '9'){
            dec += (int(hex[i]) - 48) * base;
            base = base * 16;
        }

        else if(hex[i] >= 'A' && hex[i] <= 'F') {
            dec += (int(hex[i]) - 55) * base;
            base = base * 16;
        }

    }

    return dec;
}

class Memory{
private:
    int size;
public:
    vector <pair<string ,string>> data;
    Memory(int memorySize) : size(memorySize) , data(memorySize , {"0" , "0"}){};

    string read(string address){

        int n = hexToDec(address);
        if (n >= 0 && n < size){
            return data[n].second;
        }

        else{
            cerr << "Error: Attempt to read invalid memory address " << address << endl;
            exit(1);
        }
    }

    void write(string address , string &value){

        int n = stoi(address);

        if (n >= 0 && n < size){

            string x = value.substr(0,2);
            data[n].second = x;

            if(n == 0){
                data[n].first = "0";
            }

            else{
                data[n].first = decToHex(address);
            }

            x = value.substr(2 , 4);
            data[n + 1].second = x;
            data[n + 1].first = decToHex(to_string(n + 1));

        }

        else{
            cerr << "Error: Attempt to read invalid memory address " << address << endl;
            exit(1);
        }
    }
};

class Machine {
private:
    Memory &memory;
    string pc;
    vector<string> registers;
public:
    Machine(Memory &mem) : memory(mem), registers(16, "0"), pc("0") {}

    string fetch() {
        string instruction = memory.read(pc);
        int n = stoi(pc);
        n++;
        pc = to_string(n);
        instruction += memory.read(pc);
        return instruction;
    }

    void execute(string instruction) {

        if (instruction[0] == '1') { // done
            registers[instruction[1] - '0'] = memory.read(instruction.substr(2, 4));
        }
        else if (instruction[0] == '2') { // done
            registers[instruction[1] - '0'] = instruction.substr(2, 4);
        }
        else if (instruction[0] == '3') { // done

            // represent the address in decimal to find its memory cell easy
            int x = hexToDec(instruction.substr(2, 4));
            memory.data[x].second = decToHex(registers[instruction[1] - '0']);
        }
        else if (instruction[0] == '4') { //done
            string x;
            x.push_back(instruction[2]);
            int x1 = hexToDec(x);

            string y;
            y.push_back(instruction[3]);
            int y1 = hexToDec(y);

            registers[y1] = registers[x1];
        }
        else if (instruction[0] == '5') { //done

            string x;
            x.push_back(instruction[2]);
            int r1 = hexToDec(x);

            string y;
            y.push_back(instruction[3]);
            int r2 = hexToDec(y);

            int sum = r1 + r2;

            registers[instruction[1] - '0'] = to_string(sum);

        }
        else if (instruction[0] == 'B') { //done
            if (registers[instruction[1] - '0'] == registers[0]) {
                pc = instruction.substr(2, 4);
            }
        }
    }

};
