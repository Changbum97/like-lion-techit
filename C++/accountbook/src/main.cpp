#include "../include/AccountBook.h"

int main() {
    AccountBook accountBook;
    accountBook.initialize();

    while(!accountBook.isProgramTerminate()) {
        MENU menu = accountBook.printAndGetMenu();

        switch(menu) {
        case 1: //(MENU::INPUT):
            {INPUT_MENU input_menu = accountBook.printAndGetInputMenu();
            accountBook.runInput(input_menu);}
            break;
        case 2: //(MENU::SPA):
            {accountBook.runSPA();}
            break;
        case 3: //(MENU::TERMINATE):
            {accountBook.setProgramTerminate();}
            break;
        default:
            break;
        }
    }

    return 0;
}