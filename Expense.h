#ifndef EXPENSE_H
#define EXPENSE_H

#include <iostream>
#include "CashFlow.h"

using namespace std;


class Expense: public CashFlow {

    int expenseId;

public:

    Expense(int expenseId = 0, int userId = 0, int date = 0, float amount = 0, string item = "")
    :CashFlow(userId, date, amount, item) {
        this -> expenseId = expenseId;
    }

    void setExpenseId(int newExpenseId);
    int getExpenseId();
};


#endif
