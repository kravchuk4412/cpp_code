#include "my_string.h"

using namespace std;

int main(){
    MyString str("12345");
    str.concat("678910");
    str.print();

    MyString new_str;
    new_str = str;
    new_str.print();

    MyString  move_str;   
    move_str = move(str);
    move_str.print();
    
    return 0;
}