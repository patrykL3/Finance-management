#ifndef FINANCE_MANAGER_H
#define FINANCE_MANAGER_H


#include <iostream>
#include <vector>
#include <windows.h>
#include "Income.h"
#include "Expense.h"
#include "DateManager.h"
#include "FileWithIncomes.h"
#include "FileWithExpenses.h"



using namespace std;


class FinanceManager {

    const int LOGGED_USER_ID;
    vector<Income> incomes;
    vector<Expense> expenses;
    FileWithIncomes fileWithIncomes;
    FileWithExpenses fileWithExpenses;
    DateManager dateManager;




    Income provideDataOfNewIncome();
    void displayDataIncome(Income income);
    void displayDataExpense(Expense expense);
    int getNewIncomeId();
    Expense provideDataOfNewExpense();
    int getNewExpenseId();
    string enterBeginBalanceDate();
    string enterEndBalanceDate();
    void displayBalance(float sumOfIncomes, float sumOfExpenses);
    void displayBudgetBalanceForTheMonth(int yearOfTheBalanceMonth, int monthBalance);

public:

    FinanceManager(string fileNameWithIncomes, int loggedUserId, string fileNameWithExpenses)
        : fileWithIncomes(fileNameWithIncomes), LOGGED_USER_ID (loggedUserId), fileWithExpenses(fileNameWithExpenses) {
        incomes = fileWithIncomes.loadIncomesOfLoggedUserFromFile(LOGGED_USER_ID);
        expenses = fileWithExpenses.loadExpensesOfLoggedUserFromFile(LOGGED_USER_ID);
    };

    void addIncome();
    void addExpense();



    void displayBudgetBalanceForTheCurrentMonth();
    void displayBudgetBalanceForThePreviousMonth();
    void displayBudgetBalanceForThePeriod();
};


#endif
