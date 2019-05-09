#include <iostream>
#include "Budget.h"

using namespace std;

int main() {
    Budget budget("users.xml");

    char choice;
    while(true) {
        if (!budget.ifUserIsLogged()) {
            choice = budget.chooseOptionFromMainMenu();

            switch (choice) {
            case '1':
                budget.registerUser();
                break;
            case '2':
                budget.userLogIn();
                break;
            case '9':
                exit(0);
                break;
            default:
                cout << endl << "Nie ma takiej opcji w menu." << endl << endl;
                system("pause");
                break;
            }
        } else {
            choice = budget.chooseOptionFromUserMenu();
            switch (choice){
         case '1':
            break;
         case '2':
            break;
         case '3':
            break;
         case '4':
            break;
         case '5':
            break;
         case '6':
            budget.changeUserPassword();
            break;
         case '9':
            budget.userLogOut();
            break;
            }
        }
    }

    return 0;
}
