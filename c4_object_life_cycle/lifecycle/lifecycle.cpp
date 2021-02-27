#include "iostream"

using namespace std;

class Salary{
    const static int bonuses = 500;  //const static for initialization within class
    static int taxes;

    static int count(int salary){
        return salary + bonuses - taxes;
    }
};

int Salary::taxes = 75; //static member has to be initialized out of class 

//'hero_health' - static storage duration (global scope/namespace).
static int hero_health = 200;

//'damage' and 'reduced_damage' - automatic storage duration (local variables).
//'total_damage' - static local variable.
void fight(int damage){
    static int total_damage{};
    int reduced_damage = damage*0.5;
    total_damage+=reduced_damage;
    hero_health-=reduced_damage;
    total_damage+=damage;
    if(hero_health <= 0){
        cout << "YOU DIED" << endl;
        cout << "Starting a new game..." << endl;
        hero_health = 200;
    }
}

int main(){
    //Dynamic array
    int* dyn_arr = new int[3]{1, 2, 3};
    delete[] dyn_arr;
    return 0;
}
