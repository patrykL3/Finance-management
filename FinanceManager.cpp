#include "FinanceManager.h"

void FinanceManager::displayBalance(float sumOfIncomes, float sumOfExpenses) {
    float sumOfCashFlow = sumOfIncomes - sumOfExpenses;

    cout << " Suma przychodow: " << sumOfIncomes << " zl" << endl;
    cout << " Suma wydatkow:   " << sumOfExpenses << " zl" << endl;
    cout << " Bilans:          " << sumOfCashFlow << " zl" << endl << endl;
}

void FinanceManager::displayDataExpense(Expense expense) {
    cout << " Id :    " << expense.getExpenseId() << endl;
    cout << " Data:   " << dateManager.convertIntDateToStringDate(expense.getDate()) << endl;
    cout << " Typ:    " << expense.getItem() << endl;
    cout << " Kwota:  " << expense.getAmount() << " zl" << endl << endl;
}

void FinanceManager::displayDataIncome(Income income) {
    cout << " Id:     " << income.getIncomeId() << endl;
    cout << " Data:   " << dateManager.convertIntDateToStringDate(income.getDate()) << endl;
    cout << " Typ:    " << income.getItem() << endl;
    cout << " Kwota:  " << income.getAmount() << " zl" << endl << endl;
}

string FinanceManager::enterBeginBalanceDate() {
    string beginBalanceDate = "";

    do {
        cout << "Wprowadz date poczatku okresu bilansu (format rrrr-mm-dd): ";
        beginBalanceDate = AuxiliaryMethods::loadLine();
        if (!dateManager.isDateCorrect(beginBalanceDate)) {
            cout << "Data nieprawidlowa. Poprawny format daty: rrrr-mm-dd. Zakres daty od 2000-01-01 do ostatniego dnia biezacego miesiaca." << endl;
            system("pause");
        }
    } while (!dateManager.isDateCorrect(beginBalanceDate));

    return beginBalanceDate;
}

string FinanceManager::enterEndBalanceDate() {
    string endBalanceDate = "";

    do {
        cout << "Wprowadz date konca okresu bilansu (format rrrr-mm-dd): ";
        endBalanceDate = AuxiliaryMethods::loadLine();
        if (!dateManager.isDateCorrect(endBalanceDate)) {
            cout << "Data nieprawidlowa. Poprawny format daty: rrrr-mm-dd. Zakres daty od 2000-01-01 do ostatniego dnia biezacego miesiaca." << endl;
            system("pause");
        }
    } while (!dateManager.isDateCorrect(endBalanceDate));

    return endBalanceDate;
}

void FinanceManager::displayAndCalculateIncomesForTheMonth(float &sumOfIncomes, int yearOfTheBalanceMonth, int monthBalance) {
    if (!incomes.empty()) {
        sort(incomes.begin(), incomes.end());
        cout << " PRZYCHODY:" << endl << endl;
        for(int i = 0; i < incomes.size(); ++i) {
            if(dateManager.getYearFromIntDate(incomes[i].getDate()) == yearOfTheBalanceMonth && dateManager.getMonthFromIntDate(incomes[i].getDate()) == monthBalance) {
                displayDataIncome(incomes[i]);
                sumOfIncomes += incomes[i].getAmount();
            }
        }
    }
    if(sumOfIncomes == 0) {
        cout << " BRAK PRZYCHODOW." << endl << endl;
    }
}

void FinanceManager::displayAndCalculateExpensesForTheMonth(float &sumOfExpenses, int yearOfTheBalanceMonth, int monthBalance) {
    if (!expenses.empty()) {
        sort(expenses.begin(), expenses.end());
        cout << " WYDATKI:" << endl << endl;
        for(int i = 0; i < expenses.size(); ++i) {
            if(dateManager.getYearFromIntDate(expenses[i].getDate()) == yearOfTheBalanceMonth && dateManager.getMonthFromIntDate(expenses[i].getDate()) == monthBalance) {
                displayDataExpense(expenses[i]);
                sumOfExpenses += expenses[i].getAmount();
            }
        }
    }
    if(sumOfExpenses == 0) {
        cout << " BRAK WYDATKOW." << endl << endl;
    }
}

