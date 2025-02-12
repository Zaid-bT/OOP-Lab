#include<iostream>
using namespace std;

class Glass{
	public:
		int LiquidLevel=200;
		
		void Refill(){
			LiquidLevel=200;
		}
		
		void Drink(int ml){
			ml=LiquidLevel-ml;
			LiquidLevel=ml;
			cout<<"Drink left: "<<ml<<" ml\n";
			if(ml<100){
				Refill();
				cout<<"Drink refilled to 200ml\n";
			}else{
				cout<<"No refill for you\n";
			}
		}
};

int main(int argc, char* argv[]){
	Glass juice;
//	juice.LiquidLevel=200;
	string n;
	cout<<"Drink filled for you\n";
	cout<<"Type drink to refill\nType stop to stop\n\n";
	
	cin>>n;
	while(n!="stop"){
		if(n=="drink"){
			cout<<"enter ml drank: ";
			cin>>argc;
			juice.Drink(argc);
		}
		cin>>n;
	}	
	return 0;
}