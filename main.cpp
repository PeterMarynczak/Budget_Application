#include <iostream>
#include "Budget.h"

using namespace std;

int main()
{

Budget budget("users.xml");

//budget.registerUser();
budget.userLogIn();

    return 0;
}
