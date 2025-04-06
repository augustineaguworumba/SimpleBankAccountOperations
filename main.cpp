#include <iostream>
#include "Account.h"
#include "Savings_Account.h"
#include "Checking_Account.h"
#include "Trust_Account.h"
#include "Account_Util.h"
#include <vector>

using namespace std;

int main() {
    /*
    // Account frank{"Frank", 5000};         // should not compile
    // cout << frank << endl;

    Checking_Account frank {"Frank", 5000};
    cout << frank << endl;
    
    Account *trust = new Trust_Account("James");
    cout << *trust << endl;
    
    Account *p1 = new Checking_Account("Larry", 10000);
    Account *p2 = new Savings_Account("Moe", 1000);
    Account *p3 = new Trust_Account("Curly");
    
    std::vector<Account *> accounts {p1,p2,p3};
    
    display(accounts);
    deposit(accounts, 1000);
    withdraw(accounts, 2000);
    
    display(accounts);
    
    delete p1;
    delete p2;
    delete p3;
    */
    
    // test your code here
    std::unique_ptr<Account> moes_account;
    std::unique_ptr<Account> larrys_account;
    try {
        larrys_account = std::make_unique<Savings_Account>("Larry", -2000.0);
        std::cout << *larrys_account << std::endl;
    }
    catch (const IllegalBalanceException &ex)
    {
        std::cerr << ex.what() << std::endl;
    }

    try {
        moes_account = std::make_unique<Savings_Account>("Moe", 1000.0);
        std::cout << *moes_account << std::endl;
        moes_account->withdraw(500.0);
        std::cout << *moes_account << std::endl;
        moes_account->withdraw(1000.0);
        std::cout << *moes_account << std::endl;
    }
    
    catch (const IllegalBalanceException &ex) {
        std::cerr << ex.what() << std::endl;
    }
    
    catch (const InsufficientFundsException &ex) {
        std::cerr << ex.what() << std::endl;
    }
    
    std::cout << "Program completed successfully" << std::endl;
    
    return 0;
}