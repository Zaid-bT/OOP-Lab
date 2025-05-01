#include<iostream>
#include<fstream>
#include<string>
using namespace std;

int main(){
	string str;
	
	cout<<"Enter: ";
	getline(cin,str);
	
	ofstream outFile("file.txt");
	outFile<<str;
	for(int i=0; i<str.length();i++){
		str[i] = str[i]+(i+1);
	}
	outFile<<"\n"<<str;
	outFile.close();
	
	
	
	ifstream readFile("file.txt");
	getline(readFile,str);
	getline(readFile,str);
	for(int i=0;i<str.length();i++){
		str[i] = str[i]-(i+1);
	}
	cout<<str;
	readFile.close();
	
	return 0;
	
}
