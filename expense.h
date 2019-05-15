#ifndef EXPENSE_H
#define EXPENSE_H

#include <iostream>

using namespace std;

class Expense {

int expenseId;
int userId;
string date;
string item;
string amount;

public:
    Expense(int expenseId=0, int userId=0, string date="", string item="", string amount=""){

        this->expenseId = expenseId;
        this->userId = userId;
        this->date = date;
        this->item = item;
        this->amount = amount;
    }

    bool operator <(const Expense& s1) const;
    void setExpenseId(int newExpenseId);
    void setUserId(int newUserId);
    void setDate(string newDate);
    void setItem(string newItem);
    void setAmount(string newAmount);

    int getExpenseId();
    int getUserId();
    string getDate();
    string getItem();
    string getAmount();

};

#endif
