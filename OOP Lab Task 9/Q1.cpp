#include<iostream>
#include<cmath>
using namespace std;

class Shape{
public:
    virtual double getArea() const = 0;  // pure virtual function
    virtual ~Shape() {}  // virtual destructor
};

class Rectangle : public Shape{
    double width;
    double height;

public:
    Rectangle(double w, double h) : width(w), height(h) {}
    
    double getArea() const override{
        return width * height;
    }
};

class Triangle : public Shape{
    double base;
    double height;

public:
    Triangle(double b, double h) : base(b), height(h) {}
    
    double getArea() const override{
        return 0.5 * base * height;
    }
};

int main(){
    Rectangle rect(5.0, 3.0);
    Triangle tri(4.0, 6.0);
    cout << "Area of Rectangle: " << rect.getArea() << endl;
    cout << "Area of Triangle: " << tri.getArea() << endl;
    return 0;
}

