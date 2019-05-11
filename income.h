#ifndef INCOME_H
#define INCOME_H

#include <iostream>

using namespace std;

class Income {

int incomeId;
int userId;
string date;
string item;
string amount;

public:
    Income(int incomeId=0, int userId=0, string date="", string item="", string amount=""){

        this->incomeId = incomeId;
        this->userId = userId;
        this->date = date;
        this->item = item;
        this->amount = amount;
    }

    void setIncomeId(int newIncomeId);
    void setUserId(int newUserId);
    void setDate(string newDate);
    void setItem(string newItem);
    void setAmount(string newAmount);

    int getIncomeId();
    int getUserId();
    string getDate();
    string getItem();
    string getAmount();

};

#endif
