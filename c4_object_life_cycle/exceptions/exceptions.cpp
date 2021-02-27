#include <stdexcept>
#include "iostream"

using namespace std;

//The superclass for all exceptions is std::exception class
//All the subclasses in std::exception can be partitioned
//into three groups: logic errors, runtime errors, and language support
//errors.
struct Memory{
    void forget(int x){
        if(x == 0xFACE)
            throw runtime_error("Error value!!!");
        
        cout << "I don't remember... Maybe " << x << endl;
    }
};

struct BadThing {
    BadThing() {
        cout << "Hello." << endl;
    }
    ~BadThing() {
        throw std::runtime_error{ "NEVER put 'throw' in destructor." };
    }
};

int main(){
    Memory mem;
    try{
        mem.forget(64204);
        mem.forget(64205);
        mem.forget(64206); 
    } catch (const std::logic_error& ex) {
        // Log exception and terminate the program; there is a programming error!
        cout << "It's logic_error." << endl;
    } catch (const std::runtime_error& ex) {
        // Do our best to recover gracefully
        cout << "It's runtime_error." << endl;
    } catch (const std::exception& ex) {
        // This will handle any exception that derives from std:exception
        // that is not a logic_error or a runtime_error.
        cout << "It's general exception." << endl;
    } catch (...) {
         // Panic; an unforeseen exception type was thrown.
        cout << "It's whatever it can be." << endl;
    };

    try {
    //    BadThing bt;  //This will crash a program
        throw std::runtime_error{"The second exception in flight (the first one is in destructor)."};
    } catch(const std::exception& e) {
        cout << "Caught exception: " <<  e.what() << endl;
    }

    return 0;
}