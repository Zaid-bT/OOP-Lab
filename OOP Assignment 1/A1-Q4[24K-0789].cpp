#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Payment;
class Route;
class Stop;
class Bus;

class Student{
    string name;
    int studentID;
    string cardNumber;
    bool paymentStatus;

	public:
    	Student(string name,int studentID,string cardNumber) 
        	: name(name),studentID(studentID),cardNumber(cardNumber),paymentStatus(false) {}

    	void registerStudent(){
        	cout<<"Student "<<name<<"has been registered for transportation."<<endl;
    	}	

    	void payFees(Payment &payment){
        	payment.processPayment();
        	paymentStatus = true;
        	cout<<"Student "<<name<<" has paid semester fees."<<endl;
    	}

    	void showDetails(){
        	cout<<"Student ID: "<<studentID<<", Name: "<<name<<", Card Number: "<<cardNumber<<", Payment Status: "<<(paymentStatus ? "Paid" : "Not Paid")<<endl;
    	}
};

class Payment{
    double amount;
    bool paymentStatus;

	public:
    	Payment(double amount) : amount(amount),paymentStatus(false) {}

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
        	: stopID(stopID),stopName(stopName),location(location) {}

    	void getStopDetails(){
        	cout<<"Stop ID: "<<stopID<<", Stop Name: "<<stopName <<", Location: "<<location<<endl;
    	}
};

class Route{
    int routeID;
    string routeName;
    vector<Stop> stops;

	public:
    	Route(int routeID, string routeName) : routeID(routeID),routeName(routeName) {}

    	void addStop(const Stop &stop){
        	stops.push_back(stop);
        	cout<<"Stop "<<stop.getStopDetails()<<" has been added to the route "<<routeName<<endl;
    	}

    	void removeStop(int stopID){
        	for(auto it = stops.begin(); it != stops.end();it++){
            	if(it->getStopDetails() == stopID){
                	stops.erase(it);
                	break;
           		}
        	}
        	cout<<"Stop with ID "<<stopID<<" has been removed."<<endl;
			}

    	void getAllStops(){
        	for(auto &stop : stops){
            	stop.getStopDetails();
        	}
    	}
};

class Bus{
    int busID;
    Route route;
    vector<Student> students;

	public:
    	Bus(int busID, Route route) : busID(busID),route(route) {}

    	void assignRoute(Route &route){
        	this->route = route;
        	cout<<"Bus "<<busID<<" has been assigned to route "<<route.getRouteName()<<endl;
    	}

    	void tapCard(Student &student){
        	if(student.isPaymentStatus()){
            	students.push_back(student);
            	cout<<"Student "<<student.getName()<<" has tapped their card."<<endl;
        	}else{
            	cout<<"Student "<<student.getName()<<" has not paid their fees."<<endl;
        	}
    	}

    	void viewAttendance(){
        	for(auto &student : students){
            	cout<<"Student ID: "<<student.getID()<<", Name: "<<student.getName()<<endl;
        	}
    	}
};

int main(int argc, char* argv[]){
    Student student1("John Smith", 101, "12345");
    Student student2("Jane Doe", 102, "67890");

    Payment payment1(200);
    Payment payment2(200);

    student1.registerStudent();
    student1.payFees(payment1);

    student2.registerStudent();
    student2.payFees(payment2);

    Stop stop1(1, "Main Street", "Location A");
    Stop stop2(2, "University Road", "Location B");

    Route route1(1, "Route A");
    route1.addStop(stop1);
    route1.addStop(stop2);

    Bus bus1(101, route1);
    bus1.assignRoute(route1);

    bus1.tapCard(student1);
    bus1.tapCard(student2);

    bus1.viewAttendance();

    return 0;
}

