#ifndef USERMANAGER_H
#define USERMANAGER_H
#include <iostream>
#include <vector>
#include <windows.h>

#include "User.h"
#include "UserFile.h"

using namespace std;

class UserManager{

    vector <User> users;
    UserFile userFile;
    int idOfLoggedUser;
    User EnterDataOfNewUser();
    int getIdOfNewUser();
    bool ifLoginExists(string login);

public:
    UserManager(string NAME_OF_USER_FILE) : userFile(NAME_OF_USER_FILE){
        idOfLoggedUser = 0;
        users = userFile.fetchUsersDataFromFile();
    };
    void registerUser();
    void userLogOut();
    void userLogIn();
    //void wypiszWszystkichUzytkownikow();
    //void logowanieUzytkownika();
    //void ustawIDZalogowanegoUzytkownika(int noweID);
    //int pobierzIdZalogowanegoUzytkownika();
    //bool czyUzytkownikJestZalogowany();
    //void wylogowanieUzytkownika();
    //void zmianaHaslaZalogowanegoUzytkownika();

};

#endif
