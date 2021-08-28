#include "include/MyString.h"
#include <cmath>
#include <string>
#include <vector>
using std::string;
using std::vector;
// if you've seen the double slash thing in python this is what this function does
long remainder(long x, int y)
{
    if (x % y != 0)
    {
        x = x - x % y;
    }
    x = x / y;
    return x;
};
//this function converts a base ten number to a specified base and returns an array of the values of the conerted number
vector<int> mapp(long a, int b)
{
    vector<int> ret;
    if (a == 0)
    {
        ret.push_back(0);
    }
    else
    {
        while (a > 0)
        {
            ret.push_back(a % b);
            a = remainder(a, b);
        }
    };
    vector<int> ans;
    for (int j = ret.size(); j > 0; j--)
    {
        ans.push_back(ret[j - 1]);
    }
    return ans;
};
//after coverting to a new number system you might also need to convert back to decimal be it for calculation or just to proof that your programm is running smooth
long reverse(string C, MyString &obj)
{
    int size = obj.length();
    long answer = 0;
    int n = 0;
    for (int i = C.length(); i > 0; i--)
    {
        answer += obj.codeOf(C.at(i - 1)) * pow(size, n);
        n++;
    }
    return answer;
};
//now this converts a base ten number to a pecified base which has all symbls whilethis time returning a string instead of a vector or array.
string mapNum(long num, MyString &objt)
{
    vector<int> cods = mapp(num, objt.length());
    string answer = "";
    for (int n = cods.size(); n > 0; n--)
    {
        answer += objt.charAt(cods[n - 1]);
    };
    return answer;
}
