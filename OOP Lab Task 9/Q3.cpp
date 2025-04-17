#include<iostream>
#include<string>
using namespace std;

class Person{
protected:
    string name;
    int age;

public:
    virtual void getData() 
        cout << "Enter name: ";
        cin >> name;
        cout << "Enter age: ";
        cin >> age;
    }
    virtual void displayData(){
        cout << "Name: " << name << "\nAge: " << age << endl;
    }
    virtual void bonus() = 0;
    virtual ~Person() {}
};

class Admin : public Person{
protected:
    double salary;

public:
    void getData() override{
        Person::getData();
        cout << "Enter salary: ";
        cin >> salary;
    }
    void displayData() override{
        Person::displayData();
        cout << "Salary: " << salary << endl;
    }
    void bonus() override{
        cout << "Admin Bonus: " << salary * 0.1 << endl;
    }
};

class Account : public Person{
protected:
    double salary;
public:
    void getData() override{
        Person::getData();
        cout << "Enter salary: ";
        cin >> salary;
    }

    void displayData() override{
        Person::displayData();
        cout << "Salary: " << salary << endl;
    }

    void bonus() override{
        cout << "Account Bonus: " << salary * 0.15 << endl;
    }
};

class Master : public Admin, public Account{
    double salary;

public:
    void getData() override{
        Admin::getData();
        Account::getData();
    }

    void displayData() override{
        Admin::displayData();
        Account::displayData();
    }

    void bonus() override{
        cout << "Master Bonus: " <<salary*0.2<< endl;
    }
};

int main(){
    Person* p;
    Admin admin;
    Account account;
    Master master;

    p = &admin;
    p->getData();
    p->displayData();
    p->bonus();

    p = &account;
    p->getData();
    p->displayData();
    p->bonus();

    p = &master;
    p->getData();
    p->displayData();
    p->bonus();

    return 0;
}

