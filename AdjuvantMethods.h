#ifndef ADJUVANTMETHODS_H
#define ADJUVANTMETHODS_H

#include <iostream>
#include <cstdlib>
#include <time.h>
#include <sstream>
#include <algorithm>

using namespace std;

class AdjuvantMethods{

public:
    static char loadMark();
    static int convertStringToInt(string number);
    static string convertIntToString(int number);
    static int convertDateToInt(string date);
    static bool checkIfDateIsCorrect(string date);
    static string readLine();
    static string getCurrentDate();
    static string checkIfSingleNumber (int number);
    static int lastDayOfCurrentMonth();
    static string changeCommaToDot(string amount);

};

#endif
