#include "UserManager.h"

User UserManager::EnterDataOfNewUser() {

    User user;
    user.setId(getIdOfNewUser());

    string login, password, name, surname;

    cout << "      >>> LOGOWANIE <<<" << endl;
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
