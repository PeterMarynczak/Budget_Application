#ifndef USERFILE_H
#define USERFILE_H

#include <iostream>
#include <vector>
#include <cstdlib>

#include "Markup.h"
#include "User.h"
#include "File.h"

using namespace std;

class UserFile :public File{

    const string NAME_OF_USER_FILE;
    CMarkup xml;

public:
    UserFile(string nameOfUserFile) : NAME_OF_USER_FILE(nameOfUserFile) {};

    void appendUserToFile(User user);
    vector <User> fetchUsersDataFromFile();
    bool ifFileIsEmpty(){
        File::ifFileIsEmpty(xml);
    }
    void saveUsersToFile(int &idOfLoggedUser, string newPassword);
};

#endif
