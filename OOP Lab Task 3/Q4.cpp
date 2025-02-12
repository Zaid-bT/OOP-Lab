#include<iostream>
using namespace std;


class Employee{
	public:
		string F_name,L_name;
		double salary;
		
		void checkSalary(){
			if(salary<0.0){
				salary=0.0;
			}	
		}
		
		void yearlySalary(){
			cout<<"Yearly salary of "<<F_name<<" "<<L_name<<": "<<salary*12<<endl;
		}
		
		void Increment(){
			salary=salary+(salary*0.1);
		//	cout<<salary;
			yearlySalary();
		}
};

int main(int argc,char* argv[]){
	Employee emp1;
	Employee emp2;
	
	emp1.F_name="John";
	emp1.L_name="Smith";
	cout<<"Enter monthly salary of "<<emp1.F_name<<" "<<emp1.L_name<<" : ";
	cin>>emp1.salary;
	emp1.checkSalary();
	emp1.yearlySalary();
	
	emp2.F_name="David";
	emp2.L_name="Blaine";
	cout<<"Enter monthly salary of "<<emp2.F_name<<" "<<emp2.L_name<<" : ";
	cin>>emp2.salary;
	emp2.checkSalary();
	emp2.yearlySalary();
	
	cout<<"\n10% salary raise to both employees!!!\n";
	emp1.Increment();
	emp2.Increment();
	
//	cout<<"New Yearly Salary of Employee 1: "<<emp1.salary*12;
//	cout<<"New Yearly Salary of Employee 2: "<<emp2.salary*12;
}
