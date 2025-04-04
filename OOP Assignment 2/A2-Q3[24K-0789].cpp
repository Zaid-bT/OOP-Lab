#include<iostream>
#include<string>
#include<cmath>
using namespace std;

class Vehicle{
protected:
    string vehicleID;
    double weight;
    double speed;
    double capacity;
    string destination;
    static int activeDeliveries;
public:
    Vehicle(string id, double w, double s, double c, string dest)
        : vehicleID(id), weight(w), speed(s), capacity(c), destination(dest){
        activeDeliveries++;
    }

    virtual void move() = 0;
    virtual void command(string action, int urgencyLevel = 0) = 0;

    double calculateRoute(){
        return sqrt(pow(speed, 2) + pow(weight, 2));
    }

    double estimateTime(){
        return (weight/speed)*10;
    }

    static int getActiveDeliveries(){
        return activeDeliveries;
    }

    virtual ~Vehicle(){
        activeDeliveries--;
    }
};

int Vehicle::activeDeliveries = 0;

class RamzanDrone : public Vehicle{
public:
    RamzanDrone(string id, double w, double s, double c, string dest)
        : Vehicle(id, w, s, c, dest){}

    void move() override{
        cout<<"RamzanDrone: Flying to "<<destination<<endl;
    }

    void command(string action, int urgencyLevel = 0) override{
        if(action == "Deliver"){
            if(urgencyLevel>5){
                cout<<"RamzanDrone: High-speed mode"<<endl;
            }else{
                cout<<"RamzanDrone: Standard delivery."<<endl;
            }
        }
    }
};

class RamzanTimeShip : public Vehicle{
public:
    RamzanTimeShip(string id, double w, double s, double c, string dest)
        : Vehicle(id, w, s, c, dest){}

    void move() override{
        cout<<"RamzanTimeShip: Time travel to "<<destination<<endl;
    }

    void command(string action, int urgencyLevel = 0) override{
        if(action == "Deliver"){
            if(urgencyLevel>5){
                cout<<"RamzanTimeShip: Verifying history!"<<endl;
            }else{
                cout<<"RamzanTimeShip: Delivering with accuracy."<<endl;
            }
        }
    }
};

class RamzanHyperPod : public Vehicle{
public:
    RamzanHyperPod(string id, double w, double s, double c, string dest)
        : Vehicle(id, w, s, c, dest){}

    void move() override{
        cout<<"RamzanHyperPod: Underground delivery to "<<destination<<endl;
    }

    void command(string action, int urgencyLevel = 0) override{
        if(action == "Deliver"){
            if(urgencyLevel>5){
                cout<<"RamzanHyperPod: Fast bulk delivery!"<<endl;
            }else{
                cout<<"RamzanHyperPod: Standard delivery."<<endl;
            }
        }
    }
};

bool compareVehicles(const Vehicle& v1, const Vehicle& v2){
    return v1.estimateTime() < v2.estimateTime();
}

bool operator==(const Vehicle& v1, const Vehicle& v2){
    return v1.estimateTime() == v2.estimateTime();
}

int main(){
    RamzanDrone drone1("Drone1", 10, 100, 5, "Mecca");
    RamzanTimeShip timeShip1("TimeShip1", 100, 200, 50, "Historical Site");
    RamzanHyperPod hyperPod1("HyperPod1", 500, 80, 300, "Cairo");

    Vehicle* vehicles[] = {&drone1, &timeShip1, &hyperPod1};

    drone1.command("Deliver", 7);
    timeShip1.command("Deliver", 3);
    hyperPod1.command("Deliver", 8);

    compareVehicles(drone1, timeShip1) ? cout << "Drone1 is faster" : cout << "TimeShip1 is faster";
    cout<<endl;

    if(drone1 == timeShip1){
        cout<<"The vehicles have the same delivery time."<<endl;
    }else{
        cout<<"The vehicles have different delivery times."<<endl;
    }

    cout<<"Total active deliveries: "<< Vehicle::getActiveDeliveries()<<endl;

    return 0;
}

