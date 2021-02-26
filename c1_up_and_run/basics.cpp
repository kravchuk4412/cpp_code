#include <iostream>

using namespace std;

int abs_val(int x){
    if(x < 0)
        return -x;
    
    return x;
}

int main(){
    int x = -3;
    printf("The absolute value of %d is %d.\n", x, abs_val(x));
}