void FinanceManager::displayAndCalculateExpensesForThePeriod(float &sumOfExpenses, string beginBalanceDate, string endBalanceDate) {
    if (!expenses.empty()) {
        sort(expenses.begin(), expenses.end());
        cout << " WYDATKI:" << endl << endl;
        for(int i = 0; i < expenses.size(); ++i) {
            if(expenses[i].getDate() >=  dateManager.convertStringDateToIntDate(beginBalanceDate) && expenses[i].getDate() <=  dateManager.convertStringDateToIntDate(endBalanceDate)) {
                displayDataExpense(expenses[i]);
                sumOfExpenses += expenses[i].getAmount();
            }
        }
    }
    if(sumOfExpenses == 0) {
        cout << " BRAK WYDATKOW." << endl << endl;
    }
}

void FinanceManager::displayAndCalculateIncomesForThePeriod(float &sumOfIncomes, string beginBalanceDate, string endBalanceDate) {
    if (!incomes.empty()) {
        sort(incomes.begin(), incomes.end());
        cout << " PRZYCHODY:" << endl << endl;
        for(int i = 0; i < incomes.size(); ++i) {
            if(incomes[i].getDate() >=  dateManager.convertStringDateToIntDate(beginBalanceDate) && incomes[i].getDate() <=  dateManager.convertStringDateToIntDate(endBalanceDate)) {
                displayDataIncome(incomes[i]);
                sumOfIncomes += incomes[i].getAmount();
            }
        }
    }
    if(sumOfIncomes == 0) {
        cout << " BRAK PRZYCHODOW." << endl << endl;
    }
}

void FinanceManager::displayBudgetBalanceForThePeriod() {
    float sumOfIncomes = 0;
    float sumOfExpenses = 0;
    string beginBalanceDate = enterBeginBalanceDate();
    string endBalanceDate = enterEndBalanceDate();

    system("cls");
    cout << "    >>> BILANS PRZYCHODOW / WYDATKOW <<<" << endl;
    cout << "-----------------------------------------------" << endl << endl;
    displayAndCalculateIncomesForThePeriod(sumOfIncomes, beginBalanceDate, endBalanceDate);
    cout << "-----------------------------------------------" << endl << endl;
    displayAndCalculateExpensesForThePeriod(sumOfExpenses, beginBalanceDate, endBalanceDate);
    cout << "-----------------------------------------------" << endl << endl;
    displayBalance(sumOfIncomes, sumOfExpenses);
    cout << "-----------------------------------------------" << endl;
    system("pause");
}

void FinanceManager::displayBudgetBalanceForTheMonth(int yearOfTheBalanceMonth, int monthBalance) {
    float sumOfIncomes = 0;
    float sumOfExpenses = 0;

    system("cls");
    cout << "    >>> BILANS PRZYCHODOW / WYDATKOW <<<" << endl;
    cout << "-----------------------------------------------" << endl << endl;
    displayAndCalculateIncomesForTheMonth(sumOfIncomes, yearOfTheBalanceMonth, monthBalance);
    cout << "-----------------------------------------------" << endl << endl;
    displayAndCalculateExpensesForTheMonth(sumOfExpenses, yearOfTheBalanceMonth, monthBalance);
    cout << "-----------------------------------------------" << endl << endl;
    displayBalance(sumOfIncomes, sumOfExpenses);
    cout << "-----------------------------------------------" << endl;
    system("pause");
}

void FinanceManager::displayBudgetBalanceForTheCurrentMonth() {
    int yearOfTheBalanceMonth = dateManager.getCurrentYear();
    int monthBalance = dateManager.getCurrentMonth();

    displayBudgetBalanceForTheMonth(yearOfTheBalanceMonth, monthBalance);
}

void FinanceManager::displayBudgetBalanceForThePreviousMonth() {
    int yearOfTheBalanceMonth = 0;
    int monthBalance = 0;

    if(dateManager.getCurrentMonth() == 1) {
        yearOfTheBalanceMonth = dateManager.getCurrentYear() - 1;
        monthBalance = 12;
    } else {
        yearOfTheBalanceMonth = dateManager.getCurrentYear();
        monthBalance = dateManager.getCurrentMonth() - 1;
    }

    displayBudgetBalanceForTheMonth(yearOfTheBalanceMonth, monthBalance);
}

