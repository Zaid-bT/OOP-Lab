#include<iostream>
using namespace std;

int main(int argc, char* argv[]){
	int score[5];
	string name;
	int sum,avg;
	cin>>name;
	for(int i=0;i<5;i++){
    	scanf("%d",&score[i]);
	}
	for(int i=0;i<5;i++){
    	sum+=score[i];
	}
	avg=sum/5;
	cout<<"Student Name: "<<name<<endl;
	cout<<"Test Scores: ";
	for(int i=0;i<5;i++){
		printf("%d ",score[i]);
	}printf("\n");
	cout<<"Average Score: "<<avg;

	return 0;
}
