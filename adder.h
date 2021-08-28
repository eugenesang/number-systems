#include <cmath>
#include <string>
#include <vector>
using std::string;
using std::vector;
// if you've seen the double slash thing in python this is what this function does
vector <int> filler(vector <int> a, int sz){
    while(a.size()<sz){
        a.push_back(0);
    }
    return a;
}
int modeRem(int a, int b){
    if(a%b!=0){
        a=a-a%b;
    }
    return a/b;
}
vector <int> add(vector <int> a, vector <int> b, int len){
    vector <int> c;
    int carry=0, i=0;
    a.size()<b.size()?a=filler(a, b.size()):b=filler(b, a.size());
    do{
        int val=a[i]+b[i]+carry;
        carry=modeRem(val, len);
        val-=carry*len;
        c.push_back(val);
        i++;
    }while(i<b.size());
    if(carry>0){
        c.push_back(carry);
    }
    return c;
}
vector <int> multiply(vector <int> a, vector<int> b, int len){
 vector <int> ret={0};
 for(int i=0; i<a.size(); i++){
     int countter=a[i];
     countter==0?countter=1:countter=countter;
     for(int j=0; j<countter*pow(len, i); j++){
         ret=add(ret, a, len);
     }
 }
 return ret;
}