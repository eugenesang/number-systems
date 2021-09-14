#ifndef _subraction_h
#define _subraction_h
#include <vector>
#include <string>
using std::vector;
bool bigger_vector(vector <int> a, vector <int> b)
{
 if(a.size()>b.size())
 {
     return true;
 }else if(b.size()>a.size())
 {
 return false;
 } else
 {
     int ma=0, mb=0;
     for(int i=0; i<a.size(); i++)
     {
         if(a[i]>b[i]){ma+=i;}
         if(b[i]>a[i]){mb+=i;}
     }
     if(ma>=mb)
     {
         return true;
     }
 }
 return false;
}
vector <int> fillVec(vector <int> _short, int length)
{
    length-=_short.size();
    vector <int> ret;
    while (length>0)
    {
        ret.push_back(0);
        length--;
    }
    for (int element: ret)
    {
        _short.push_back(element);
    }
    return _short;
}
vector <int> subtract(vector <int> x, vector <int> y, int max)
{
    vector <int> a, b;
    int sign=1;
    if(bigger_vector(x, y))
    {
        a=x; 
        b=y;
    }else{
        a=y;
        b=x;
        sign=-1;
    }
    if(a.size()>b.size())
    {
        b=fillVec(b, a.size());
    }else
    {
        a=fillVec(a, b.size());
    }
    int borrow=0;
    vector <int> ret;
    for (int i=0; i<a.size(); i++)
    {
        int dif;
        if(a[i]<(b[i]+borrow))
        {
            borrow=1;
            dif=max+a[i]-b[i];
        }else
        {
            dif=a[i]-b[i]-borrow;
            borrow=0;
        }
        ret.push_back(dif);
    }
    ret.push_back(sign);
    return ret;
}
#endif