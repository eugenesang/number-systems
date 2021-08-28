#include <string>
#include "include/MyString.h"
#include "adder.h"
//#include "multiplier.h"
#include <vector>
using std::string;
using std::vector;
vector <int> reverseVector(vector <int> a){
    vector <int> ret;
   for(int i=a.size(); i>0; i--){
       ret.push_back(a[i-1]);
   }
   return  ret;
};
vector <vector<int>> vectorize(string a, string b, MyString str){
    vector <vector <int>> v={{0},{0}};
    for(char ca: a)
    {
        v[0].push_back(str.codeOf(ca));

    }
    for (char cb: b)
    {
        v[1].push_back(str.codeOf(cb));
    }
    v[0]=reverseVector(v[0]);
    v[1]=reverseVector(v[1]);
    return v;
}
string addition(string a, string b, MyString parent)
{
    vector <int> va, vb;
    vector <vector <int>> vect=vectorize(a,b,parent);
    va=vect[0];
    vb=vect[1];
    vector <int> ans=add(va, vb, parent.length());

    string ret="";
    for(int i: reverseVector(ans))
    {
        ret+=parent.charAt(i);
    }
    return ret;
}
string multiplication(string a, string b, MyString parent)
{
    vector <int> va, vb, answ;
    vector <vector <int>> vect=vectorize(a,b,parent);
    va=vect[0];
    vb=vect[1];
    vector <int> ans=add(va, vb, parent.length());
    answ=multiply(va, vb, parent.length());
    string retu="";
    for(int i: reverseVector(answ))
    {
        retu+=parent.charAt(i);
    }
    return retu;
}