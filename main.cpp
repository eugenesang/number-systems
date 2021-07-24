#include <iostream>
#include <string>
#include <vector>
#include "./include/MyString.h"
#include "encrypt.h"
using std::cin;
using std::cout;
using std::string;
using std::vector;
int main()
{
    long num;
    string str;
    MyString Characters("0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz");
    num = reverse("07s7", Characters);
    str = mapNum(num, Characters);
    cout << num << "\n"
         << str << std::endl;
    return 0;
}
