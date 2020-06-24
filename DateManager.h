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


    int getCurrentDay();
    Date convertStringDateToConstructor(string date);
    bool isCorrectDateFormat(string date);

public:
    int getYearFromIntDate(int date);
    int getMonthFromIntDate(int date);
    int getCurrentMonth();
    int getCurrentYear();
    string convertIntDateToStringDate(int date);
    int getTodaysDateInIntFormat();
    bool isDateCorrect(string date);
    int convertStringDateToIntDate(string date);
};


#endif
