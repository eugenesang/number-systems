#ifndef VLIST_H
#define VLIST_H

#include <vector>
using std::vector;

vector <int> addFirst(vector <int> v, int n){
    vector <int> ret={n};
    for (int i:v) ret.push_back(i);
    return ret;
}

vector <int> fixVec(vector <int> &v){
    int carry=0;
    for(int &i:v){
        i+=carry;
        if(i>9){
            carry=i/10;
            i%=10;
        }else{
            carry=0;
        }
    }
    if(carry){
        v.push_back(carry);
        return fixVec(v);
    }
    return v;
}

vector <int> fillVec(vector <int> &v, int n){ while(n>0){ v=addFirst(v, 0); n--;} return v; }

vector <int> reverseVec (vector <int> v){
    vector <int> ret;
    for(int i=v.size()-1; i>=0; i--){
        ret.push_back(v[i]);
    }
    return ret;
}

vector <int> add(vector <int> a , vector <int> b){
    if(a.size()>b.size()){ fillVec(b, a.size()-b.size()); }
    else { fillVec(a, b.size()-a.size()); }
    for(int i=b.size()-1; i>=0; i--){
        b[i]+=a[i];
    }
    b=reverseVec(b);

    b=fixVec(b);

    return reverseVec(b);
}


//  a-b = 0-(b-a)

char abeBiggerVec(vector <int> a, vector <int> b){
    if(a.size()>b.size()) return 'a';
    if(b.size() > a.size()) return 'b';
    for( int i=a.size(); i>0; i--){
        if(a[i] > b[i]) return 'a';
        if(b[i] > a[i]) return 'b';
    }
    return 'e';
}

vector <int> unsafeMinus(vector <int> &a, vector <int> b){
    int borrow=0;
    b=fillVec(b, a.size()-b.size());
    vector <int> ret;
    for(int i=a.size()-1; i>=0; i--){
        int x=a[i]-(borrow+b[i]);
        if(x<0){
            x+=10;
            borrow=1;
        }else{
            borrow=0;
        }
        ret.push_back(x);
    }
    return reverseVec(ret);
}

vector <int> subtract(vector <int> a, vector <int> b){
    vector <int> r={0};
    switch (abeBiggerVec(a, b))
    {
    case 'a':
        r=unsafeMinus(a, b);
        break;
    case 'b':
        r= unsafeMinus(b, a);
        break;
    default:
        break;
    }
    
    return r;
}
#endif