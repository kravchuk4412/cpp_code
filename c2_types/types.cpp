#include <iostream>
#include <cstdint> //for different types of ints

using namespace std;

enum class BRG {
    Blue,
    Red,
    Green
};

void print_ints(){
    short si {};
    int i{};
    long li{};
    long long lli{};
    int64_t i64{}; // signed long, 8 bytes

    cout << "Short int size = " << sizeof(si) << " bytes." << endl; 
    cout << "Int size = " << sizeof(i) << " bytes." << endl; 
    cout << "Long int size = " << sizeof(li) << " bytes." << endl; 
    cout << "Long long int size = " << sizeof(lli) << " bytes." << endl; 
    cout << "Int64_t size = " << sizeof(int64_t) << " bytes." << endl;
}

void print_arr(int arr[], int a_size){
    for(auto i = 0; i < a_size; ++i){
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main(){
    int arr[] {1, 2, 3};
    print_ints();
    print_arr(arr, sizeof(arr)/sizeof(int));
    return 0;
}