void FinanceManager::addExpense() {
    Expense expense = provideDataOfNewExpense();

    expenses.push_back(expense);
    fileWithExpenses.addExpenseToFile(expense);

    cout << endl << "Nowy wydatek zostal dodany" << endl << endl;
    system("pause");
}

Expense FinanceManager::provideDataOfNewExpense() {
    Expense expense;
    char choiceCharacter;

    expense.setExpenseId(getNewExpenseId());
    expense.setUserId(LOGGED_USER_ID);

    string date = "";
    cout << "Czy chcesz wprowadzic wydatek z dzisiejsza data? ('t'- tak, 'n'- nie): ";
    choiceCharacter = AuxiliaryMethods::loadCharacter();
    if (choiceCharacter == 't') {
        expense.setDate(dateManager.getTodaysDateInIntFormat());
    } else {
        do {
            cout << "Wprowadz date wydatku (format rrrr-mm-dd): ";
            date = AuxiliaryMethods::loadLine();
            if (!dateManager.isDateCorrect(date)) {
                cout << "Data nieprawidlowa. Poprawny format daty: rrrr-mm-dd. Zakres daty od 2000-01-01 do ostatniego dnia biezacego miesiaca." << endl;
                system("pause");
            }
        } while (!dateManager.isDateCorrect(date));
        expense.setDate(dateManager.convertStringDateToIntDate(date));
    }

    string item;
    cout << "Wprowadz typ wydatku: ";
    item = AuxiliaryMethods::loadLine();
    expense.setItem(item);

    string amount;
    do {
        cout << "Jaka jest wartosc wydatku? : ";
        cin >> amount;
        AuxiliaryMethods::replaceCommasWithPeriods(amount);
        if (AuxiliaryMethods::convertStringToFloat(amount) <= 0) {
            cout << "Wydatek musi byc liczba wieksza od 0!" << endl;
            system("pause");
        }
    } while (AuxiliaryMethods::convertStringToFloat(amount) <= 0);
    expense.setAmount(AuxiliaryMethods::convertStringToFloat(amount));
    return expense;
}

int FinanceManager::getNewExpenseId() {
    int newExpenseId = fileWithExpenses.getLastExpenseId() + 1;

    return newExpenseId;
}

void FinanceManager::addIncome() {
    Income income = provideDataOfNewIncome();

    incomes.push_back(income);
    fileWithIncomes.addIncomeToFile(income);

    cout << endl << "Nowy przychod zostal dodany" << endl << endl;
    system("pause");
}

Income FinanceManager::provideDataOfNewIncome() {
    Income income;
    char choiceCharacter;

    income.setIncomeId(getNewIncomeId());
    income.setUserId(LOGGED_USER_ID);

    string date = "";
    cout << "Czy chcesz wprowadzic przychod z dzisiejsza data? ('t'- tak, 'n'- nie): ";
    choiceCharacter = AuxiliaryMethods::loadCharacter();
    if (choiceCharacter == 't') {
        income.setDate(dateManager.getTodaysDateInIntFormat());
    } else {
        do {
            cout << "Wprowadz date przychodu (format rrrr-mm-dd): ";
            date = AuxiliaryMethods::loadLine();
            if (!dateManager.isDateCorrect(date)) {
                cout << "Data nieprawidlowa. Poprawny format daty: rrrr-mm-dd. Zakres daty od 2000-01-01 do ostatniego dnia biezacego miesiaca." << endl;
                system("pause");
            }
        } while (!dateManager.isDateCorrect(date));
        income.setDate(dateManager.convertStringDateToIntDate(date));
    }

    string item;
    cout << "Wprowadz typ przychodu: ";
    item = AuxiliaryMethods::loadLine();
    income.setItem(item);

    string amount;
    do {
        cout << "Jaka jest wartosc przychodu? : ";
        cin >> amount;
        AuxiliaryMethods::replaceCommasWithPeriods(amount);
        if (AuxiliaryMethods::convertStringToFloat(amount) <= 0) {
            cout << "Przychod musi byc liczba wieksza od 0!" << endl;
            system("pause");
        }
    } while (AuxiliaryMethods::convertStringToFloat(amount) <= 0);
    income.setAmount(AuxiliaryMethods::convertStringToFloat(amount));
    return income;
}

int FinanceManager::getNewIncomeId() {
    int newIncomeId = fileWithIncomes.getLastIncomeId() + 1;

    return newIncomeId;
}

