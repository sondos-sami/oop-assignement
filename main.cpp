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
    Memory(int memorySize) : size(memorySize) , data(memorySize , {"" , ""}){};

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

        } else{
            cerr << "Error: Attempt to read invalid memory address " << address << endl;
            exit(1);
        }
    }

};
 class Machine {
    private:
        Memory& memory;
        int pc;
        vector<string> registers;
        char op_code;
        int output_register;
        string memory_cell;
        string val_mem;
        int m;


    public:
        Machine(Memory& mem) : memory(mem),  registers(16, 0), pc(0) {}

        int fetch() {
            string  instruction = memory.read(pc);

        }

        void decode(string  instruction) {
           if(instruction[0]=='1'){//1056
             op_code='1';
             output_register=instruction[1];
             memory_cell=instruction[2]+instruction[3];

           }
           else if(instruction[0]=='2'){
               op_code='2';
               output_register=instruction[1];
             val_mem =instruction.substr(2);
           }
        /*   else if(instruction[0]=='3'){
               op_code='3';
           }
           else if(instruction[0]=='4'){
               op_code='4';
           }
           else if(instruction[0]=='5'){
               op_code='5';
           }
           else if(instruction[0]=='6'){
               op_code='6';
           }else if(instruction[0]=='B'){
               op_code='B';
           }


        }
*/}
        void execute(string instruction){
            while(instruction!="C000"){
                if(op_code=='1'){
                    int m= stoi(memory_cell);
                    registers[output_register]=memory.read(m);
                }
            }

    }};


class Register:public Machine{
    vector<string> registers;
public:

string instruction_register;

void set_value(int reg_num,int new_val){
    registers[reg_num-1]=new_val;
}
void display_status(int num){//5
cout<<"Register "<<num<<" now contains :"<<registers[num-1]<<endl;
}

};



class arithmeticUnit {

};

