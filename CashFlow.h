#ifndef CASH_FLOW_H
#define CASH_FLOW_H

#include <iostream>

using namespace std;


class CashFlow {

    int userId;
    int date;
    float amount;
    string item;

public:

    CashFlow(int userId = 0, int date = 0, float amount = 0, string item = "") {
        this -> userId = userId;
        this -> date = date;
        this -> amount = amount;
        this -> item = item;
    }

    void setUserId(int newUserId);
    void setDate(int newDate);
    void setAmount(float newAmount);
    void setItem(string newItem);

    int getUserId();
    int getDate();
    float getAmount();
    string getItem();
};


#endif
