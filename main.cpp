#include <iostream>

#include "FinanceManagement.h"

using namespace std;


int main() {
    FinanceManagement financeManagement("users.xml", "incomes.xml", "expenses.xml");
    char choice;

    while (true) {
        if (!financeManagement.isLogged()) {
            choice = financeManagement.selectOptionFromLoginMenu();

            switch (choice) {
            case '1':
                financeManagement.userRegistration();
                break;
            case '2':
                financeManagement.userLogin();
                break;
            case '9':
                exit(0);
                break;
            default:
                cout << endl << "Nie ma takiej opcji w menu." << endl << endl;
                system("pause");
                break;
            }
        } else {
            choice = financeManagement.selectOptionFromMainMenu();

            switch (choice) {
            case '1':
                financeManagement.addIncome();
                break;
            case '2':
                financeManagement.addExpense();
                break;
            case '3':
                financeManagement.displayBudgetBalanceForTheCurrentMonth();
                break;
            case '4':
                financeManagement.displayBudgetBalanceForThePreviousMonth();
                break;
            case '5':
                financeManagement.displayBudgetBalanceForThePeriod();
                break;
            case '6':
                financeManagement.changePasswordLoggedUser();
                break;
            case '7':
                financeManagement.logOutUser();
                break;
            }
        }
    }
    return 0;
}

