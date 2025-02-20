#include<iostream>
using namespace std;


class Account{
	float balance;
	
	public:
		void addAmount(float amount){
			balance+=amount;
			cout<<amount<<" added in account successfully"<<endl;
		}
		void withdraw(float amount){
			balance-=amount;
			cout<<amount<<" withdrawn from account"<<endl;
		}
		float getBalance(){
			return balance;
		}
};


int main(int argc, char* argv[]){
	Account acc1;
	acc1.addAmount(200);
	acc1.withdraw(100);
	cout<<"Bank balance: "<<acc1.getBalance();
	
	
	return 0;
}
