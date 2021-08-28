#include <iostream>
#include <string>
#include <vector>
#include "digits.h"
//#include "multiplier.h"
using std::cin;
using std::cout;
using std::string;
using std::vector;

int main()
{
    Digits a("z");
    Digits b("z00z");
    Digits c=a+b;
    Digits d=a*b;
    cout<<c.value<<"\n"<<d.value<<std::endl;
    
}
