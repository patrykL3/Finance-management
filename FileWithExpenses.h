#ifndef FILE_WITH_EXPENSES_H
#define FILE_WITH_EXPENSES_H

#include <iostream>
#include <vector>
#include <cstdlib>
#include "Expense.h"
#include "AuxiliaryMethods.h"
#include "DateManager.h"
#include "XmlFile.h"

using namespace std;


class FileWithExpenses:private XmlFile {

    int lastExpenseId;

    int getLastExpenseIdFromFile();
    Expense getExpenseDataFromFileToConstructor();

public:

    FileWithExpenses(string fileNameWithExpenses) : XmlFile(fileNameWithExpenses) {
        lastExpenseId = getLastExpenseIdFromFile();
    };

    void addExpenseToFile(Expense expense);
    int getLastExpenseId();
    vector<Expense> loadExpensesOfLoggedUserFromFile(int loggedUserId);
};


#endif
