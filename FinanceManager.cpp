#include "FinanceManager.h"


void FinanceManager::displayBudgetBalanceForTheCurrentMonth() {
    for(int i = 0; i < incomes.size(); ++i) {
        cout << "incomeId: " <<incomes[i].getIncomeId() << endl;
        cout << "userId: " <<incomes[i].getUserId() << endl;
        cout << "date: " <<incomes[i].getDate() << endl;
        cout << "amount: " <<incomes[i].getAmount() << endl;
        cout << "item: " <<incomes[i].getItem() << endl << endl;
    }
    system("pause");
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

