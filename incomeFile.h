#ifndef INCOMEFILE_H
#define INCOMEFILE_H

#include <iostream>
#include <vector>
#include <cstdlib>

#include "Markup.h"
#include "income.h"
#include "File.h"

using namespace std;

class IncomeFile :public File{

    const string NAME_OF_INCOME_FILE;
    int idOfLastAddedIncome;
    CMarkup xml;

public:
    IncomeFile(string nameOfIncomeFile) : NAME_OF_INCOME_FILE(nameOfIncomeFile) {
       idOfLastAddedIncome = 0;
    }

    bool ifFileIsEmpty(){
        File::ifFileIsEmpty(xml);
    }

    vector <Income> fetchIncomesOfLoggedUserFromFile(int idOfLoggedUser);
    bool appendIncomeToFile(Income income);
    int getIdOfLastIncome();

    //void saveUsersToFile(int &idOfLoggedUser, string newPassword);
};

#endif
