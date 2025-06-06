#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Employee {
protected:
    int id;
    string name;
public:
    Employee(int i, const string& n) : id(i), name(n) {}
    virtual void display() {
        cout << "ID: " << id << ", Name: " << name << endl;
    }
    virtual ~Employee() {}
};

class IOrderTaker {
public:
    virtual void takeOrder() = 0;
    virtual ~IOrderTaker() {}
};

class IOrderPreparer {
public:
    virtual void prepareOrder() = 0;
    virtual ~IOrderPreparer() {}
};

class IBiller {
public:
    virtual void generateBill() = 0;
    virtual ~IBiller() {}
};

class Waiter : public Employee, public IOrderTaker {
public:
    Waiter(int i, const string& n) : Employee(i, n) {}
    void takeOrder() override {
        cout << name << " is taking the order." << endl;
    }
};

class Chef : public Employee, public IOrderPreparer {
public:
    Chef(int i, const string& n) : Employee(i, n) {}
    void prepareOrder() override {
        cout << name << " is preparing the food." << endl;
    }
};

class Cashier : public Employee, public IBiller {
public:
    Cashier(int i, const string& n) : Employee(i, n) {}
    void generateBill() override {
        cout << name << " is generating the bill." << endl;
    }
};

class Manager : public Employee, public IOrderTaker, public IBiller {
public:
    Manager(int i, const string& n) : Employee(i, n) {}
    void takeOrder() override {
        cout << name << " is taking the order as a manager." << endl;
    }
    void generateBill() override {
        cout << name << " is generating the bill as a manager." << endl;
    }
};

class Menu {
public:
    virtual double calculateTotal() = 0;
    virtual ~Menu() {}
};

class FoodMenu : public Menu {
public:
    double calculateTotal() override {
        return 100.0;
    }
};

class BeverageMenu : public Menu {
public:
    double calculateTotal() override {
        return 50.0 * 1.1;
    }
};

int main() {
    vector<IOrderTaker*> orderTakers;
    vector<IBiller*> billers;
    vector<Employee*> allEmployees;

    Waiter w(1, "Alice");
    Chef c(2, "Bob");
    Cashier cs(3, "Charlie");
    Manager m(4, "Dana");

    orderTakers.push_back(&w);
    orderTakers.push_back(&m);
    billers.push_back(&cs);
    billers.push_back(&m);

    allEmployees.push_back(&w);
    allEmployees.push_back(&c);
    allEmployees.push_back(&cs);
    allEmployees.push_back(&m);

    for (auto e : allEmployees) {
        e->display();
    }

    for (auto o : orderTakers) {
        o->takeOrder();
    }

    for (auto b : billers) {
        b->generateBill();
    }

    FoodMenu fm;
    BeverageMenu bm;
    cout << "Food total: " << fm.calculateTotal() << endl;
    cout << "Beverage total: " << bm.calculateTotal() << endl;

    return 0;
}

