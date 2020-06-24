#ifndef INCOME_H
#define INCOME_H

#include <iostream>
#include "CashFlow.h"
#include<algorithm>

using namespace std;


class Income: public CashFlow {

    int incomeId;

public:

    Income(int incomeId = 0, int userId = 0, int date = 0, float amount = 0, string item = "")
        :CashFlow(userId, date, amount, item) {
        this -> incomeId = incomeId;
    }

    void setIncomeId(int newId);
    int getIncomeId();
};


#endif
