#include<iostream>
using namespace std;


class Circle{
	float radius;
	
	public:
		Circle();
		
		Circle(float r){
			radius=r;
		}
		
		float getArea() {
			return 3.142*radius*radius;
		}
		
		float getPerimeter(){
			return 2*3.142*radius;
		}
		
};


int main(int argc, char* argv[]){
	float r;
	cout<<"Enter radius: ";
	cin>>r;
	Circle c1(r);
	cout<<"Area of circle: "<<c1.getArea()<<endl;
	cout<<"Circumference of circle: "<<c1.getPerimeter()<<endl;
	
	return 0;
}
