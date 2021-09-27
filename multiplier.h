#ifndef MULTIPLIER_H
#define MULTIPLIER_H
#include <iostream>
#include <vector>
using std::vector;
using std::cout;
using std::endl;
vector <int> times_vec(vector <int> &a, int x)
{
    for(int &i : a)
    {
        i=i*x;
    }
    return a;
}
int floor_div(int num, int den)
{
    num -= num%den;
    return num/den;
}
vector <int> fix_vector(vector <int> & vec, int max)
{
    int carry=0;
    for(int &i : vec)
    {
        i+=carry;
        if(i>max)
        {
            carry=floor_div(i, max);
            i%=max;
        }else
        {
            carry=0;
        }
    }
    if(carry>0)
    {
        vec.push_back(carry);
        fix_vector(vec, max);
    }
    return vec;
}
vector <int> multiply(vector <int> multiple, vector <int> multiplier)
{
    vector < vector <int> > answer;
    vector <int> final;
    for(int i=0; i<multiple.size(); i++)
    {
        answer.push_back(times_vec(multiplier, i));
    }
    for(int i=0; i<answer.size(); i++)
    {
        for(int j=0; j<answer[i].size(); j++)
        {
            if(final[j+i]){
                final[j+i]+=answer[i][j];
            }else{
                final[j+i]=answer[i][j];
            }
        }
    }
    
    return fix_vector(final, 10);
}
#endif
