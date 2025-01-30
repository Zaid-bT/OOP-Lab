#include<iostream>
using namespace std;

int main(int argc, char* argv[]){
	float kg;
	float pound;
	cout<<"Enter weight in kg: ";
	cin>>kg;
	pound= kg*2.2;
	printf("Weight in pounds: %.1f\n",pound);
	printf("Weight in kg: %.1f",kg);

	return 0;
}
