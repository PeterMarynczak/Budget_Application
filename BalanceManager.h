#ifndef BALANCEMANAGER_H
#define BALANCEMANAGER_H

#include <iostream>
#include <vector>
#include <windows.h>
#include <algorithm>

#include "income.h"
#include "incomeFile.h"
#include "expense.h"
#include "expensesFile.h"
#include "AdjuvantMethods.h"

using namespace std;

class BalanceManager{

    IncomeFile incomeFile;
    ExpensesFile expensesFile;
    const int ID_OF_LOGGED_USER;
    vector <Income> incomes;
    vector <Expense> expenses;

    Income enterNewInfoAboutIncome();
    Expense enterNewInfoAboutExpense();
    void showIncomeData();

public:
    BalanceManager(string nameOfIncomeFile, string nameOfExpensesFile, int idOfLoggedUser)
    : incomeFile(nameOfIncomeFile), expensesFile(nameOfExpensesFile) ,ID_OF_LOGGED_USER(idOfLoggedUser)  {
        incomes = incomeFile.fetchIncomesOfLoggedUserFromFile(ID_OF_LOGGED_USER);
        expenses = expensesFile.fetchExpensesOfLoggedUserFromFile(ID_OF_LOGGED_USER);
    }


    void addIncome();
    void addExpense();
    void showIncomes();
    void showExpensesData();
    void showBilanceFromCurrentMonth();

};

#endif


