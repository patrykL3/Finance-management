#include "DateManager.h"


string DateManager::convertIntDateToStringDate(int date) {
    string convertedDate = AuxiliaryMethods::convertIntToString(date);

    convertedDate.insert(4, "-");
    convertedDate.insert(7, "-");

    return convertedDate;
}

int DateManager::convertStringDateToIntDate(string date) {
    int convertedDate = 0;

    date.erase(4, 1);
    date.erase(6, 1);
    convertedDate = AuxiliaryMethods::convertStringToInt(date);

    return convertedDate;
}

int DateManager::getTodaysDateInIntFormat() {
    int TodaysDateInIntFormat = 0;
    SYSTEMTIME systemTime;
    GetSystemTime(&systemTime);

    TodaysDateInIntFormat = systemTime.wYear * 10000 + systemTime.wMonth * 100 + systemTime.wDay;

    return TodaysDateInIntFormat;
}

bool DateManager::isDateCorrect(string date) {
    Date convertedDate;
    bool isDateCorrect = false;

    if(!isCorrectDateFormat(date))
        return isDateCorrect;

    convertedDate = convertStringDateToConstructor(date);
    if (convertedDate.getYear() < 2000 || convertedDate.getYear() > getCurrentYear()) {
        return isDateCorrect;
    } else if (convertedDate.getMonth() < 1 || convertedDate.getMonth() > 12 || (convertedDate.getYear() == getCurrentYear() && convertedDate.getMonth() > getCurrentMonth())) {
        return isDateCorrect;
    } else if (convertedDate.getDay() < 1 || convertedDate.getDay() > getNumberDaysOfMonth(convertedDate.getMonth(), convertedDate.getYear())) {
        return isDateCorrect;
    } else {
        isDateCorrect = true;
    }

    return isDateCorrect;
}

bool DateManager::isCorrectDateFormat(string date) {
    bool isCorrectDateFormat = false;
    int charNumber0inASCI = 48;
    int charNumber9inASCI = 57;

    if (date.length() != 10)
        return isCorrectDateFormat;
    if(date[4] != '-' || date[7] != '-')
        return isCorrectDateFormat;
    for(int i = 0; i < 4; ++i) {
        if(date[i] < charNumber0inASCI || date[i] > charNumber9inASCI)
            return isCorrectDateFormat;
    }
    for(int i = 5; i < 7; ++i) {
        if(date[i] < charNumber0inASCI || date[i] > charNumber9inASCI)
            return isCorrectDateFormat;
    }
    for(int i = 8; i < 10; ++i) {
        if(date[i] < charNumber0inASCI || date[i] > charNumber9inASCI)
            return isCorrectDateFormat;
    }

    isCorrectDateFormat = true;
    return isCorrectDateFormat;
}

Date DateManager::convertStringDateToConstructor(string dateInLine) {
    Date date;
    string partDataOfDate = "";
    int numberPartDataOfDate = 1;

    for (int characterPosition = 0; characterPosition < dateInLine.length(); characterPosition++) {
        if (dateInLine[characterPosition] != '-' && characterPosition != dateInLine.length() -1) {
            partDataOfDate += dateInLine[characterPosition];
        } else {
            switch(numberPartDataOfDate) {
            case 1:
                date.setYear(atoi(partDataOfDate.c_str()));
                break;
            case 2:
                date.setMonth(atoi(partDataOfDate.c_str()));
                break;
            case 3:
                partDataOfDate += dateInLine[characterPosition];
                date.setDay(atoi(partDataOfDate.c_str()));
                break;
            }
            partDataOfDate = "";
            numberPartDataOfDate++;
        }
    }
    return date;
}

int DateManager::getCurrentYear() {
    int currentYear = 0;
    SYSTEMTIME systemTime;
    GetSystemTime(&systemTime);

    currentYear = systemTime.wYear;

    return currentYear;
}

int DateManager::getCurrentMonth() {
    int currentMonth = 0;
    SYSTEMTIME systemTime;
    GetSystemTime(&systemTime);

    currentMonth = systemTime.wMonth;

    return currentMonth;
}

int DateManager::getCurrentDay() {
    int currentDay = 0;
    SYSTEMTIME systemTime;
    GetSystemTime(&systemTime);

    currentDay = systemTime.wDay;

    return currentDay;
}

int DateManager::getNumberDaysOfMonth(int numberMonth, int yearNumberOfTheMonth) {
    int numberDayOfCheckingMonth = 0;

    switch(numberMonth) {
    case 1:
        numberDayOfCheckingMonth = 31;
        break;
    case 2:
        numberDayOfCheckingMonth = getNumberDaysOfFebruary(yearNumberOfTheMonth);
        break;
    case 3:
        numberDayOfCheckingMonth = 31;
        break;
    case 4:
        numberDayOfCheckingMonth = 30;
        break;
    case 5:
        numberDayOfCheckingMonth = 31;
        break;
    case 6:
        numberDayOfCheckingMonth = 30;
        break;
    case 7:
        numberDayOfCheckingMonth = 31;
        break;
    case 8:
        numberDayOfCheckingMonth = 31;
        break;
    case 9:
        numberDayOfCheckingMonth = 30;
        break;
    case 10:
        numberDayOfCheckingMonth = 31;
        break;
    case 11:
        numberDayOfCheckingMonth = 30;
        break;
    case 12:
        numberDayOfCheckingMonth = 31;
        break;
    }

    return numberDayOfCheckingMonth;
}

int DateManager::getNumberDaysOfFebruary(int yearNumberOfFebruary) {
    int numberDaysOfFebruary = 0;

    if((yearNumberOfFebruary % 4 == 0 && yearNumberOfFebruary % 100 != 0) || yearNumberOfFebruary % 400 == 0)
        numberDaysOfFebruary = 29;
    else
        numberDaysOfFebruary = 28;

    return numberDaysOfFebruary;
}
