#include<iostream>
using namespace std;


class Book{
	string name,author,publisher;
	string isbn;
	
	public:
		Book(string name,string isbn,string author,string publisher){
			this->name=name;
			this->isbn=isbn;
			this->publisher=publisher;
			this->author=author;
		}
		
		string getName(){
			return name;
		}
		string getAuthor(){
			return author;
		}
		string getPublisher(){
			return publisher;
		}
		string getISBN(){
			return isbn;
		}
    	void getBookInfo(){
    		cout<< "Book Name: " + name + "\nISBN: " + isbn + "\nAuthor: " + author + "\nPublisher: " + publisher + "\n\n";
//	       	return "Book Name: " + name + "\nISBN: " + isbn + "\nAuthor: " + author + "\nPublisher: " + publisher;
    	}
    	
    	void SearchByName(string name){
    		if(this->name==name){
    			getBookInfo();
			}else{
				cout<<"No book found with this name...\n";
			}
		}
		void SearchByAuthor(string author){
    		if(this->author==author){
    			getBookInfo();
			}else{
				cout<<"No book found with this author name...\n";
			}
		}
		void SearchByISBN(string isbn){
    		if(this->isbn==isbn){
    			getBookInfo();
			}else{
				cout<<"No book found with this ISBN number...\n";
			}
		}
		void SearchByPublisher(string publisher){
    		if(this->publisher==publisher){
    			getBookInfo();
			}else{
				cout<<"No book found with this publisher group...\n";
			}
		}
			
};

int main(int argc, char* argv[]){
	Book BookTest[5] = {
    	Book("Book1", "1111", "Author1", "Publisher1"),
        Book("Book2", "2222", "Author2", "Publisher2"),
        Book("Book3", "3333", "Author3", "Publisher3"),
        Book("Book4", "4444", "Author4", "Publisher4"),
        Book("Book5", "5555", "Author5", "Publisher5")
    };
	
	BookTest[0].SearchByName("Book1");
	BookTest[1].SearchByAuthor("Author2");
	BookTest[2].SearchByISBN("3333");
	BookTest[3].SearchByPublisher("Publisher4");
	BookTest[4].getBookInfo();
	
	BookTest[0].SearchByName("Book6");

		
}



