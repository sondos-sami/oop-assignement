#include "BigReal.h"
#include "bits/stdc++.h"
using namespace std;

bool BigReal::isValidReal(string realNum) {
    if(realNum.empty()){//if the string is empty then it is not valid as a number
        return false;
    }

    if(realNum[realNum.length()-1]=='.'){
        return false;
    }

    string dot;
    for(int i=0;i<realNum.length();++i){
        if((realNum[i]=='+'&&i!=0)||(realNum[i]=='-'&&i!=0)){
            return false;
        }

        if(realNum[i]>='a'&&realNum[i]<='z'){
            return false;
        }
        else  if(!(realNum[i]>='0'&&realNum[i]<='9')&& (realNum[i]!='+')&&(realNum[i]!='-')&&(realNum[i]!='.')){

            return false;

        }

        else if(realNum[i]=='.'){
            if(dot.empty()){
                dot+=realNum[i];
            }
            else{
                return false;//if there is more than one dot
            }
        }
    }
    return true;
}

BigReal::BigReal(double realNumber) {
    string RealNumber  = to_string(realNumber);//convert double to string
    if(isValidReal(RealNumber)) {
        if (RealNumber[0] == '+' || RealNumber[0] == '-') {

            sign = RealNumber[0];
            RealNumber.erase(0, 1);
        }
    }
    if(isValidReal(RealNumber)){//we divide string into two parts (integer_part which is before . and fraction part which is after it)
        integer_part= RealNumber.substr(0,RealNumber.find('.'));
        fraction_part= RealNumber.substr(integer_part.size()+1);
    }
    if(integer_part.empty()){
        integer_part="0";
    }
    if(fraction_part.empty()){
        fraction_part="0";
    }

//     cout<<sign<<endl;
//     cout<<integer_part<<endl;
//     cout<<fraction_part<<endl;
}

BigReal::BigReal (string realNumber){// Initialize from string
    if(isValidReal(realNumber)) {
        if (realNumber[0] == '+' || realNumber[0] == '-') {

            sign = realNumber[0];
            realNumber.erase(0, 1);
        }
    }

    if(isValidReal(realNumber)){

        integer_part= realNumber.substr(0,realNumber.find('.'));
        fraction_part= realNumber.substr(integer_part.size()+1);
    }
    if(integer_part.empty()){
        integer_part="0";
    }
    if(fraction_part.empty()){
        fraction_part="0";
    }


//    cout<<sign<<endl;
//    cout<<integer_part<<endl;
//    cout<<fraction_part<<endl;

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

BigReal BigReal :: operator-(BigReal &other) {

    BigReal result;
   static int intPart1 = stoi(integer_part);
    int fractionPart1 = stoi(fraction_part);
    int intPart2 = stoi(other.integer_part);
    int fractionPart2 = stoi(other.fraction_part);
    int intResult;
    int fractionResult;

    for (int i = integer_part.size(); i >= 0 ; --i) {
       intPart1 = stoi(integer_part[i])
    }

    result.integer_part = to_string(intResult);
    result.fraction_part = to_string(fractionResult);
    return result;


}
bool BigReal::operator == (  BigReal anotherReal) {
    return (sign == anotherReal.sign && fraction_part == anotherReal.fraction_part&&integer_part==anotherReal.integer_part);
}
bool BigReal:: operator > (BigReal  anotherReal){
    if(sign=='+' && anotherReal.sign == '-'){
        return true;
    }
    else if(sign =='-' && anotherReal.sign == '+'){
        return false;
    }
    else if(sign == '-' && anotherReal.sign == '-'){
        if(integer_part.size() > anotherReal.integer_part.size()){
            return false;
        }
        else if( integer_part.size() < anotherReal.integer_part.size()){
            return  true;
        }
        else if(integer_part.size() == anotherReal.integer_part.size()){
            for (int i = 0; i <integer_part.size() ; ++i) {
                if((integer_part[i] - '0') > (anotherReal.integer_part[i] - '0')){
                    return false;
                }
                else if((integer_part[i] - '0') < (anotherReal.integer_part[i] - '0')){
                    return true;
                }
            }
            if(fraction_part.size() > anotherReal.fraction_part.size()){
                for (int i = 0; i <anotherReal.fraction_part.size() ; ++i) {
                    if((fraction_part[i] - '0') > (anotherReal.fraction_part[i] -'0')){
                        return false;
                    }
                    else if((fraction_part[i] - '0') < (anotherReal.fraction_part[i] -'0')){
                        return true;
                    }
                }
            }
            else{
                for (int i = 0; i <fraction_part.size() ; ++i) {
                    if((fraction_part[i] - '0') > (anotherReal.fraction_part[i] -'0')){
                        return false;
                    }
                    else if((fraction_part[i] - '0') < (anotherReal.fraction_part[i] -'0')){
                        return true;
                    }
                }
            }
        }
    }
    else if(sign == '+' && anotherReal.sign == '+'){
        if(integer_part.size() < anotherReal.integer_part.size()){
            return false;
        }
        else if( integer_part.size() > anotherReal.integer_part.size()){
            return true;
        }
        else if(integer_part.size() == anotherReal.integer_part.size()){
            for (int i = 0; i <integer_part.size() ; ++i) {
                if((integer_part[i] - '0') < (anotherReal.integer_part[i] - '0')){
                    return false;
                }
                else if((integer_part[i] - '0') > (anotherReal.integer_part[i] - '0')){
                    return true;
                }
            }
            if(fraction_part.size() > anotherReal.fraction_part.size()){
                for (int i = 0; i <anotherReal.fraction_part.size() ; ++i) {
                    if((fraction_part[i] - '0') < (anotherReal.fraction_part[i] -'0')){
                        return false;
                    }
                    else if((fraction_part[i] - '0') > (anotherReal.fraction_part[i] -'0')){
                        return true;
                    }
                }
            }
            else{
                for (int i = 0; i <fraction_part.size() ; ++i) {
                    if((fraction_part[i] - '0') < (anotherReal.fraction_part[i] -'0')){
                        return false;
                    }
                    else if((fraction_part[i] - '0') > (anotherReal.fraction_part[i] -'0')){
                        return true;
                    }
                }
            }
        }
    }
}
ostream &operator << (ostream &out, const BigReal& num){
    out << num.sign << num.integer_part << '.' << num.fraction_part;
    return out;
}


