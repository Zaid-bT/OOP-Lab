#include<iostream>
#include<limits>
using namespace std;

int main(int argc, char* argv[]){
	int array[10];
	for(int i=0;i<10;i++){
    	scanf("%d",&array[i]);
	}
	int *ptr=array;
	int max= INT_MIN;
	int sec_max=INT_MIN;
	for (int i=0;i<10;i++){
    	if(max< *(ptr+i)){
        	sec_max=max;
        	max=*(ptr+i);
    	}
    	else if(sec_max<*(ptr+i) && max!=*(ptr+i)){
        	sec_max=*(ptr+i);
    	}
	}
	cout<<"second largest"<<sec_max;
	return 0;
}
