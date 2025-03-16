#include <iostream>
using namespace std;

class Books{
	protected:
    	string genre;

	public:
    	Books(string g) : genre(g){}
    	
    void displayGenre(){
        cout<<"Genre: "<<genre<<endl;
    }
};

class Novel : public Books{
	private:
    	string title;
    	string author;

	public:
    	Novel(string t, string a) : Books("Novel"), title(t), author(a) {}

    	void display(){
        	displayGenre();
        	cout << "Title: " << title << endl;
        	cout << "Author: " << author << endl << endl;
    	}
};

class Mystery : public Books{
	private:
    	string title;
    	string author;

	public:
    	Mystery(string t, string a) : Books("Mystery"), title(t), author(a) {}

    	void display(){
        	displayGenre();
        	cout << "Title: " << title << endl;
        	cout << "Author: " << author << endl << endl;
    	}
};

int main(int argc, char* argv[]){
    Novel novel1("The Great Gatsby", "F. Scott Fitzgerald");
    Mystery mystery1("The Hound of the Baskervilles", "Arthur Conan Doyle");

    novel1.display();
    mystery1.display();

    return 0;
}

