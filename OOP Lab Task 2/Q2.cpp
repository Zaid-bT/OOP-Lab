#include<iostream>
using namespace std;


void* addOperation(void* arr, int size){
	int* arrInt = static_cast<int*>(arr); // casts void ptr to int ptr
	for( int i=0;i<size;i++){
		arrInt[i]+=1;
	}
//	void * ret=&c
	arr=&arrInt;
	return arr;
}

int main(int argc, char* argv[]){
	int size;
	cout<<"Enter array size: ";
	cin>>size;
//	int size=stoi(argv[1]);
    int* array=new int[size];
    for(int i=0;i<size;i++){
    	cout<<"Enter value: ";
    	cin>>array[i];
	}
	
	cout<<"Orignal array: "<<endl;
	for(int i=0;i<size;i++){
		cout<<array[i]<<" ";
	}
	
	cout<<"\nModified array: "<<endl;
	addOperation(array,size);
	for(int i=0;i<size;i++){
		cout<<array[i]<<" ";
	}
	
	
	
    return 0;
}
