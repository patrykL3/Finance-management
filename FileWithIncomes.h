#ifndef FILE_WITH_INCOMES_H
#define FILE_WITH_INCOMES_H

#include <iostream>
#include <vector>
#include <cstdlib>
#include "Income.h"
#include "AuxiliaryMethods.h"
#include "DateManager.h"
#include "XmlFile.h"

using namespace std;


class FileWithIncomes:private XmlFile {

    int lastIncomeId;

    int getLastIncomeIdFromFile();
    Income getIncomeDataFromFileToConstructor();

public:

    FileWithIncomes(string fileNameWithIncomes) : XmlFile(fileNameWithIncomes) {
        lastIncomeId = getLastIncomeIdFromFile();
    };

    void addIncomeToFile(Income income);
    int getLastIncomeId();
    vector<Income> loadIncomesOfLoggedUserFromFile(int loggedUserId);
};


#endif
