#ifndef MYSTRING_H
#define MYSTRING_H
#include <string>
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

    protected:

    private:
    string content;
};

#endif // MYSTRING_H
