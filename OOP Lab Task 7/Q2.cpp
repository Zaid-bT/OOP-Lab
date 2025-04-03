#include<iostream>
#include<cmath>
using namespace std;

class Shape{
protected:
    string color;

public:
    Shape(string col) : color(col) {}
    virtual void draw() = 0;
    virtual double calculateArea() = 0;
    virtual double calculatePerimeter() = 0;
};

class Circle : public Shape{
    double radius;

public:
    Circle(string col, double r) : Shape(col), radius(r) {}

    void draw() override{
        cout<<"Drawing "<<color<<" circle."<<endl;
    }

    double calculateArea() override{
        return M_PI * radius * radius;
    }

    double calculatePerimeter() override{
        return 2 * M_PI * radius;
    }
};

class Rectangle : public Shape{
    double width, height;

public:
    Rectangle(string col, double w, double h) : Shape(col), width(w), height(h) {}

    void draw() override{
        cout<< "Drawing "<<color<<" rectangle."<<endl;
    }

    double calculateArea() override{
        return width * height;
    }

    double calculatePerimeter() override{
        return 2 * (width + height);
    }
};

int main(){
    Circle circle("red", 5.0);
    Rectangle rectangle("blue", 4.0, 6.0);

    circle.draw();
    cout << "Circle Area: " << circle.calculateArea() << endl;
    cout << "Circle Perimeter: " << circle.calculatePerimeter() << endl;

    rectangle.draw();
    cout << "Rectangle Area: " << rectangle.calculateArea() << endl;
    cout << "Rectangle Perimeter: " << rectangle.calculatePerimeter() << endl;

    return 0;
}

