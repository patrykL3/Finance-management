#include"CashFlow.h"


void CashFlow::setUserId(int newUserId) {
    if (newUserId >= 0)
        userId = newUserId;
}

void CashFlow::setDate(int newDate) {
    date = newDate;
}

void CashFlow::setAmount(float newAmount) {
    amount = newAmount;
}

void CashFlow::setItem(string newItem) {
    item = newItem;
}

int CashFlow::getUserId() {
    return userId;
}

int CashFlow::getDate() {
    return date;
}

float CashFlow::getAmount() {
    return amount;
}

string CashFlow::getItem() {
    return item;
}

