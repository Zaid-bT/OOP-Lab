#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Payment;
class Route;
class Stop;
class Bus;
class Person;

class Person{
protected:
    string name;
    int ID;
    string cardNumber;
    bool paymentStatus;

public:
    Person(string name, int ID, string cardNumber) 
        : name(name), ID(ID), cardNumber(cardNumber), paymentStatus(false) {}

    virtual void payFees(Payment &payment) = 0;
    void showDetails(){
        cout<<"ID: "<<ID << ", Name: " << name << ", Card Number: " << cardNumber << ", Payment Status: " << (paymentStatus ? "Paid" : "Not Paid") << endl;
    }

    bool getPaymentStatus(){
        return paymentStatus;
    }

    string getName(){
        return name;
    }

    int getID(){
        return ID;
    }
};

class Student : public Person{
public:
    Student(string name, int ID, string cardNumber) 
        : Person(name, ID, cardNumber) {}

    void payFees(Payment &payment) override{
        payment.processPayment();
        paymentStatus = true;
        cout<<"Student "<<name<<" has paid semester fees."<<endl;
    }
};

class Teacher : public Person{
public:
    Teacher(string name, int ID, string cardNumber) 
        : Person(name, ID, cardNumber) {}

    void payFees(Payment &payment) override{
        payment.processPayment();
        paymentStatus = true;
        cout<<"Teacher "<<name<<" has paid monthly fees."<<endl;
    }
};

class Staff : public Person{
public:
    Staff(string name, int ID, string cardNumber) 
        : Person(name, ID, cardNumber) {}

    void payFees(Payment &payment) override{
        payment.processPayment();
        paymentStatus = true;
        cout<<"Staff member "<<name<<" has paid monthly fees."<<endl;
    }
};

class Payment{
    double amount;
    bool paymentStatus;

public:
    Payment(double amount) : amount(amount), paymentStatus(false) {}

    void processPayment(){
        paymentStatus = true;
        cout<<"Payment of amount "<<amount<<" has been processed."<<endl;
    }

    bool getPaymentStatus(){
        return paymentStatus;
    }
};

class Stop{
    int stopID;
    string stopName;
    string location;

public:
    Stop(int stopID, string stopName, string location) 
        : stopID(stopID), stopName(stopName), location(location) {}

    void getStopDetails(){
        cout << "Stop ID: "<<stopID<<", Stop Name: "<<stopName<<", Location: "<<location<<endl;
    }
};

class Route{
    int routeID;
    string routeName;
    vector<Stop> stops;

public:
    Route(int routeID, string routeName) : routeID(routeID), routeName(routeName) {}

    void addStop(const Stop &stop){
        stops.push_back(stop);
        cout << "Stop has been added to the route " << routeName << endl;
    }

    bool operator==(const Route &other) const{
        return this->routeID == other.routeID;
    }

    void getAllStops(){
        for (auto &stop : stops){
            stop.getStopDetails();
        }
    }

    string getRouteName(){
        return routeName;
    }
};

class Bus{
    int busID;
    Route route;
    vector<Person*> passengers;

public:
    Bus(int busID, Route route) : busID(busID), route(route) {}

    void assignRoute(Route &route){
        this->route = route;
        cout << "Bus " << busID << " has been assigned to route " << route.getRouteName() << endl;
    }

    void tapCard(Person &person){
        if (person.getPaymentStatus()){
            passengers.push_back(&person);
            cout << person.getName()<<" has tapped their card."<<endl;
        } else {
            cout << person.getName()<<" has not paid their fees."<<endl;
        }
    }

    void viewAttendance(){
        for (auto &passenger : passengers){
            passenger->showDetails();
        }
    }
};

int main(){
    cout << "FAST's Transportation System\n\n";

    Student student1("John Smith", 101, "12345");
    Teacher teacher1("Alice Brown", 201, "54321");
    Staff staff1("Bob White", 301, "67890");

    Payment payment1(200);
    Payment payment2(150);
    Payment payment3(150);

    student1.payFees(payment1);
    teacher1.payFees(payment2);
    staff1.payFees(payment3);

    Stop stop1(1, "Main Street", "Location A");
    Stop stop2(2, "University Road", "Location B");

    Route route1(1, "Route A");
    route1.addStop(stop1);
    route1.addStop(stop2);

    Bus bus1(101, route1);
    bus1.assignRoute(route1);

    bus1.tapCard(student1);
    bus1.tapCard(teacher1);
    bus1.tapCard(staff1);

    bus1.viewAttendance();

    Route route2(1, "Route A");
    if(route1 == route2){
        cout<<"Route 1 and Route 2 are the same!"<<endl;
    }else{
        cout<<"Route 1 and Route 2 are different."<<endl;
    }

    return 0;
}

