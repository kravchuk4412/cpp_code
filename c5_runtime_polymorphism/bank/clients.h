#pragma once
#include <iostream>

using namespace std;

enum class ClientType{
    SILVER,
    GOLDEN,
    PLATINUM
};

class Client{
protected:
    size_t id;
    int account;
    string name;
public:
    Client(string name, size_t id) : name{name}, id{id}, account{} {};

    size_t get_id(){
        return id;
    };

    string get_name(){
        return name;
    };

    void set_name(string name){
        this->name = name;
    };

    virtual void print() = 0;
    virtual ~Client() = default;
};

class SilverClient : Client{
public:
    SilverClient(string name, size_t id) : Client(name, id) {};

    void print() override {
        cout << "Hello, my name is " << name << ". I'm SilverClient in runtime!" << endl;
    };
};

class GoldenClient : Client{
public:
    GoldenClient(string name, size_t id) : Client(name, id) {};
    
    void print() override {
        cout << "Hello, my name is " << name << ". GoldenClient in runtime!" << endl;
    };
};

class PlatinumClient : Client{
public:
    PlatinumClient(string name, size_t id) : Client(name, id) {};
    
    void print() override {
        cout << "Hello, my name is " << name << ". PlatinumClient in runtime!" << endl;
    };
};