#include <iostream>
using namespace std;

class Vehicle{
	protected:
    	double price;

	public:
    	Vehicle(double p) : price(p){}

    	void display(){
        	cout<<"Price: "<<price<<endl;
    	}
};

class Car : public Vehicle{
	protected:
    	int seatingCapacity;
    	int numberOfDoors;
    	string fuelType;

	public:
    	Car(double p, int sc, int doors, string fuel) 
        	: Vehicle(p), seatingCapacity(sc), numberOfDoors(doors), fuelType(fuel) {}

    	void display() {
        	cout << "Price: " << price << endl;
        	cout << "Seating Capacity: " << seatingCapacity << endl;
        	cout << "Number of Doors: " << numberOfDoors << endl;
        	cout << "Fuel Type: " << fuelType << endl;
    	}
};

class Motorcycle : public Vehicle{
	protected:
    	int numberOfCylinders;
    	int numberOfGears;
    	int numberOfWheels;

	public:
    	Motorcycle(double p, int cylinders, int gears, int wheels) 
        	: Vehicle(p), numberOfCylinders(cylinders), numberOfGears(gears), numberOfWheels(wheels) {}

    	void display(){
        	cout <<"Price: "<<price<<endl;
        	cout <<"Number of Cylinders: "<<numberOfCylinders<<endl;
        	cout <<"Number of Gears: "<<numberOfGears<<endl;
        	cout <<"Number of Wheels: "<<numberOfWheels<<endl;
    	}
};

class Audi : public Car{
	private:			
    	string modelType;

	public:
    	Audi(double p, int sc, int doors, string fuel, string model) 
        	: Car(p, sc, doors, fuel), modelType(model) {}

    	void display(){
        	Car::display();
        	cout << "Model Type: " << modelType << endl;
    	}
};

class Yamaha : public Motorcycle{
	private:	
    	string makeType;

	public:
    	Yamaha(double p, int cylinders, int gears, int wheels, string make) 
        	: Motorcycle(p, cylinders, gears, wheels), makeType(make) {}

    	void display(){
        	Motorcycle::display();
        	cout << "Make Type: " << makeType << endl;
		}
};

int main(int argc, char* argv[]){
    Audi audiCar(50000, 5, 4, "Petrol", "Q7");
    Yamaha yamahaBike(15000, 4, 6, 2, "YZF-R1");

    cout<<"Audi Car Details: " <<endl;
    audiCar.display();

    cout<<endl;

    cout<<"Yamaha Motorcycle Details: "<<endl;
    yamahaBike.display();

    return 0;
}

