#include<iostream>
using namespace std;

class Date{
	public:
		int day,month,year;
		
		void displayDate(){
			cout<<day<<"/"<<month<<"/"<<year;
			return;
		}
	
};

int main(int argc, char* argv[]){
	Date DateTest;
	DateTest.day=1;
	DateTest.month=1;
	DateTest.year=25;
	cout<<"date: ";
	DateTest.displayDate();
	
	return 0;
	
}