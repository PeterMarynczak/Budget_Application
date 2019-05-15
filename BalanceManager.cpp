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


void BalanceManager::showIncomeData() {

    bilance = 0;
    double sumOfIncomes = 0;
    int AmountOfDaysFromCurrentMonth = AdjuvantMethods::getAmountOfDaysFromCurrentMonth();
    int lastDateInInt = AdjuvantMethods::getDateOfLastDayFromCurrentMonthInInt();
    int dateFromVector = 0;
    sort(incomes.begin(),incomes.end());

    for (int i = 0; i < incomes.size(); i++) {
        dateFromVector = AdjuvantMethods::convertDateToInt(incomes[i].getDate());
        if ( (dateFromVector <= lastDateInInt) && (dateFromVector >= lastDateInInt - AmountOfDaysFromCurrentMonth)) {
            cout << endl << "Id przychodu: " << incomes[i].getIncomeId() << endl;
            cout << "Data uzyskania przychodu:     " << incomes[i].getDate() << endl;
            cout << "Przychod z tytulu:            " << incomes[i].getItem() << endl;
            cout << "Kwota przychodu:              " << incomes[i].getAmount() << endl;
            sumOfIncomes += atof(incomes[i].getAmount().c_str());
        }
    }
    cout << endl << "Suma przychodow w tym miesiacu wynosi: " << sumOfIncomes <<" zl" << endl;
    bilance = sumOfIncomes;
}

void BalanceManager::showExpensesData() {

    double sumOfExpenses = 0;
    int AmountOfDaysFromCurrentMonth = AdjuvantMethods::getAmountOfDaysFromCurrentMonth();
    int lastDateInInt = AdjuvantMethods::getDateOfLastDayFromCurrentMonthInInt();
    int dateFromVector = 0;
    sort(expenses.begin(),expenses.end());

    for (int i = 0; i < expenses.size(); i++) {
        dateFromVector = AdjuvantMethods::convertDateToInt(expenses[i].getDate());
        if ( (dateFromVector <= lastDateInInt) && (dateFromVector >= lastDateInInt - AmountOfDaysFromCurrentMonth)) {
            cout << endl << "Id wydatku: " << expenses[i].getExpenseId() << endl;
            cout << "Data wydatku:     "      << expenses[i].getDate() << endl;
            cout << "Wydatek z tytulu:      " << expenses[i].getItem() << endl;
            cout << "Kwota wydatku:         " << expenses[i].getAmount() << endl;
            sumOfExpenses += atof(expenses[i].getAmount().c_str());
        }
    }
    cout << endl << "Suma wydatkow w tym miesiacu wynosi: " << sumOfExpenses <<" zl";
    bilance -= sumOfExpenses;
}

void BalanceManager::showBilanceFromCurrentMonth(){

    system("cls");
        cout << "    >>> BILANS Z BIEZACEGO MIESIACA <<<" << endl;
        cout << "-----------------------------------------------" << endl;
        cout << "             >>> PRZYCHODY <<<" << endl;
        showIncomeData();
        cout << endl;
        cout << "             >>> WYDATKI <<<" << endl;
        showExpensesData();
        cout << endl;
        cout << "-----------------------------------------------" << endl;
        cout << "      >>> BILANS <<<" << endl << endl;
        cout << bilance << "zl" << endl << endl;
        if (bilance > 0) cout << "Twoj bilans jest dodatni, trzymaj tak dalej" << endl << endl;
        else cout << "Twoj bilans jest ujemny, uwazaj na wydatki" << endl;
        bilance = 0;

    system("pause");
}

void BalanceManager::showBilanceFromLastMonth(){

    system("cls");
        cout << "    >>> BILANS Z OSTATNIEGO MIESIACA <<<" << endl;
        cout << "-----------------------------------------------" << endl;
        cout << "             >>> PRZYCHODY <<<" << endl;
        showIncomeDataFromLastMonth();
        cout << endl;
        cout << "             >>> WYDATKI <<<" << endl;
        showExpensesDataFromLastMonth();
        cout << endl;
        cout << "-----------------------------------------------" << endl;
        cout << "      >>> BILANS <<<" << endl << endl;
        cout << bilance << "zl" << endl << endl;
        if (bilance > 0) cout << "Twoj bilans jest dodatni, trzymaj tak dalej" << endl << endl;
        else cout << "Twoj bilans jest ujemny, uwazaj na wydatki" << endl;
        bilance = 0;

    system("pause");
}

void BalanceManager::showIncomeDataFromLastMonth(){

    bilance = 0;
    double sumOfIncomes = 0;
    int AmountOfDaysFromLastMonth = AdjuvantMethods::getAmountOfDaysFromLastMonth();
    int lastDateInInt = AdjuvantMethods::getDateOfLastDayFromLastMonthInInt();
    int dateFromVector = 0;
    sort(incomes.begin(),incomes.end());

    for (int i = 0; i < incomes.size(); i++) {
        dateFromVector = AdjuvantMethods::convertDateToInt(incomes[i].getDate());
        if ( (dateFromVector <= lastDateInInt) && (dateFromVector >= lastDateInInt - AmountOfDaysFromLastMonth)) {
            cout << endl << "Id przychodu: " << incomes[i].getIncomeId() << endl;
            cout << "Data uzyskania przychodu:     " << incomes[i].getDate() << endl;
            cout << "Przychod z tytulu:            " << incomes[i].getItem() << endl;
            cout << "Kwota przychodu:              " << incomes[i].getAmount() << endl;
            sumOfIncomes += atof(incomes[i].getAmount().c_str());
        }
    }
    cout << endl << "Suma przychodow w ostatnim miesiacu wyniosla: " << sumOfIncomes <<" zl" << endl;
    bilance = sumOfIncomes;
}

void BalanceManager::showExpensesDataFromLastMonth(){

    double sumOfExpenses = 0;
    int AmountOfDaysFromLastMonth = AdjuvantMethods::getAmountOfDaysFromLastMonth();
    int lastDateInInt = AdjuvantMethods::getDateOfLastDayFromLastMonthInInt();
    int dateFromVector = 0;
    sort(expenses.begin(),expenses.end());

    for (int i = 0; i < expenses.size(); i++) {
        dateFromVector = AdjuvantMethods::convertDateToInt(expenses[i].getDate());
        if ( (dateFromVector <= lastDateInInt) && (dateFromVector >= lastDateInInt - AmountOfDaysFromLastMonth)) {
            cout << endl << "Id wydatku: " << expenses[i].getExpenseId() << endl;
            cout << "Data wydatku:     "      << expenses[i].getDate() << endl;
            cout << "Wydatek z tytulu:      " << expenses[i].getItem() << endl;
            cout << "Kwota wydatku:         " << expenses[i].getAmount() << endl;
            sumOfExpenses += atof(expenses[i].getAmount().c_str());
        }
    }
    cout << endl << "Suma wydatkow w tym miesiacu wynosi: " << sumOfExpenses <<" zl";
    bilance -= sumOfExpenses;
}










