#include <vector>
#include <iostream>
using std::cout;
using std::vector;

//#define max=10;
//lets define some helpers that will be used throughout the program

// 1. this function makes sure that no member of the vector exeeds the specified maximum value,

vector <int> fix_vector(vector <int> & vec,int max)
{
    int carry=0;
    for(int &i : vec)
    {
        i+=carry;
        if(i>max)
        {
            carry=i/max;
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

// 2. this function fills a vector with zeros without affecting is value

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
// 3. this function heleps clean a vector by removing unnnecesary 0's
vector <int> clean_vec(vector <int> a){
    vector <int >ret;
    vector <int> zero_carier;
    for(int i : a){
        if(i==0){
            zero_carier.push_back(i);
        }else{
            for(int o : zero_carier){
                ret.push_back(o);
            }
            ret.push_back(i);
            zero_carier={};
        }
    }
    return ret;
}
// 4. this function compares two vectors a and b and returns 1 if a is greater than b,2 if b is greater and 3 if they are equal;
int bigger_vector(vector <int> a, vector <int> b)
{
    a=clean_vec(a);
    b=clean_vec(b);
 if(a.size()>b.size())
 {
     return 1;
 }else if(b.size()>a.size())
 {
 return 2;
 } else
 {
     for(int i=0; i<a.size(); i++)
     {
         if(a[i]>b[i]) return 1;
         if(b[i]>a[i]) return 2;
     }
 }
 return 3;
}

//adition 

vector <int> add(vector <int> a, vector <int> b, int maxlength)
{
    int carry=0;
    vector <int> vf;
    if(a.size()>b.size()){ b=fillVec(b, a.size());}
    if(b.size()>a.size()){ a=fillVec(a, b.size());}
    for(int i=0; i<a.size(); i++)
    {
        int n=a[i]+b[i]+carry;
        vf.push_back(n);
    }
    fix_vector(vf, maxlength);
    return vf;
}

//subtraction

vector <int> subtract(vector <int> x, vector <int> y, int max)
{
    vector <int> a, b;
    int sign=1;
    if(bigger_vector(x, y)==1)
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

//multiplication part

// we need a helper function to make it faster
//this function will multiply a vector with an integer

vector <int> times_vec(vector <int> a, int x)
{
    vector <int> b;
    for(int i : a)
    {
        b.push_back(i*x);
    }
    return b;
}


vector <int> multiply(vector <int> multiple, vector <int> multiplier)
{
    vector < vector <int> > answer;
    
    for(int i=0; i<multiple.size(); i++)
    {
        vector <int> cur=times_vec(multiplier, multiple[i]);
        answer.push_back(cur);
    }
    vector <int> final; int iter=0;
    while (iter < answer.size()+answer[0].size()+2)
    {
        final.push_back(0);
        iter++;
    }
    int i_c=0;
    for(vector <int> i : answer)
    {
         int j_c=0;
        for(int j : i)
        {
            final[i_c+j_c]+=j;
            j_c++;
        }
        i_c++;
    }
    return fix_vector(final, 10);
}

//division --the most complicated to impliment--
//first of all we need to find a list of all multiples of the divisor between zero and the maximum number in the system

vector < vector <int> > generate_mulitiples(vector <int> divisor, int max){
vector < vector <int> > ret;
for(int i=0; i<max; i++)ret.push_back(times_vec(divisor, i));
return ret;
}

/* 
we need to keep track of the following
1. the current value
2. the closest match of the current value in the list of multiples of the divisor
3. index of the best fit in the multiples list, and a vector to store it
4. the number of decimal points
5. the reminder

in every iteration we need to check 
1. if the value of remainder has occured twice --recuring
2. number of decimal places has exceeded the reasonable size
3. if the value of the remainder is zero

*/

// the initial number;
vector <int> first_number(vector <int> a, vector <vector <int>> multiples){
for( int i=0; i<multiples.size(); i++){
    int val=bigger_vector(a, multiples[i]);
 //   cout<<val<<"\n";
    if(val>=2 ){
        return multiples[i];
    }
}
return multiples[multiples.size()-1];
}


vector <int> divide(vector <int> a, vector <int> b){
vector <int> ret;
vector < vector <int> > multiples=generate_mulitiples(b, 10);
for(vector <int> t: multiples){
    for(int i : t){
        cout<<i;
    }
    cout<<"  "<<bigger_vector(a, t)<<"   ";
    for(int i: a){
        cout<<i;
    }
    cout<<"\n";
}
return first_number(a, multiples);
}