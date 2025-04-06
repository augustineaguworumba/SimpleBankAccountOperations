#include <iostream>
#include <cstring>
#include "Checking_Account.h"

using namespace std;

Checking_Account::Checking_Account(string name, double balance)
    : Account {name, balance} {
    }
    //try : Account {name, balance} {
    //}
    //catch (...) {
    //    ;
    //}

// Withdrawal:
//      Amount supplied to withdrawal will be decremented by (amount -= 1.50)
//      and then the updated amount will be withdrawn

bool Checking_Account::withdraw(double amount) {
    amount += def_withdrawal_fee;
    return Account::withdraw(amount);
}

bool Checking_Account::deposit(double amount) {
    return Account::deposit(amount);
}

void Checking_Account::print(ostream &os) const{
    os.precision(2);
    os << fixed;
    os << "[Checking_Account:" << name << ":"  << balance << "]";
}
