
#include <iostream>
using namespace std;

struct Employee{
	string emp_id;
	string emp_name;
	int emp_salary;
}emp;

struct Organisation{
	string org_name;
	int org_number;
	Employee emp;
}org1;

int main(int argc, char* argv[]){
//	org org1;
//	emp emp1;
	
	cout<<"organisation name: ";
	cin>>org1.org_name;
	cout<<"organisation number: ";
	cin>>org1.org_number;
	cout<<"employee name: ";
	cin>>org1.emp.emp_name;
	cout<<"employee id: ";
	cin>>org1.emp.emp_id;
	cout<<"employee salary: ";
	cin>>org1.emp.emp_salary;
	
	cout<<"organisation name: "<<org1.org_name<<endl;
	cout<<"organisation number: "<<org1.org_number<<endl;
	cout<<"employee name: "<<org1.emp.emp_name<<endl;
	cout<<"employee id: "<<org1.emp.emp_id<<endl;
	cout<<"employee salary: "<<org1.emp.emp_salary<<endl;
	
	
	return 0;
}

