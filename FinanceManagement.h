#ifndef FINANCE_MANAGEMENT_H
#define FINANCE_MANAGEMENT_H

#include <iostream>
#include"UserManager.h"
#include"FinanceManager.h"
#include"AuxiliaryMethods.h"

using namespace std;


class FinanceManagement {

    UserManager userManager;
    FinanceManager *financeManager;
    const string FILE_NAME_WITH_INCOMES;
    const string FILE_NAME_WITH_EXPENSES;

public:

    FinanceManagement(string fileNameWithUsers, string fileNameWithIncomes, string fileNameWithExpenses)
        : userManager(fileNameWithUsers), FILE_NAME_WITH_INCOMES(fileNameWithIncomes), FILE_NAME_WITH_EXPENSES(fileNameWithExpenses) {
        financeManager = NULL;
    };
    ~FinanceManagement() {
        delete financeManager;
        financeManager = NULL;
    }

    bool isLogged();
    char selectOptionFromLoginMenu();
    void userRegistration();
    void userLogin();

    char selectOptionFromMainMenu();
    void addIncome();
    void addExpense();
    void displayBudgetBalanceForTheCurrentMonth();
    void displayBudgetBalanceForThePreviousMonth();
    void displayBudgetBalanceForThePeriod();
    void changePasswordLoggedUser();
    void logOutUser();
};


#endif

