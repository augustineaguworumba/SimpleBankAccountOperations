#ifndef _CHECKING_ACCOUNT_H_
#define _CHECKING_ACCOUNT_H_
#include <iostream>
#include "Account.h"
#include <string>

using namespace std;

// Checking Account is a type of Account that has a fee of $1.50 for every withdrawal transaction.
// Deposit - same as a regular account
// Withdrawal:
//      Amount supplied to withdrawal will be decremented by (amount += 1.50) 
//      and then the updated amount will be returned
//

class Checking_Account: public Account {
private:
    static constexpr const char *def_name = "Unnamed Checking Account";
    static constexpr double def_balance = 0.0;
    static constexpr double def_withdrawal_fee = 1.50;
public:
    Checking_Account(string name = def_name, double balance =def_balance);
    virtual bool withdraw(double) override;
    virtual bool deposit(double) override;
    virtual void print(ostream &os) const override;
    
    virtual ~Checking_Account() = default;
};

#endif // _CHECKING_ACCOUNT_H_