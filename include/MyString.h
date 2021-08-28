#ifndef MYSTRING_H
#define MYSTRING_H
#include <string>
#include <vector>
using std::vector;
using std::string;
class MyString
{
    public:
        MyString(string characters){
        content=characters;

        };
        int length(){
        return content.size();
        };
int codeOf(char N){
if(content.find(N)){
    return content.find(N);
} else{
    return 0;
}
};
char charAt(int N){
return content.at(N);
};
// MyString operator+(MyString &obj){
//     for(char ch: obj.content){

//     }
// }
string content;
    protected:

    private:
    
};

#endif // MYSTRING_H
