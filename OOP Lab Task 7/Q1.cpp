#include<iostream>
using namespace std;

class Account{
protected:
    int accountNumber;
    double balance;
    string accountHolderName;

public:
    Account(int accNum, double bal, string name)
        : accountNumber(accNum), balance(bal), accountHolderName(name){}

    virtual void deposit(double amount){
        balance += amount;
        cout<<"Deposited: "<<amount<<" | New Balance: "<<balance<<endl;
    }
    
    virtual void withdraw(double amount) {
        if (balance >= amount){
            balance -= amount;
            cout<<"Withdrawn: "<<amount<<" | New Balance: "<<balance<<endl;
        }else{
            cout << "Insufficient balance!" << endl;
        }
    }

    virtual void calculateInterest() = 0; 

    void printStatement() {
        cout<<"Account Holder: "<<accountHolderName<<" | Balance: "<<balance<<endl;
    }
};

class SavingsAccount : public Account{
    double interestRate;

public:
    SavingsAccount(int accNum, double bal, string name, double rate)
        : Account(accNum, bal, name), interestRate(rate) {}

    void calculateInterest() override{
        double interest = balance * (interestRate / 100);
        balance += interest;
        cout<<"Interest Added: "<<interest<<" | New Balance: "<<balance<<endl;
    }
};

class FixedDepositAccount : public Account{
    double fixedInterestRate;
    int maturityDate;

public:
    FixedDepositAccount(int accNum, double bal, string name, double rate, int maturity)
        : Account(accNum, bal, name), fixedInterestRate(rate), maturityDate(maturity) {}

    void calculateInterest() override{
        double interest = balance * (fixedInterestRate / 100);
        cout << "Fixed Deposit Interest: " << interest << endl;
    }
};

int main(){
    SavingsAccount savings(101, 5000, "John Doe", 5.0);
    FixedDepositAccount fixed(102, 10000, "Jane Doe", 6.5, 12);

    savings.deposit(1000);
    savings.withdraw(2000);
    savings.calculateInterest();
    savings.printStatement();

    fixed.calculateInterest();
    fixed.printStatement();

    return 0;
}

