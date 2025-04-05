#include<iostream>
using namespace std;


class Shape{
    double area;
public:
    Shape(double a) : area(a) {}

    double Area() const{
        return area;
    }
    Shape operator+(const Shape& other){
        return Shape(this->area + other.area);
    }
    void display() const{
        cout<<"Area: "<<area<<endl;
    }
};

int main(int argc, char* argv[]){
    Shape shape1(50.5);
    Shape shape2(30.5);
    Shape totalArea = shape1+shape2;

    shape1.display();
    shape2.display();
    totalArea.display();

    return 0;
}

