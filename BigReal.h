#ifndef BIGREAL_BIGREAL_H
#define BIGREAL_BIGREAL_H

#include "bits/stdc++.h"
using namespace std;

class BigReal {
private:
    char sign = ' ';
    string integer_part;
    string fraction_part;
    string realNumber;

     bool isValidReal(string realNumber);

public:
    BigReal(double realNumber = 0.0);
    BigReal(string realNumber);
    BigReal(const BigReal &other);
    BigReal& operator=(BigReal& other);
    BigReal operator+ (BigReal& other);
    BigReal operator- (BigReal& other);
    bool operator< (BigReal anotherReal);
    bool operator> (BigReal anotherReal);
    bool operator== (BigReal anotherReal);
    friend ostream& operator <<     (ostream& out, const BigReal& num);

};

#endif //BIGREAL_BIGREAL_H
