#include "expense.h"

bool Expense::operator <(const Expense& s1) const {
    return this->date < s1.date;
}

void Expense::setExpenseId(int newExpenseId){
expenseId = newExpenseId;
}

void Expense::setUserId(int newUserId){
userId = newUserId;
}

void Expense::setDate(string newDate){
date = newDate;
}

void Expense::setItem(string newItem){
item = newItem;
}

void Expense::setAmount(string newAmount){
amount = newAmount;
}

int Expense::getExpenseId(){
return expenseId;
}

int Expense::getUserId(){
return userId;
}

string Expense::getDate(){
return date;
}

string Expense::getItem(){
return item;
}

string Expense::getAmount(){
return amount;
}
