
#include <iostream>
using namespace std;

int main(int argc, char* argv[]){
	int sum=0;
	int arr[argc];
	int *ptr=arr;
	for(int i=0;i<argc;i++){
		arr[i]=atoi(argv[i]);
	}
	for(int i=0;i<argc;i++){
		sum+=*(ptr+i);
	}
	cout << "Sum of Array: " << sum;
	
	return 0;
}

