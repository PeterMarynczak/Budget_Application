#include "UserManager.h"


void UserManager::userLogOut(){
    idOfLoggedUser = 0;
}

bool UserManager::ifUserIsLogged(){

if (idOfLoggedUser > 0)
    return true;
else
    return false;
}

int UserManager::getIdOfLoggedUser(){
return idOfLoggedUser;
}

void UserManager::userLogIn() {

    string login = "", password = "";
    system("cls");
    cout << "      >>> LOGOWANIE <<<" << endl;
    cout << "--------------------------------" << endl;
    cout << "Podaj login: ";
    cin >> login;

    vector <User>::iterator itr = users.begin();
    while (itr != users.end()) {
        if (itr -> getLogin() == login) {
            for (int choiceAmount = 3; choiceAmount > 0; choiceAmount--) {
                cout << "Podaj haslo. Pozostalo prob: " << choiceAmount << ": ";
                cin >> password;

                if (itr -> getPassword() == password) {
                    idOfLoggedUser = itr -> getId();
                    cout << endl << "Zalogowales sie." << endl << endl;
                    system("pause");
                    return;
                }
            }
            cout << "Wprowadzono 3 razy bledne haslo." << endl;
            system("pause");
            return;
        }
        itr++;
    }
    cout << "Nie ma uzytkownika z takim loginem" << endl << endl;
    system("pause");
    return;
}

User UserManager::EnterDataOfNewUser() {

    User user;
    user.setId(getIdOfNewUser());

    string login, password, name, surname;

    system("cls");
    cout << "      >>> REJESTRACJA <<<" << endl;
    cout << "--------------------------------" << endl;
    do {
        cout << "Podaj login: ";
        cin >> login;
        user.setLogin(login);
    } while (ifLoginExists(user.getLogin()) == true);

    cout << "Podaj haslo: ";
    cin >> password;
    user.setPassword(password);
    cout << "Podaj imie: ";
    cin >> name;
    user.setName(name);
    cout << "Podaj nazwisko: ";
    cin >> surname;
    user.setSurname(surname);

    return user;
}

int UserManager::getIdOfNewUser() {
    if (users.empty() == true)
        return 1;
    else
        return users.back().getId() + 1;
}

bool UserManager::ifLoginExists(string login) {
    for (int i = 0; i < users.size(); i++){
        if(users[i].getLogin() == login){
            cout << endl << "Istnieje uzytkownik o takim loginie" << endl;
        return true;
        }
    }
    return false;
}

void UserManager::registerUser() {

    User user = EnterDataOfNewUser();
    users.push_back(user);
    userFile.appendUserToFile(user);

    cout << endl << "Konto zalozono pomyslnie" << endl << endl;
    system("pause");
}

void UserManager::changeUserPassword(){

    string newPassword;
    cout << "Podaj nowe haslo: ";
    cin >> newPassword;

    for (vector <User>::iterator itr = users.begin(); itr != users.end(); itr++){
        if (itr -> getId() == idOfLoggedUser){
            itr -> setPassword(newPassword);
            cout << "Haslo zostalo zmienione." << endl;
            system("pause");
        }
    }
    userFile.saveUsersToFile(idOfLoggedUser, newPassword);
}

