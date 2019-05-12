#ifndef EXPENSESFILE_H
#define EXPENSESFILE_H

#include <iostream>
#include <vector>
#include <cstdlib>

#include "Markup.h"
#include "expense.h"
#include "File.h"

using namespace std;

class ExpensesFile :public File{

    const string NAME_OF_EXPENSES_FILE;
    int idOfLastAddedExpense;
    CMarkup xml;

public:
    ExpensesFile(string nameOfExpensesFile) : NAME_OF_EXPENSES_FILE(nameOfExpensesFile) {
       idOfLastAddedExpense = 0;
    }

    bool ifFileIsEmpty(){
        File::ifFileIsEmpty(xml);
    }

    vector <Expense> fetchExpensesOfLoggedUserFromFile(int idOfLoggedUser);
    bool appendExpenseToFile(Expense expense);
    int getIdOfLastExpense();

    //void saveUsersToFile(int &idOfLoggedUser, string newPassword);
};

#endif
