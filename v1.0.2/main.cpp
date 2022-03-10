#include <iostream>
#include <vector>
#include "./BigInt.h"

using namespace std;

int main(){
    BigInt a("12345"), b("456085"), c=a+b;
    cout<< (a-b).getValue()<<endl;
    cout<<(a+b).getValue()<<endl;
    return 0;
}