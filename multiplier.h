#include <vector>
using std::vector;
using std::endl;
vector <int> times_vec(vector <int> a, int x)
{
    vector <int> b;
    for(int i : a)
    {
        b.push_back(i*x);
    }
    return b;
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
