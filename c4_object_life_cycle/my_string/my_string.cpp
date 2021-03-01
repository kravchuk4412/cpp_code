#include "my_string.h"
#include <stdexcept>
#include <stdio.h>
#include <string.h>

using namespace std;

MyString::MyString() : size{} {
    str = new char[1] {'\0'};
};

void MyString::throw_error(ErrorMessage error_type){
    switch (error_type)
    {
    case ErrorMessage::LENGTH_ERROR:{
        char error_txt[256];
        snprintf(error_txt, sizeof(error_txt),
         "Too long string was passed. Maximum allowed string size is %i.", MAX_STR_SIZE);
        throw length_error(error_txt);
        break;
    }  
    default:
        break;
    }
};

MyString::MyString(const char* str){
    auto new_size = strlen(str);
    if(new_size > MAX_STR_SIZE){
        throw_error(ErrorMessage::LENGTH_ERROR); 
    } else {
        this->str = new char[new_size + 1];
        strncpy(this->str, str, new_size + 1);
        this->size = new_size;
    } 
};

MyString::MyString(const MyString& other) 
    : str{new char[other.size + 1]}, size{other.size} {
    strncpy(str, other.str, other.size + 1);         
};

MyString& MyString::operator=(const MyString& other){
    if (this == &other) return *this;
    delete[] str;
    str = new char[other.size + 1];
    size = other.size;
    strncpy(str, other.str, other.size + 1);
    return *this;
};

MyString::MyString(MyString&& other) noexcept
    : str{other.str}, size {other.size} {
    other.str = nullptr;
    other.size = 0;
};

MyString& MyString::operator=(MyString&& other) noexcept{
    if (this == &other) return *this;
    delete[] str;
    str = other.str;
    size = other.size;
    other.str = nullptr;
    other.size = 0;
    return *this;
};  

char* MyString::get_str(){
    return str;
};

size_t MyString::get_size(){
    return size;
};

char* MyString::concat(const char* str){
    auto new_size = this->size + strlen(str); 
    if(new_size > MAX_STR_SIZE){
        throw_error(ErrorMessage::LENGTH_ERROR); 
    } else {
        char* new_str = new char[new_size + 1];
        strncat(strncpy(new_str, this->str, size + 1), str, strlen(str) + 1);
        delete[] this->str;
        this->str = new_str;
        this->size = new_size;
        return this->str; 
    }
};

MyString::~MyString(){
    delete[] str;
};

void MyString::print(){
    cout << "String: " << this->str << endl;
    cout << "Size: " << this->size << endl; 
};