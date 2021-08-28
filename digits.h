#ifndef DIGITS_LOCAL_H
#define DIGITS_LOCAL_H
#include <vector>
#include <string>
#include "./include/MyString.h"
#include "bindings.h"
using std::string;
using std::vector;
MyString numberSystem("0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz");
class Digits
{
public:
    Digits(string str)
    {
        value = str;
    }
    Digits operator*(Digits &str){
        Digits x(multiplication(this->value, str.value, numberSystem));
        return x;
    }
    Digits operator+(Digits &num)
    {
        Digits n(addition(this->value, num.value, numberSystem));
        return n;
    }
    string value;
private:
};
#endif