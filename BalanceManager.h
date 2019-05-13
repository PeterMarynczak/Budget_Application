#ifndef BALANCEMANAGER_H
#define BALANCEMANAGER_H

#include <iostream>
#include <vector>
#include <windows.h>

#include "income.h"
#include "incomeFile.h"
#include "expense.h"
#include "expensesFile.h"
#include "AdjuvantMethods.h"

using namespace std;

class BalanceManager{

    IncomeFile incomeFile;
    ExpensesFile expensesFile;
    vector <Income> incomes;
    vector <Expense> expenses;
    const int ID_OF_LOGGED_USER;

    Income enterNewInfoAboutIncome();
    Expense enterNewInfoAboutExpense();
    void showIncomeData(Income income);

public:
    BalanceManager(string nameOfIncomeFile, string nameOfExpensesFile, int idOfLoggedUser)
    : incomeFile(nameOfIncomeFile), expensesFile(nameOfExpensesFile) ,ID_OF_LOGGED_USER(idOfLoggedUser)  {
        incomes = incomeFile.fetchIncomesOfLoggedUserFromFile(ID_OF_LOGGED_USER);
        expenses = expensesFile.fetchExpensesOfLoggedUserFromFile(ID_OF_LOGGED_USER);
    }

    void addIncome();
    void addExpense();
    void showIncomes();
    void showBilanceFromCurrentMonth();

};

#endif


