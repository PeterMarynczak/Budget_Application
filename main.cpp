#include <iostream>
#include "UserManager.h"

using namespace std;

int main()
{

UserManager usermanager("users.xml");

usermanager.registerUser();

    return 0;
}
