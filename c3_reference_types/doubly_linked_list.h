#include <string.h>
#include "iostream"

using namespace std;

class List{
    class ListElement{
        char str[256]{};
        ListElement *prev{};
        ListElement *next{};

    public:
        ListElement() {};

        ListElement(const char *str, ListElement *prev, ListElement *next) : prev(prev), next(next) {
            set_str(str);
        };

        ListElement(const char *str) : ListElement(str, nullptr, nullptr) {};

        char* get_str(){
            return str;
        };

        void set_str(const char* str){
            strcpy(this->str, str);
        }

        ListElement* get_prev(){
            return prev;
        };

        void set_prev(ListElement* prev){
            this->prev = prev;
        }

        ListElement* get_next(){
            return next;
        };

        void set_next(ListElement* next){
            this->next = next;
        };

        void print(){
            cout << "str = " << this->str << endl;
            cout << "prev = " << (this->prev ? this->prev->get_str() : "") << endl;
            cout << "next = " << (this->next ? this->next->get_str() : "") << endl;
        };
    };
    ListElement* start{};
    ListElement* end{};
    size_t size{};
public:
    List();

    bool is_empty() const;
    void push_forward(const char* str);
    void push_back(const char* str);
    void pop(const char* str);
    void pop_forward();
    void pop_back();  
    void print() const;

    ~List();
};