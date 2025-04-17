#include<iostream>
#include<string>
using namespace std;

class Car{
protected:
    string model;
    double price;

public:
    Car(string m, double p) : model(m), price(p) {}

    string getModel() const{
        return model;
    }

    double getPrice() const{
        return price;
    }

    void setModel(const string& m){
        model = m;
    }

    virtual void setPrice(double p) = 0;

    virtual void displayInfo() const = 0;

    virtual ~Car(){}
};

class Color : public Car{
    string color;

public:
    Color(string m, double p, string c) : Car(m, p), color(c) {}

    void setPrice(double p) override{
        price = p * 1.1;
    }

    void displayInfo() const override{
        cout << "Model: " << model << "\nColor: " << color << "\nPrice: $" << price << endl;
    }
};

class Company : public Car{
    string companyName;

public:
    Company(string m, double p, string cName) : Car(m, p), companyName(cName) {}

    void setPrice(double p) override{
        price = p*1.2;
    }

    void displayInfo() const override{
        cout << "Model: " << model << "\nCompany: " << companyName << "\nPrice: $" << price << endl;
    }
};

int main(){
    Color car1("Sedan", 20000, "Red");
    Company car2("SUV", 30000, "Luxury Motors");

    car1.setPrice(20000);
    car2.setPrice(30000);
    cout << "\nCar 1 Info:" << endl;
    car1.displayInfo();
    cout << "\nCar 2 Info:" << endl;
    car2.displayInfo();

    return 0;
}

