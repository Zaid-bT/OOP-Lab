#include<iostream>
using namespace std;


class Media{
protected:
    string title, publicationDate, uniqueID, publisher;
public:
    Media(string t, string pubDate, string id, string pub) 
        : title(t), publicationDate(pubDate), uniqueID(id), publisher(pub) {}

    virtual void displayInfo(){
        cout<<"Title: "<<title<<"\nPublication Date: "<<publicationDate <<"\nUnique ID: "<<uniqueID<<"\nPublisher: "<<publisher<<endl;
    }

    void checkOut(){
        cout << title <<" has been checked out.\n";
    }

    void returnItem(){
        cout << title <<" has been returned.\n";
    }

    
    bool search(string searchTitle){
        return title == searchTitle;
    }

    bool searchByYear(string year){
        return publicationDate == year;
    }
};


class Book : public Media{
    string author, ISBN;
    int numberOfPages;
public:
    Book(string t, string pubDate, string id, string pub, string a, string isbn, int pages) 
        : Media(t, pubDate, id, pub), author(a), ISBN(isbn), numberOfPages(pages) {}

    void displayInfo() override{
        Media::displayInfo();
        cout<<"Author: "<<author<<"\nISBN: "<<ISBN<<"\nPages: "<<numberOfPages<<endl;
    }
};


class DVD : public Media{
    string director, rating;
    int duration;
public:
    DVD(string t, string pubDate, string id, string pub, string dir, int dur, string rate) 
        : Media(t, pubDate, id, pub), director(dir), duration(dur), rating(rate) {}

    void displayInfo() override{
        Media::displayInfo();
        cout<<"Director: "<<director<<"\nDuration: "<<duration<<" mins\nRating: "<<rating<<endl;
    }
};


class CD : public Media{
    string artist, genre;
    int numberOfTracks;
public:
    CD(string t, string pubDate, string id, string pub, string art, int tracks, string gen) 
        : Media(t, pubDate, id, pub), artist(art), numberOfTracks(tracks), genre(gen) {}

    void displayInfo() override{
        Media::displayInfo();
        cout<<"Artist: "<<artist<<"\nTracks: "<<numberOfTracks<<"\nGenre: "<<genre<<endl;
    }
};


int main(){
    Book b1("The Great Gatsby", "1925", "B001", "Scribner", "F. Scott Fitzgerald", "9780743273565", 180);
    DVD d1("Inception", "2010", "D001", "Warner Bros", "Christopher Nolan", 148, "PG-13");
    CD c1("Thriller", "1982", "C001", "Epic Records", "Michael Jackson", 9, "Pop");

    
    cout << "\nBook Info:\n";
    b1.displayInfo();
    b1.checkOut();
    b1.returnItem();

    cout << "\nDVD Info:\n";
    d1.displayInfo();

    cout << "\nCD Info:\n";
    c1.displayInfo();

    
    cout << "\nSearching for 'Inception': ";
    cout << (d1.search("Inception") ? "Found!" : "Not Found!")<<endl;

    cout << "Searching for media from 1982: ";
    cout << (c1.searchByYear("1982") ? "Found!" : "Not Found!")<<endl;

    return 0;
}

