#ifndef BUDGET_H
#define BUDGET_H

#include "UserManager.h"
#include "AdjuvantMethods.h"
#include "BalanceManager.h"

#include <iostream>

using namespace std;

class Budget{

UserManager userManager;
BalanceManager *balanceManager;

const string INCOME_FILE_NAME;
const string EXPENSES_FILE_NAME;

public:
    Budget(string userFileName, string expensesFileName ,string incomeFileName)
    : userManager(userFileName), EXPENSES_FILE_NAME(expensesFileName) ,INCOME_FILE_NAME(incomeFileName) {

        balanceManager = NULL;
    };
    ~Budget(){
        delete balanceManager;
        balanceManager = NULL;
    }
    void registerUser();
    void userLogIn();
    void userLogOut();
    char chooseOptionFromMainMenu();
    char chooseOptionFromUserMenu();
    bool ifUserIsLogged();
    void changeUserPassword();
    void addIncome();
    void addExpense();
    void showBilanceFromCurrentMonth();

};

#endif
