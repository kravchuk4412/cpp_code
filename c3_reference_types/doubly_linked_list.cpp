#include "doubly_linked_list.h"

using namespace std;

List::List(){};

bool List::is_empty() const{
    return !this->start; 
};

void List::pop(const char *str){
    if(this->is_empty()) return;
    ListElement *ptr {this->start->get_next()};
    if(!strcmp(str, this->start->get_str())) this->pop_forward();
    else if(!strcmp(str, this->end->get_str())) this->pop_back();
    else {
        while(ptr){
            if(!strcmp(str, ptr->get_str())){
                ptr->get_next()->set_prev(ptr->get_prev());
                ptr->get_prev()->set_next(ptr->get_next());
                delete ptr;
                --this->size;
                return; 
            }
            ptr = ptr->get_next();
        }
    }
};

void List::pop_forward(){
    if(this->is_empty()) return;
    ListElement *ptr {this->start->get_next()};
    delete this->start;
    this->start = ptr;
    this->start->set_prev(nullptr);
    --this->size;
};

void List::pop_back(){
    if(this->is_empty()) return;
    ListElement *ptr {this->end->get_prev()};
    delete this->end;
    this->end = ptr;
    this->end->set_next(nullptr);
    --this->size;
};

void List::push_back(const char *str){
    ListElement* elem = new ListElement(str);
    this->size++;
    if(this->is_empty()){
        this->start = this->end = elem;
    } else {
        elem->set_prev(this->end);
        this->end->set_next(elem);
        this->end = elem;
    }
};

void List::push_forward(const char *str){
    ListElement* elem = new ListElement(str);
    this->size++;
    if(this->is_empty()){
        this->start = this->end = elem;
    } else {
        elem->set_next(this->start);
        this->start->set_prev(elem);
        this->start = elem;
    }
};

void List::print() const{
    cout << "size = " << this->size << endl;
    if(is_empty()) return;
    ListElement *ptr {this->start};
    while(ptr->get_next()){
        cout << ptr->get_str() << " -> ";
        ptr = ptr->get_next();
    }
    cout << ptr->get_str() << endl;
};

List::~List(){
    if(this->is_empty()) return;
    ListElement *ptr {};
    while(this->start){
        ptr = this->start;
        this->start = ptr->get_next();
        delete ptr; 
    }
};