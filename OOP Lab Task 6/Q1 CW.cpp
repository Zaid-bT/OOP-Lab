#include<iostream>
using namespace std;

class BankAccount{
	string accNum;
	float balance;
	
	public:
		BankAccount(string acc,float b){
			accNum = acc;
			balance = b;
		}
		void withdraw(float num){
			balance -= num;
			cout<<"new account balance: "<< balance<<endl;
		}
		
		void deposit(float num){
			balance += num;
			cout<<"new account balance: "<< balance<<endl;
		}
		
		string getAccountNumber(){
			return accNum;
		}
		
		float getBalance(){
			return balance;
		}
		
		void setBalance(int num){
			balance = num;
		}
};

class SavingsAccount : public BankAccount{
	float monthInterest;
	
	public:
		SavingsAccount(float interest, string acc, float b){
			monthInterest=interest;
			BankAccount(acc,b);
		}
		
		float applyInterest(){
			float newBalance = getBalance()+monthInterest;
			return newBalance;
		}
		
		float getInterest(){
			return monthInterest;
		}
};


class CheckingAccount : public BankAccount{
	int limit;
	
	public:
		CheckingAccount(int lim, string acc, float b){
			limit = lim;
			BankAccount(acc,b);
		}
		
		void checkOverDraft(){
			float newBalance = getBalance();
			if(newBalance < limit){
				cout<< "Overdrafts exceeds limit!!!\n";
			}
		}
};

class BussinessAccount : public BankAccount{
	float corporateTax;
	float deposit;
	
	public:
		BussinessAccount(float tax,float d, string acc, float b){
			corporateTax = tax;
			deposit = d;
			BankAccount(acc,b);
		}
		
		void applyCorpTax(){
			float newBalance = deposit - corporateTax;
			setBalance(newBalance);
		}
};






