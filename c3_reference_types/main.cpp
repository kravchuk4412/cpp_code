#include "doubly_linked_list.h"

int main(){
    List list{};
    list.push_back("Pasha");
    list.push_back("Ortem");
    list.push_back("Alex");
    list.print();
    //list.pop_back();  
    //list.print();
    //list.pop_forward();  
    //list.print();
    list.pop("Ortem");
    list.print();
    return 0;
}