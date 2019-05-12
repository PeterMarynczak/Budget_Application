#include <iostream>
#include "Budget.h"

using namespace std;

int _main() {
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

#include "income.h"
#include "incomeFile.h"
#include "BalanceManager.h"

int main(){

BalanceManager balanceManager("incomes.xml", 1);
balanceManager.showIncomes();

//IncomeFile incomeFile("incomes.xml");

//Income income(1,2,"2017-11-01","Zakupy","2134.50");

//incomeFile.appendIncomeToFile(income);

}





















