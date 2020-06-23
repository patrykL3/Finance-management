#include "FileWithExpenses.h"


int FileWithExpenses::getLastExpenseId() {
    return lastExpenseId;
}

int FileWithExpenses::getLastExpenseIdFromFile() {
    int lastExpenseIdFromFile = 0;

    if(fileExists()) {
        findElement("Expenses");
        intoElement();

        while (elementExists("Expense")) {
            findChildElement("ExpenseId");
            lastExpenseIdFromFile = AuxiliaryMethods::convertStringToInt(getChildData());
        }
    }

    return lastExpenseIdFromFile;
}

void FileWithExpenses::addExpenseToFile(Expense expense) {
    DateManager dateManager;

    if(!fileExists()) {
        addElement("Expenses");
    }
    findElement();
    intoElement();
    addElement("Expense");
    intoElement();
    addElement("ExpenseId", expense.getExpenseId());
    addElement("UserId", expense.getUserId());
    addElement("Date", dateManager.convertIntDateToStringDate(expense.getDate()));
    addElement("Item", expense.getItem());
    addElement("Amount", AuxiliaryMethods::convertFloatToString(expense.getAmount()));

    saveFile();
    lastExpenseId++;
}

Expense FileWithExpenses::getExpenseDataFromFileToConstructor() {
    Expense expense;
    DateManager dateManager;

    resetChildPosition();
    findChildElement("ExpenseId");
    expense.setExpenseId(AuxiliaryMethods::convertStringToInt(getChildData()));
    findChildElement("UserId");
    expense.setUserId(AuxiliaryMethods::convertStringToInt(getChildData()));
    findChildElement("Date");
    expense.setDate(dateManager.convertStringDateToIntDate(getChildData()));
    findChildElement("Item");
    expense.setItem(getChildData());
    findChildElement("Amount");
    expense.setAmount(AuxiliaryMethods::convertStringToFloat(getChildData()));

    return expense;
}

vector<Expense> FileWithExpenses::loadExpensesOfLoggedUserFromFile(int loggedUserId) {
    Expense expense;
    vector <Expense> expenses;
    string expenseIDString;

    if(fileExists()) {
        resetPosition();
        findElement("Expenses");
        intoElement();

        while (elementExists("Expense")) {
               findChildElement("ExpenseId");
               expenseIDString = getChildData();
                findChildElement("UserId");
            if (getChildData() == AuxiliaryMethods::convertIntToString(loggedUserId)) {
                expense = getExpenseDataFromFileToConstructor();
                expenses.push_back(expense);
            }
        }
    }

    return expenses;
}

