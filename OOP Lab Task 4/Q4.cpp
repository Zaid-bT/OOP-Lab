#include<iostream>
using namespace std;

class Book{
	string author,title,publisher;
	float price;
	int stock;
	
	public:
		Book();
		Book(string t,string a, string p,float price,int s){
			author=a;
			title=t;
			publisher=p;
			this->price=price;
			stock=s;
		}
		int getStock(){
			return stock;
		}

		void searchBook(string t,string a){
			if(t==title and a==author){
				cout<<"Book available \n";
				cout<<"Title: "<<title<<endl;
				cout<<"Author: "<<author<<endl;
				cout<<"Publisher: "<<publisher<<endl;
				cout<<"Price: "<<price<<endl;
				int copies;
				cout<<"Enter copies required: ";
				cin>>copies;
				if(copies>getStock()){
					cout<<"required number of copies not in stock";
					return;
				}else{
					cout<<"Total price: "<<price*copies<<endl;
				}
				
			}else{
				cout<<"No such book available...\n"<<endl;
			}
		}
};

int main(int argc,char* argv[]){
	Book book1("Book1","Author1","Publish1",200.20,3);
	Book book2("Book2","Author2","Publish2",100.50,4);
	
	book1.searchBook("Book3","Author1");
	book2.searchBook("Book2","Author2");
	
	return 0;
}
