#include<iostream>
using namespace std;

class User{
	public:
		string name;
		int age;
		
};

int main(int argc, char* argv[]){
	User p1;
	p1.name="Teo";
	p1.age=24;
	cout<<"My name is "<<p1.name<<" and I am "<<p1.age<<" years old.";
	return 0;
}
