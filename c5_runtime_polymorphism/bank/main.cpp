#include "bank.h"

int main(){
    ConsoleLogger logger;
    Bank bank((Logger *)&logger);
    bank.fill_db();
    bank.make_transfer(1, 3, 5000);
    bank.make_transfer(1, 4, 5000);
    bank.make_transfer(2, 3, 5000);

    bank.print_db();
    return 0;
}