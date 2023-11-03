#include <iostream>
#include<string>

#include<cstdlib>
 using namespace std;
class BigReal {
private:
    char sign = '+';
    string integer_part;
    string fraction_part;
    string realNumber;

    bool isValidReal(string realNumber);

public:
    BigReal(double realNumber=0.0);
    BigReal (string realNumber);
    BigReal(const BigReal &other);
    BigReal& operator= (BigReal& other);
    /* Depending on how you store data, default can be enough
    void setNum (string realNumber);

    int sign();
    int size();
    BigReal operator+ (BigReal& other);
    BigReal operator- (BigReal& other);
    bool operator< (BigReal anotherReal);
    bool operator> (BigReal anotherReal);
    bool operator== (BigReal anotherReal);
    friend ostream& operator << (ostream& out, BigReal num);
*/
};
bool isValid(string realNumber){

    if(realNumber.empty()){//if the string is empty then it is not valid as a number
        return false;
    }
    if(realNumber[realNumber.length()-1]=='.'){
        return false;
    }


    string dot="";
    for(int i=0;i<realNumber.length();++i){
        if((realNumber[i]=='+'&&i!=0)||(realNumber[i]=='-'&&i!=0)){
            return false;
        }

        if(realNumber[i]>='a'&&realNumber[i]<='z'){
            return false;
        }
        else  if(!(realNumber[i]>='0'&&realNumber[i]<='9')&& (realNumber[i]!='+')&&(realNumber[i]!='-')&&(realNumber[i]!='.')){

            return false;

        }

        else if(realNumber[i]=='.'){
            if(dot.empty()){
                dot+=realNumber[i];
            }
            else{
                return false;//if there is more than one dot
            }

        }


    }return true;
}
BigReal::BigReal(double realNumber ){

    string RealNumber  = to_string(realNumber);//convert double to string

    if(isValid(RealNumber)) {
        if (RealNumber[0] == '+' || RealNumber[0] == '-') {

            sign = RealNumber[0];
            RealNumber.erase(0, 1);
        }
    }
    if(isValid(RealNumber)){//we divide string into two parts (integer_part which is before . and fraction part which is after it)
        integer_part= RealNumber.substr(0,RealNumber.find("."));
        fraction_part= RealNumber.substr(integer_part.size()+1);
    }
    if(integer_part.empty()){
        integer_part="0";
    }
    if(fraction_part.empty()){
        fraction_part="0";
    }

   /* cout<<sign<<endl;
    cout<<integer_part<<endl;
   */ cout<<fraction_part<<endl;

}


   BigReal::BigReal (string realNumber){// Initialize from string
   if(isValid(realNumber)) {
       if (realNumber[0] == '+' || realNumber[0] == '-') {

           sign = realNumber[0];
           realNumber.erase(0, 1);
       }
   }

       if(isValid(realNumber)){

           integer_part= realNumber.substr(0,realNumber.find("."));
           fraction_part= realNumber.substr(integer_part.size()+1);
       }
       if(integer_part.empty()){
           integer_part="0";
       }
       if(fraction_part.empty()){
           fraction_part="0";
       }


    /*  cout<<sign<<endl;
       cout<<integer_part<<endl;
       cout<<fraction_part<<endl;
*/
   }
    BigReal & BigReal::operator= (BigReal& other) {// Assignment operator
        integer_part = other.integer_part;
        fraction_part = other.fraction_part;
        sign = other.sign;
        return *this;//pointer to return

    }




BigReal::BigReal(const BigReal& other){// Copy constructor

    integer_part=other.integer_part;
    fraction_part=other.fraction_part;
    sign=other.sign;
}


int main() {
BigReal obj("-.66666");
//obj()



    return 0;
}
