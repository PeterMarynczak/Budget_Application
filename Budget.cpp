#include "Budget.h"

void Budget::addIncome(){
    balanceManager->addIncome();
}

void Budget::registerUser(){
    userManager.registerUser();
}
void Budget::userLogIn(){
    userManager.userLogIn();
        if (userManager.ifUserIsLogged()){
        balanceManager = new BalanceManager(INCOME_FILE_NAME, userManager.getIdOfLoggedUser());
    }
}

void Budget::userLogOut(){
    userManager.userLogOut();
    delete balanceManager;
    balanceManager = NULL;
}

bool Budget::ifUserIsLogged(){
    userManager.ifUserIsLogged();
}

void Budget::changeUserPassword(){
    userManager.changeUserPassword();
}

char Budget::chooseOptionFromMainMenu(){

    char choice;
    system("cls");
    cout << "    >>> MENU  GLOWNE <<<" << endl;
    cout << "---------------------------" << endl;
    cout << "1. Rejestracja" << endl;
    cout << "2. Logowanie" << endl;
    cout << "9. Koniec programu" << endl;
    cout << "---------------------------" << endl;
    cout << "Twoj wybor: ";
    cin.sync();

    choice = AdjuvantMethods::loadMark();
    return choice;
}

char Budget::chooseOptionFromUserMenu(){

    char choice;
    system("cls");
    cout << "    >>> MENU  UZYTKOWNIKA <<<" << endl;
    cout << "---------------------------" << endl;
    cout << "1. Dodaj przychod" << endl;
    cout << "2. Dodaj wydatek" << endl;
    cout << "3. Bilans z biezacego miesiaca" << endl;
    cout << "4. Bilans z poprzedniego miesiaca" << endl;
    cout << "5. Bilans z wybranego okresu" << endl;
    cout << "6. Zmien haslo" << endl;
    cout << "9. Wyloguj sie" << endl;
    cout << "---------------------------" << endl;
    cout << "Twoj wybor: ";
    cin.sync();

    choice = AdjuvantMethods::loadMark();
    return choice;



}
