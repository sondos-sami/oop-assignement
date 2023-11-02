#include <iostream>
#include<string>

#include<cstdlib>
 using namespace std;
class BigReal {
private:
    char sign='+';
    string integer_part,fraction_part;
    bool isValid(string b){

        if(b.empty()){//if the string is empty then it is not valid as a number
            return false;
        }
        if(b[b.length()-1]=='.'){
            return false;
        }


        string dot="";
        for(int i=0;i<b.length();++i){
            if((b[i]=='+'&&i!=0)||(b[i]=='-'&&i!=0)){
                return false;
            }

            if(b[i]>='a'&&b[i]<='z'){
                return false;
            }
            else  if(!(b[i]>='0'&&b[i]<='9')&& (b[i]!='+')&&(b[i]!='-')&&(b[i]!='.')){

                return false;

            }

            else if(b[i]=='.'){
                if(dot.empty()){
                    dot+=b[i];
                }
                else{
                    return false;//if there is more than one dot
                }

            }


        }return true;
    }

public:
    BigReal (double realNumber = 0.0){//default constructor
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

        cout<<sign<<endl;
        cout<<integer_part<<endl;
        cout<<fraction_part<<endl;

    }
   BigReal (string realNumber){// Initialize from string
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


       cout<<sign<<endl;
       cout<<integer_part<<endl;
       cout<<fraction_part<<endl;

   }


   /* BigReal (const BigReal& other); // Copy constructor
    BigReal& operator= (BigReal& other); // Assignment operator
// Depending on how you store data, default can be enough
    void setNum (string realNumber);
    int size();
    int sign();
    BigReal operator+ (BigReal& other);
    BigReal operator- (BigReal& other);
    bool operator< (BigReal anotherReal);
    bool operator> (BigReal anotherReal);
    bool operator== (BigReal anotherReal);
    friend ostream& operator << (ostream& out, BigReal num);
*/
};
int main() {
BigReal obj("-.66666");



    return 0;
}
