#ifndef BALANCEMANAGER_H
#define BALANCEMANAGER_H

#include <iostream>
#include <vector>
#include <windows.h>

#include "income.h"
#include "incomeFile.h"
#include "AdjuvantMethods.h"

using namespace std;

class BalanceManager{

    IncomeFile incomeFile;
    vector <Income> incomes;
    const int ID_OF_LOGGED_USER;

    Income enterNewInfoAboutIncome();
    void showIncomeData(Income income);

public:
    BalanceManager(string nameOfIncomeFile, int idOfLoggedUser)
    : incomeFile(nameOfIncomeFile), ID_OF_LOGGED_USER(idOfLoggedUser)  {
        incomes = incomeFile.fetchIncomesOfLoggedUserFromFile(ID_OF_LOGGED_USER);
    }

    void addIncome();
    void showIncomes();

};

#endif


