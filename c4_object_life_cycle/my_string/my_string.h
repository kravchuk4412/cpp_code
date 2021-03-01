#pragma once
#include <iostream>
#define MAX_STR_SIZE 20

using namespace std;

enum class ErrorMessage{
    LENGTH_ERROR
};

class MyString{ 
    char* str;
    size_t size;

    void throw_error(ErrorMessage error_type);
public:
    MyString();
    MyString(const char* str);
    MyString(const MyString& other);
    MyString& operator=(const MyString& other);
    MyString(MyString&& other) noexcept;
    MyString& operator=(MyString&& other) noexcept; //move assigment
    //MyString(const MyString& other) = delete; //to forbid a copy constructor
    //MyString& operator=(const MyString& other) = default; //to declare a default copy assigment operator

    char* get_str();
    size_t get_size();
    char* concat(const char* str);

    void print();
    ~MyString();
};