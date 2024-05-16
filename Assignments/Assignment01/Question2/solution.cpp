#include <iostream>
using namespace std;
class Account {
protected:
    double balance;
public:
    Account(double initial_balance) {
        if (initial_balance >= 0.0) {
            balance = initial_balance;
        } else {
            balance = 0.0;
            cout << "Initial balance cannot be negative. Balance set to 0.0." << endl;
        }
    }

    void credit(double amount) {
        balance += amount;
    }

    bool debit(double amount) {
        if (amount <= balance) {
            balance -= amount;
            return true; 
        } else {
            cout << "Debit amount exceeded account balance." << endl;
            return false; 
        }
    }

    double getBalance() const {
        return balance;
    }
};

class SavingsAccount : public Account {
private:
    double interest;

public:
    SavingsAccount(double initial_balance, double interest)
        : Account(initial_balance), interest(interest) {}

    double calculateInterest() const {
        return balance * interest;
    }
};

class CheckingAccount : public Account {
private:
    double transactionFee;

public:
    CheckingAccount(double initial_balance, double transactionFee)
        : Account(initial_balance), transactionFee(transactionFee) {}

    void credit(double amount) {
        balance += amount - transactionFee;
    }

    bool debit(double amount) {
        if (Account::debit(amount)) { 
            balance -= transactionFee;
            return true; 
        } else {
            return false; 
        }
    }
};

int main() {

    Account acc(100.0);
    cout << "Account balance: " << acc.getBalance() << endl;
    acc.credit(50.0);
    cout << "Account balance after credit: " << acc.getBalance() << endl;
    acc.debit(30.0);
    cout << "Account balance after debit: " << acc.getBalance() << endl;

    SavingsAccount savingsAccount(500.0, 0.05); 
    double interest = savingsAccount.calculateInterest();
    savingsAccount.credit(interest); 
    cout << "Savings account balance after adding interest: " << savingsAccount.getBalance() << endl;

    CheckingAccount checkingAccount(200.0, 2.0);
    checkingAccount.debit(50.0);
    cout << "Checking account balance after debit: " << checkingAccount.getBalance() << endl;

    return 0;
}
