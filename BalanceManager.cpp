#include "BalanceManager.h"

void BalanceManager::addIncome() {

    Income income;

    system("cls");
    cout << " >>> DODAWANIE NOWEGO PRZYCHODU <<<" << endl << endl;
    income = enterNewInfoAboutIncome();

    incomes.push_back(income);
    /*if (incomeFile.appendIncomeToFile(income))
        cout << "Nowy przychod zostal dodany" << endl;
    else
        cout << "Blad. Nie udalo sie dodac nowego przychodu do pliku." << endl;
    system("pause");*/
}

Income BalanceManager::enterNewInfoAboutIncome() {

    Income income;
    string date, item, amount;

}

void BalanceManager::showIncomes() {
    system("cls");
    if (!incomes.empty()) {
        cout << "             >>> PRZYCHODY <<<" << endl;
        cout << "-----------------------------------------------" << endl;
        for (vector <Income> :: iterator itr = incomes.begin(); itr != incomes.end(); itr++) {
            showIncomeData(*itr);
        }
        cout << endl;
    } else {
        cout << endl << "Nie dodano jeszcze zadnych przychodow" << endl << endl;
    }
    system("pause");
}

void BalanceManager::showIncomeData(Income income) {
    cout << endl << "Id:         " << income.getIncomeId() << endl;
    cout << "Data:               " << income.getDate() << endl;
    cout << "Item:               " << income.getItem() << endl;
    cout << "kwota przychodu:    " << income.getAmount() << endl;
}
