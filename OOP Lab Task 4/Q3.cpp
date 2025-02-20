#include<iostream>
using namespace std;


class Invoice{
	string number,description;
	int quantity;
	double price;
	
	
	public:
		Invoice();
		
		Invoice(string n, string d, int q, double p){
			number=n;
			description=d;
			quantity=q;
			price=p;
			if(p<0){
				price=0.0;
			}
			if(q<0){
				quantity=0;
			}
		}
		
		double getInvoiceAmount(){
			return quantity*price;
		}
		
};

int main(int argc, char* argv[]){
	Invoice invoice1("1111","Bolt",4,2.2);
	cout<<"Total price: "<<invoice1.getInvoiceAmount()<<endl;
}
