#ifndef BIGINT_H
#define BIGINT_H

#include <vector>
#include <string>
#include "./operations.h"


using std::string;
using std::vector;

string vecToString(vector <int> v){
    string numbers="0123456789",
    ret="";
    for(int i:v){
        ret+=numbers[i%10];
    }
    return ret;
}

class BigInt{
    private:
    vector <int> digits;
    bool positive;

    string uAdd(BigInt b){
        return (vecToString(add(this->digits, b.digits)));
    }
    string uSubtract (BigInt b){
        string symbol="";
        if(abeBiggerVec(this->digits, b.digits) == 'b'){
            symbol="-";
        }
        return (symbol+vecToString(subtract(this->digits, b.digits)));
    }
    

    BigInt calculate(BigInt b){
        //  -a + -b
        if(!this->positive && !b.positive){
            return BigInt("-"+ uAdd(b));
        }
        // b - a
        if(!this->positive && b.positive){
            vector <int> c=this->digits;
            this->digits=b.digits;
            b.digits=c;
            return BigInt(uSubtract(b));
        }
        if(this->positive && !b.positive){
            return BigInt(uSubtract(b));
        }
        if(this->positive && b.positive){
            return BigInt(uAdd(b));
        }
        return BigInt(uAdd(b));
    }

    public:
    BigInt(string init){
        if(init [0] =='-') {positive=false;}else positive=true;
        for(char c: init){
            if((int)c > 57 || int(c)<48){
                continue;
            }
            digits.push_back((int)c-48);
        }
    }
    void makePositive(bool p){
        positive=p;
    }
    string getValue(){
        string ans="";
        if(positive==false) ans+="-";

        ans+=vecToString(digits);
        

        return ans;
    }

    
    BigInt operator + (BigInt b){
        return calculate(b);
    }
    BigInt operator - (BigInt b){
        b.makePositive(!b.positive);
        return calculate(b);
    }
    
};


#endif