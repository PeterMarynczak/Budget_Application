#include "BalanceManager.h"

void BalanceManager::addIncome() {

    Income income;

    system("cls");
    cout << " >>> DODAWANIE NOWEGO PRZYCHODU <<<" << endl << endl;
    income = enterNewInfoAboutIncome();

    incomes.push_back(income);
    if (incomeFile.appendIncomeToFile(income))
        cout << endl << "Nowy przychod zostal dodany" << endl << endl;
    else
        cout << "Blad. Nie udalo sie dodac nowego przychodu do pliku." << endl;
    system("pause");
}

void BalanceManager::addExpense() {

    Expense expense;

    system("cls");
    cout << " >>> DODAWANIE NOWEGO WYDATKU <<<" << endl << endl;
    expense = enterNewInfoAboutExpense();

    expenses.push_back(expense);
    if (expensesFile.appendExpenseToFile(expense))
        cout << endl << "Nowy wydatek zostal dodany" << endl << endl;
    else
        cout << "Blad. Nie udalo sie dodac nowego wydatku do pliku." << endl;
    system("pause");
}

Income BalanceManager::enterNewInfoAboutIncome() {

    Income income;
    char choice;
    string date, item, amount;
    income.setUserId(ID_OF_LOGGED_USER);
    income.setIncomeId(incomeFile.getIdOfLastIncome()+1);

    cout << "czy przychod dotyczy dnia dzisiejszego, tak lube nie (t/n)? ";

    do {
        choice = AdjuvantMethods::loadMark();
        switch (choice) {
        case 't':
            date = AdjuvantMethods::getCurrentDate();
            income.setDate(date);
            break;
        case 'n':
            cout << "podaj date w formacie rrrr-mm-dd np. 2017-11-01: ";
            date = AdjuvantMethods::readLine();
            if (AdjuvantMethods::checkIfDateIsCorrect(date) == true) {
                income.setDate(date);
                break;
            } else {
                cout << endl << "wprowadzona data jest niepoprawna " << endl;
                choice = ' ';
            }
        default:
            cout << "sprobuj ponownie wybierajac (t/n) ";
        }
    } while(choice != 't' && choice != 'n');

    cout << endl << "Napisz czego dotyczyl przychod: ";
    item = AdjuvantMethods::readLine();
    income.setItem(item);

    cout << endl << "Podaj wysokosc przychodu: ";
    amount = AdjuvantMethods::readLine();
    amount = AdjuvantMethods::changeCommaToDot(amount);
    income.setAmount(amount);

    return income;
}

Expense BalanceManager::enterNewInfoAboutExpense() {

    Expense expense;
    char choice;
    string date, item, amount;
    expense.setUserId(ID_OF_LOGGED_USER);
    expense.setExpenseId(expensesFile.getIdOfLastExpense()+1);

    cout << "czy wydatek dotyczy dnia dzisiejszego, tak lube nie (t/n)? ";

    do {
        choice = AdjuvantMethods::loadMark();
        switch (choice) {
        case 't':
            date = AdjuvantMethods::getCurrentDate();
            expense.setDate(date);
            break;
        case 'n':
            cout << "podaj date w formacie rrrr-mm-dd np. 2017-11-01: ";
            date = AdjuvantMethods::readLine();
            if (AdjuvantMethods::checkIfDateIsCorrect(date) == true) {
                expense.setDate(date);
                break;
            } else {
                cout << endl << "wprowadzona data jest niepoprawna " << endl;
                choice = ' ';
            }
        default:
            cout << "sprobuj ponownie wybierajac (t/n) ";
        }
    } while(choice != 't' && choice != 'n');

    cout << endl << "Napisz czego dotyczyl wydatek: ";
    item = AdjuvantMethods::readLine();
    expense.setItem(item);

    cout << endl << "Podaj wysokosc wydatku: ";
    amount = AdjuvantMethods::readLine();
    amount = AdjuvantMethods::changeCommaToDot(amount);
    expense.setAmount(amount);

    return expense;
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

    int sum = 0;
    int AmountOfDaysFromCurrentMonth = AdjuvantMethods::lastDayOfCurrentMonth();
    int lastDateInInt = AdjuvantMethods::getDateOfLastDayFromCurrentMonthInInt();
    int dateFromVector = AdjuvantMethods::convertDateToInt(income.getDate());

    if ( (dateFromVector <= lastDateInInt) && (dateFromVector >= lastDateInInt - AmountOfDaysFromCurrentMonth))
    {
    cout << endl << "Id:         " << income.getIncomeId() << endl;
    cout << "Data:               " << income.getDate() << endl;
    cout << "Item:               " << income.getItem() << endl;
    cout << "kwota przychodu:    " << income.getAmount() << endl;
    }
}

void BalanceManager::showBilanceFromCurrentMonth(){


    system("cls");
        cout << "        >>> BILANS Z BIEZACEGO MIESIACA <<<" << endl;
        cout << "-----------------------------------------------" << endl;
        for (vector <Income> :: iterator itr = incomes.begin(); itr != incomes.end(); itr++) {
            showIncomeData(*itr);
        }
        cout << endl;

    system("pause");
}


