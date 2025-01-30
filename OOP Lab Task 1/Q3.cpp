#include<iostream>
using namespace std;
int main(int argc, char* argv[]){
	int id,unit;
    float bill,final_bill,surcharge;
	string name;
	cin>>id;
    cin>>unit;
    cin>>name; 
	if(unit<0){
		printf("Invalid Units");
		}
	else if (unit>0 && unit<=199){ 
		bill= unit*16.20;
		}
	else if(unit>=200 && unit<300){
		bill=unit*20.10;
		}
	else if (unit>=300 && unit<500){
		bill=unit*27.10;
		}
	else if (unit>=500){
		bill=unit*35.90;
		}
	if(bill>18000){
		surcharge=0.15*bill;
		}
    cout<<name<<endl;
    cout<<id<<endl;
    cout<<unit<<endl;
	cout<<"Amount: "<<bill<<endl;
	cout<<"Surcharge: "<<surcharge<<endl;
	cout<<"Net Amount: "<<(bill+surcharge)<<endl;
	
	return 0;
	
}
