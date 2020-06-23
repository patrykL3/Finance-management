#ifndef DATE_H
#define DATE_H

#include <iostream>

using namespace std;


class Date {

    int year;
    int month;
    int day;

public:

    Date(int year = 0, int month = 0, int day = 0) {
        this -> year = year;
        this -> month = month;
        this -> day = day;
    }

    void setYear(int newYear);
    void setMonth(int newMonth);
    void setDay(int newDay);

    int getYear();
    int getMonth();
    int getDay();
};


#endif
