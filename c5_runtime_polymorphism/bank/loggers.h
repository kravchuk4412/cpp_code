#pragma once
#include <iostream>

using namespace std;

class Logger{
public:
    virtual ~Logger() = default;
    virtual void log_transfer(string from, string to, int amount) = 0;
};

class ConsoleLogger : Logger {
    void log_transfer(string from, string to, int amount) override {
        cout << "[console] " << from << " -> " << to << " : " << amount << endl;
    }
};

class FileLogger : Logger {
    void log_transfer(string from, string to, int amount) override {
        cout << "[file] " << from << " -> " << to << " : " << amount << endl;
    }
};
