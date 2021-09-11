#ifndef ARITHMETHICS_H
#define ARITHMETHICS_H
#include <string>
#include <iostream>
#include <vector>
using std::vector;
using std::string;
string characters="0123456789";//ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz
//add more characters you may need
int max_num=characters.size();
long floorDiv(long x, int y)
{
    if (x % y != 0)
    {
        x = x - x % y;
    }
    x = x / y;
    return x;
};
void reverseVector(vector <int> &v)
{
    vector <int> c;
    for (int i=v.size(); i>0; i--)
    {
        c.push_back(v[i-1]);
    }
    v=c;
}
vector <int> fixVector(vector <int> &vec, int max)
{
    int carry=0;
    vector <int> ret;
    for(int i : vec)
    {
        int all=i+carry;
        if(all>max)
        {
            carry=floorDiv(all, max);
            all=all%max;
        }else{
            carry=0;
        }
        ret.push_back(all);
    }
    while(carry>0)
    {
        ret.push_back(carry%max);
        carry=floorDiv(carry, max);   
    }
    return ret;
}
void fillVector(vector <int> &vec, int s, int n=1)
{   

    s-=vec.size();
    vector <int> r;
    while(r.size()<s){
        r.push_back(0);
    };
    if(n=1)
    {
        for(int i: vec)
        {
            r.push_back(i);
        }
    } else {
        for(int i: r)
        {
            vec.push_back(i);
        }
        r=vec;
    }
    
    vec=r;
}

int codeOf(char c)
{
    int r=-1;
    for(int i=0; i<characters.size(); i++)
    {
        if(characters[i]==c)
        {
            r=i;
        }
    }
    return r;
}
char charAt(int code)
{
    if(code < 0 || code > 62)
    {
        return '~';
    }
    return characters[code];
}
vector <int> vectorize(string str)
{
    vector <int> r;
    for (char c: str)
    {
        r.push_back(codeOf(c));
    }
    return r;
}
string stringify(vector <int> num)
{
    string r;
    for (int i : num)
    {
        r+=charAt(i);
    }
    return r;
}
vector <int> addVectors(vector <int> va, vector <int> vb)
{
    int maxlength=characters.size();
    int carry=0;
    vector <int> vf;
    if(va.size()>vb.size())
    {
        fillVector(vb, va.size());
    } else{
        fillVector(va, vb.size());
    } 
    reverseVector(va);
    reverseVector(vb);
    for(int i=0; i<va.size(); i++)
    {
        int n=va[i]+vb[i]+carry;
        if(n>=maxlength)
        {
            carry=floorDiv(n, maxlength);  
            n=n%maxlength; 
        }else{
            carry=0;
        }
        vf.push_back(n);
    }
    reverseVector(vf);
    return vf;
}
string addAlphNumerics(string &a, string &b)
{   
   
    vector <int> va=vectorize(a), vb=vectorize(b);
    vector <int> vf=addVectors(va, vb);
    string str=""; 
    for(int i : vf)
    {
        str+=charAt(i);
    }  
    return str;
}
vector <int> vectorAdder2(vector <int> a, vector <int> b)
{
    vector <int> ans, add;
    if(a.size()>b.size())
    {
        ans=a;
        add=b;
    }else{
        ans=b;
        add=a;
    }
    a={};
    for(int i=0; i<ans.size(); i++)
    {
        if(i < add.size())
        {
            a.push_back(ans[i]+add[i]);
        }else{
            a.push_back(ans[i]);
        }

    }
    return  fixVector(a, max_num);
}
vector <int> vecTimesInt(vector <int> v, int n)
{
    for(int &i : v)
    {
        i*=n;
    }
    return v;
}
vector <int> vectorMultiplier(vector <int> a,  vector <int> b )
{
    reverseVector(a);
    reverseVector(b);
    vector <int> ans, cur;
    int exponential=b.size();
    for(int i: a)
    {
        cur=vecTimesInt(b, i);
        fillVector(cur, exponential);
        exponential++;
        cur=fixVector(cur, max_num);
        ans=addVectors(ans, cur);
        std::cout<<std::endl;
        ans=fixVector(ans, max_num);
        std::cout<<std::endl;
    }
    reverseVector(ans);
    return ans;
}
#endif
