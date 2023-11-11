#include <bits/stdc++.h>
using namespace std;
class Machine {

};

class Memory{
private:
    int size;
public:
    vector <pair<int,string>> data;
    Memory(int memorySize) : size(memorySize) , data(memorySize , {0 , ""}){};

    string read(int address){
        if (address >= 0 && address < size){
            return data[address].second;
        }
        else{
            cerr << "Error: Attempt to read invalid memory address " << address << endl;
            exit(1);
        }
    }
    void write(int address , string &value){
        if (address >= 0 && address < size){
          
            string x = value.substr(0,2);
            data[address].second =x ;
            data[address].first = address;
          
            x = value.substr(2 , 4);
            data[address + 1].second = x;
            data[address + 1].first = address + 1;
          
        } else{
            cerr << "Error: Attempt to read invalid memory address " << address << endl;
            exit(1);
        }
    }

};

class Register{

};

class arithmeticUnit {

};

