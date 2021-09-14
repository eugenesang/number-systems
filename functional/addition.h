#ifndef _addition_h
#define _addition_h
#include <vector>
using std::vector;
vector<int> fill_vector_a(vector <int> &a, int b)
{
    while(a.size()<b)
    {
        a.push_back(0);
    }
    return a;
};
void fix_vector_a(vector <int> &a, int max_a)
{
    int carry=0;
    for(int &i: a)
    {
        i+=carry;
        if(i>=max_a)
        {
            carry=i-i%max_a;
            carry/=max_a;
            i=i%max_a;
        }else{
            carry=0;
        }
    }
    if(carry>0)
    {
        a.push_back(carry);
    }
}
vector <int> add_vectors(vector <int> a, vector <int> b, int maxlength)
{
    int carry=0;
    vector <int> vf;
    if(a.size()>b.size()){ b=fill_vector_a(b, a.size());}
    if(b.size()>a.size()){ a=fill_vector_a(a, b.size());}
    for(int i=0; i<a.size(); i++)
    {
        int n=a[i]+b[i]+carry;
        vf.push_back(n);
    }
    fix_vector_a(vf, maxlength);
    return vf;
}
#endif