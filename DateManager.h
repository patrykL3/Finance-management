#ifndef DATE_MANAGER_H
#define DATE_MANAGER_H

#include <sstream>
#include <iostream>
#include <time.h>
#include <windows.h>
#include "AuxiliaryMethods.h"
#include "Date.h"

using namespace std;


class DateManager {

    int getNumberDaysOfFebruary(int yearNumberOfFebruary);
    int getNumberDaysOfMonth(int numberMonth, int yearNumberOfTheMonth);
    int getCurrentYear();
    int getCurrentMonth();
    int getCurrentDay();
    Date convertStringDateToConstructor(string date);
    bool isCorrectDateFormat(string date);

public:

    string convertIntDateToStringDate(int date);
    int getTodaysDateInIntFormat();
    bool isDateCorrect(string date);
    int convertStringDateToIntDate(string date);
};


#endif
