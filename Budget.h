#ifndef BUDGET_H
#define BUDGET_H

#include "UserManager.h"

#include <iostream>

using namespace std;

class Budget{

UserManager userManager;

public:
    Budget(string UserFileName): userManager(UserFileName) {};
    void registerUser();
    void userLogIn();

};

#endif
