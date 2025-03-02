#include <iostream>
#include <string>
#include <vector>

using namespace std;

const int LEARNER = 0;
const int INTERMEDIATE = 1;
const int FULL = 2;

class Vehicle{
	public:
    	string model;
    	double rentalPricePerDay;
    	int eligibleLicense;

    	Vehicle(string m,double price,int license) : model(m),rentalPricePerDay(price),eligibleLicense(license) {}
};

class User{
    string name;
    int age;
    int type;
    string contactInfo;
    string userID;

	public:
    	User(string n,int a,int lt,string contact,string id)
        : name(n),age(a),type(lt),contactInfo(contact),userID(id) {}

		void updateDetails(string n, int a, int lt, string contact){
        	name = n;
        	age = a;
        	type = lt;
        	contactInfo = contact;
    	}

    	bool isEligibleForRental(Vehicle* vehicle){
        	return vehicle->eligibleLicense <= type;
    	}

    	void displayUserDetails(){
        	cout<<"User ID: "<<userID<<endl;
        	cout<<"Name: "<<name<<endl;
        	cout<<"Age: "<<age<<endl;
        	cout<<"License Type: "<<(type == LEARNER ? "Learner" : (type == INTERMEDIATE ? "Intermediate" : "Full"))<<endl;
        	cout<<"Contact Info: "<<contactInfo<<endl;
    	}

    	string getUserID(){
        	return userID;
    	}
};

class RentalSystem{
    vector<User*> users;
    vector<Vehicle*> vehicles;

	public:
    	void registerUser(string name,int age,int type,string contact,string userID){
        	User* newUser = new User(name,age,type,contact,userID);
        	users.push_back(newUser);
        	cout<<"User registered !"<<endl;
    	}

    	void updateUserDetails(string userID, string name, int age, int type, string contact){
        	for(auto& user : users){
            	if(user->getUserID() == userID){
                	user->updateDetails(name,age,type,contact);
                	cout<<"User details updated successfully!"<<endl;
                	return;
            	}
        	}
        	cout<<"User not found..."<<endl;
    	}

    	void addVehicle(string model,double rentalPrice,int eligibility){
        	Vehicle* newVehicle = new Vehicle(model,rentalPrice,eligibility);
        	vehicles.push_back(newVehicle);
    	}

    	void listAvailableVehicles(){
        	cout<<"Available Vehicles: "<<endl;
        	for(auto& vehicle : vehicles){
            	cout<<"Model: "<<vehicle->model<<", Price per day: "<<vehicle->rentalPricePerDay<<", Eligible License: "<<(vehicle->eligibleLicense == LEARNER ? "Learner" : (vehicle->eligibleLicense == INTERMEDIATE ? "Intermediate" : "Full"))<<endl;
        	}
    	}

    	void rentVehicle(string userID, string vehicleModel){
        	User* selectedUser = nullptr;
        	Vehicle* selectedVehicle = nullptr;
	        for(auto& user : users){
    	        if(user->getUserID() == userID){
        	        selectedUser = user;
            	    break;
            	}
        	}
        	if(selectedUser == nullptr){
            	cout<<"User not found..."<<endl;
            	return;
        	}
        	for(auto& vehicle : vehicles){
            	if(vehicle->model == vehicleModel){
                	selectedVehicle=vehicle;
                	break;
            	}
        	}
        	if(selectedVehicle == nullptr){
            	cout<<"Vehicle not found..."<<endl;
            	return;
        	}

        	if(selectedUser->isEligibleForRental(selectedVehicle)){
            	cout<<"Rental Successful!"<<endl;
            	cout<<"Vehicle: "<<selectedVehicle->model<<endl;
            	cout<<"Rental Price per Day: "<<selectedVehicle->rentalPricePerDay<<endl;
        	}else{
            	cout<<"You are not eligible to rent this vehicle!"<<endl;
        	}
    	}

    	~RentalSystem(){
        	for(auto& user : users){
            	delete user;
        	}
        	for(auto& vehicle : vehicles){
            	delete vehicle;
        	}
    	}
};

int main(int argc, char* argv[]){
	cout<<"Zaid Bin Tariq....24K-0789\n\n";
	
	
    RentalSystem system;

    system.registerUser("John Doe", 25, FULL, "123-456-7890", "U001");
    system.registerUser("Jane Smith", 19, LEARNER, "987-654-3210", "U002");

    system.addVehicle("Toyota Corolla", 50.0, INTERMEDIATE);
    system.addVehicle("BMW X5", 100.0, FULL);
    system.addVehicle("Honda Civic", 40.0, LEARNER);

    system.listAvailableVehicles();

    system.rentVehicle("U001", "BMW X5");
    system.rentVehicle("U002", "BMW X5");

    system.updateUserDetails("U002", "Jane Doe", 20, INTERMEDIATE, "555-555-5555");

    return 0;
}

