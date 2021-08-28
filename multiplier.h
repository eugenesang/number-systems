#ifndef MULTIPLIER_H
#define MULTIPLIER_H
#include <vector>
#include <cmath>
#include "adder.h"
using std::vector;
vector <int> multiply(vector <int> a, vector<int> b, int len){
 vector <int> ret={0};
 for(int i=0; i<a.size(); i++){
     
     for(int j=0; j<a[i]*pow(len, i); j++){
         ret=add(ret, a, len);
     }
 }
 return ret;
}
#endif