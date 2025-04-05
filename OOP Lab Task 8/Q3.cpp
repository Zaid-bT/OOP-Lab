#include<iostream>
#include<string>
using namespace std;



class Person{
protected:
    int employeeID;
public:
    void getData(int id){
        employeeID = id;
    }

    void displayData() const{
        cout<<"Employee ID: "<<employeeID<<endl;
    }
};

class Admin : public Person{
    string name;
    double monthlyIncome;
public:
    void getData(int id, const string& empName, double income){
        Person::getData(id);
        name = empName;
        monthlyIncome = income;
    }
    void displayData() const{
        Person::displayData();
        cout << "Name: " << name<<endl;
        cout << "Monthly Income: "<<monthlyIncome<<endl;
        cout << "Bonus: " <<bonus()<<endl;
    }
    double bonus() const{
        return monthlyIncome*12*0.05;
    }
};

class Accounts : public Person{
    string name;
    double monthlyIncome;
public:
    void getData(int id, const string& empName, double income){
        Person::getData(id);
        name = empName;
        monthlyIncome = income;
    }
    void displayData() const{
        Person::displayData();
        cout << "Name: " << name<<endl;
        cout << "Monthly Income: " << monthlyIncome<<endl;
        cout << "Bonus: " << bonus()<<endl;
    }

    double bonus() const{
        return monthlyIncome*12*0.05;
    }
};

int main(int argc, char* argv[]){
    Admin admin1, admin2;
    Accounts acc1, acc2;

    admin1.getData(101, "Alice Johnson", 3000);
    admin2.getData(102, "Bob Smith", 3500);

    acc1.getData(201, "Charlie Brown", 4000);
    acc2.getData(202, "Diana Ross", 4500);

    cout << "\nEmployee Details (Admin Department):" << endl;
    admin1.displayData();
    admin2.displayData();

    cout << "\nEmployee Details (Accounts Department):" << endl;
    acc1.displayData();
    acc2.displayData();



    return 0;
}

