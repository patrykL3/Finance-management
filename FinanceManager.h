#ifndef FINANCE_MANAGER_H
#define FINANCE_MANAGER_H


#include <iostream>
#include <vector>
#include <windows.h>
#include "Income.h"
//#include "Expense.h"
#include "DateManager.h"
#include "FileWithIncomes.h"
//#include "FileWithExpenses.h"


using namespace std;


class FinanceManager {

    const int LOGGED_USER_ID;
    vector<Income> incomes;
    //vector<Expense> expenses;
    FileWithIncomes fileWithIncomes;
    //FileWithExpenses fileWithExpenses;
    DateManager dateManager;

    /*void wyswietlDaneAdresata(Adresat adresat);
    Adresat podajDaneNowegoAdresata();
    string zamienPierwszaLitereNaDuzaAPozostaleNaMale(string tekst);
    void wyswietlIloscWyszukanychAdresatow(int iloscAdresatow);
    int podajIdWybranegoAdresata();
    char wybierzOpcjeZMenuEdycja();*/



    ////string replaceTheCommaOnPeriod();
    Income provideDataOfNewIncome();
    int getNewIncomeId();

public:

    FinanceManager(string fileNameWithIncomes, int loggedUserId)//, string fileNameWithExpenses, int loggedUserId)
        : fileWithIncomes(fileNameWithIncomes), LOGGED_USER_ID (loggedUserId) { //fileWithExpenses(fileNameWithExpenses), LOGGED_USER_ID (loggedUserId) {
        incomes = fileWithIncomes.loadIncomesOfLoggedUserFromFile(LOGGED_USER_ID);
        //expenses = fileWithExpenses.loadExpensesOfLoggedUserFromFile(LOGGED_USER_ID);
    };

    void addIncome();



    void addExpense();
    void displayBudgetBalanceForTheCurrentMonth();
    void displayBudgetBalanceForThePeriod();
};


#endif
