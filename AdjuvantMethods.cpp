#include "AdjuvantMethods.h"

string AdjuvantMethods::readLine() {
    string enteredData = "";
    getline(cin, enteredData);
    return enteredData;
}

char AdjuvantMethods::loadMark() {

    string input = "";
    char mark = {0};

    while(true) {
        getline(cin, input);
        if(input.length() == 1) {
            mark = input[0];
            break;
        }
        cout << "To nie jest pojedynczy znak. Wpisz ponownie." << endl;
    }
    return mark;
}

int AdjuvantMethods::convertStringToInt(string number) {
    int numberInt;
    istringstream iss(number);
    iss >> numberInt;

    return numberInt;
}

int AdjuvantMethods::convertDateToInt(string date) {

    string dateWithoutDash = "";
    for (int i = 0; i < date.length() ; i++) {
        if (date[i] != '-') {
            dateWithoutDash += date[i];
        }
    }
    return  convertStringToInt(dateWithoutDash);
}

bool AdjuvantMethods::checkIfDateIsCorrect(string date) {

    time_t currentTime = time(0);
    tm* now = localtime(&currentTime);
    int enteredUserDate = convertDateToInt(date);
    int youngestDate = 20000101;
    int latestDate = (((now->tm_year + 1900) * 10000) +(100 * (now->tm_mon + 1) + lastDayOfCurrentMonth()));

    if ((enteredUserDate >= youngestDate) && (enteredUserDate <= latestDate))
        return true;
    else
        return false;
}

string AdjuvantMethods::getCurrentDate() {

    string date = "";
    int yearNr, monthNr, dayNr;
    string year, month, day;
    time_t currentTime = time(0);
    tm* now = localtime(&currentTime);

    yearNr = now->tm_year + 1900;
    monthNr = now->tm_mon + 1;
    dayNr = now->tm_mday;

    year = convertIntToString(yearNr);
    month = checkIfSingleNumber(monthNr);
    day = checkIfSingleNumber(dayNr);

    date = year + "-" + month + "-" + day;
    return date;
}

string AdjuvantMethods::checkIfSingleNumber (int number) {

    string date;
    if (number < 10) {
        date = "0" + convertIntToString(number);
        return date;
    } else
        return convertIntToString(number);
}


string AdjuvantMethods::convertIntToString(int number) {
    ostringstream ss;
    ss << number;
    string str = ss.str();
    return str;
}

int AdjuvantMethods::lastDayOfCurrentMonth() {

    time_t currentTime = time(0);
    tm* now = localtime(&currentTime);
    int monthNr = now->tm_mon + 1;
    int lastDay;

    switch (monthNr) {
    case 1:
    case 3:
    case 5:
    case 7:
    case 8:
    case 10:
    case 12:
        lastDay = 31;
        break;
    case 4:
    case 6:
    case 9:
    case 11:
        lastDay = 30;
        break;
    case 2:
        int year = now->tm_year + 1900;
        if (((year%4 == 0) && (year%100 != 0)) || (year%400 == 0)) {
            lastDay = 29;
            break;
        } else
            lastDay = 28;
        break;
    }
    return lastDay;
}

string AdjuvantMethods::changeCommaToDot(string amount){

for (int i = 0; i < amount.length(); i++){
    if(amount[i] == ',')
        amount[i] == '.';
}
return amount;
}

