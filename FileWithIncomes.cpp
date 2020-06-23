#include "FileWithIncomes.h"


int FileWithIncomes::getLastIncomeId() {
    return lastIncomeId;
}

int FileWithIncomes::getLastIncomeIdFromFile() {
    int lastIncomeIdFromFile = 0;

    if(fileExists()) {
        findElement("Incomes");
        intoElement();

        while (elementExists("Income")) {
            findChildElement("IncomeId");
            lastIncomeIdFromFile = AuxiliaryMethods::convertStringToInt(getChildData());
        }
    }

    return lastIncomeIdFromFile;
}

void FileWithIncomes::addIncomeToFile(Income income) {
    DateManager dateManager;

    if(!fileExists()) {
        addElement("Incomes");
    }
    findElement();
    intoElement();
    addElement("Income");
    intoElement();
    addElement("IncomeId", income.getIncomeId());
    addElement("UserId", income.getUserId());
    addElement("Date", dateManager.convertIntDateToStringDate(income.getDate()));
    addElement("Item", income.getItem());
    addElement("Amount", AuxiliaryMethods::convertFloatToString(income.getAmount()));

    saveFile();
    lastIncomeId++;
}

Income FileWithIncomes::getIncomeDataFromFileToConstructor() {
    Income income;
    DateManager dateManager;

    resetChildPosition();
    findChildElement("IncomeId");
    income.setIncomeId(AuxiliaryMethods::convertStringToInt(getChildData()));
    findChildElement("UserId");
    income.setUserId(AuxiliaryMethods::convertStringToInt(getChildData()));
    findChildElement("Date");
    income.setDate(dateManager.convertStringDateToIntDate(getChildData()));
    findChildElement("Item");
    income.setItem(getChildData());
    findChildElement("Amount");
    income.setAmount(AuxiliaryMethods::convertStringToFloat(getChildData()));

    return income;
}

vector<Income> FileWithIncomes::loadIncomesOfLoggedUserFromFile(int loggedUserId) {
    Income income;
    vector <Income> incomes;
    string incomeIDString;

    if(fileExists()) {
        resetPosition();
        findElement("Incomes");
        intoElement();

        while (elementExists("Income")) {
               findChildElement("IncomeId");
               incomeIDString = getChildData();
                findChildElement("UserId");
            if (getChildData() == AuxiliaryMethods::convertIntToString(loggedUserId)) {
                income = getIncomeDataFromFileToConstructor();
                incomes.push_back(income);
            }
        }
    }

    return incomes;
}

