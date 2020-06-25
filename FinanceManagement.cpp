#include "FinanceManagement.h"


void FinanceManagement::addIncome() {
    financeManager -> addIncome();
}

void FinanceManagement::addExpense() {
    financeManager -> addExpense();
}

void FinanceManagement::displayBudgetBalanceForTheCurrentMonth() {
    financeManager -> displayBudgetBalanceForTheCurrentMonth();

}

void FinanceManagement::displayBudgetBalanceForThePreviousMonth() {
   financeManager -> displayBudgetBalanceForThePreviousMonth();

}

void FinanceManagement::displayBudgetBalanceForThePeriod() {
    financeManager -> displayBudgetBalanceForThePeriod();

}

void FinanceManagement::changePasswordLoggedUser() {
    userManager.changePasswordLoggedUser();
}

void FinanceManagement::logOutUser() {
    userManager.logOutUser();
    delete financeManager;
    financeManager = NULL;
}

char FinanceManagement::selectOptionFromMainMenu() {
    char choice;

    system("cls");
    cout << " >>> MENU GLOWNE <<<" << endl;
    cout << "---------------------------" << endl;
    cout << "1. Dodaj przychod" << endl;
    cout << "2. Dodaj wydatek" << endl;
    cout << "3. Bilans z biezacego miesiaca" << endl;
    cout << "4. Bilans z poprzedniego miesiaca" << endl;
    cout << "5. Bilans z wybranego okresu" << endl;
    cout << "---------------------------" << endl;
    cout << "6. Zmien haslo" << endl;
    cout << "7. Wyloguj sie" << endl;
    cout << "---------------------------" << endl;
    cout << "Twoj wybor: ";
    choice = AuxiliaryMethods::loadCharacter();

    return choice;
}

void FinanceManagement::userRegistration() {
    userManager.userRegistration();
}

void FinanceManagement::userLogin() {
    userManager.userLogin();
    if (userManager.isLogged())
        financeManager = new FinanceManager(FILE_NAME_WITH_INCOMES, userManager.getIdLoggedUser(), FILE_NAME_WITH_EXPENSES);
}

bool FinanceManagement::isLogged() {
    if(userManager.getIdLoggedUser() == 0)
        return false;
    else
        return true;
}

char FinanceManagement::selectOptionFromLoginMenu() {
    char choice;

    system("cls");
    cout << ">>> MENU LOGOWANIA <<<" << endl;
    cout << "---------------------------" << endl;
    cout << "1. Rejestracja" << endl;
    cout << "2. Logowanie" << endl;
    cout << "9. Koniec programu" << endl;
    cout << "---------------------------" << endl;
    cout << "Twoj wybor: ";
    choice = AuxiliaryMethods::loadCharacter();

    return choice;
}

