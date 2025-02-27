
Conversation opened. 2 messages. All messages read.

Skip to content
Using NUCES-FAST Mail with screen readers

35 of 1,431
(no subject)
Inbox

k241027 Noman Ali
AttachmentsFeb 21, 2025, 10:15 AM (6 days ago)
 

k240789 Zaid Bin Tariq <k240789@nu.edu.pk>
Attachments
Feb 21, 2025, 10:25 AM (6 days ago)
to k240784, k240772


---------- Forwarded message ---------
From: k241027 Noman Ali <k241027@nu.edu.pk>
Date: Fri, 21 Feb 2025, 10:15 am
Subject:
To: <k240789@nu.edu.pk>




 3 Attachments
  •  Scanned by Gmail
#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include <algorithm>

using namespace std;

class Book {
public:
    Book(string isbn, string title, string author)
        : isbn(isbn), title(title), author(author) {}

    string getISBN() const { return isbn; }
    string getTitle() const { return title; }
    string getAuthor() const { return author; }

private:
    string isbn;
    string title;
    string author;
};

class Catalog {
public:
    void addBookToCatalog(Book* book) {
        catalog.push_back(book);
    }

    Book* findBookInCatalog(const string& isbn) {
        for (auto& book : catalog) {
            if (book->getISBN() == isbn) {
                return book;
            }
        }
        return nullptr; 
    }

private:
    vector<Book*> catalog; 
};

class Library {
    string name;
    string address;
    Catalog* catalog; 
    vector<Book*> books; 
public:
    Library(string name, string address)
        : name(name), address(address), catalog(new Catalog()) {}
        
    void addBook(Book* book) {
        catalog->addBookToCatalog(book);
        books.push_back(book);
    }

    void removeBook(const string& isbn) {
        books.erase(remove_if(books.begin(), books.end(),
            [&isbn](Book* book) { return book->getISBN() == isbn; }),
            books.end());
    }

    Book* findBookInCatalog(const string& isbn) {
        return catalog->findBookInCatalog(isbn);
    }

    void displayLibraryInfo() const {
        cout << "Library Name: " << name << "\n";
        cout << "Address: " << address << "\n";
    }

};

int main(int argc, char* argv[]){
    Book book1("1234", "The Great Book", "John Doe");
    Book book2("5678", "Learning C++", "Jane Smith");

    Library library("City Library", "123 Library St");

    library.displayLibraryInfo();

    library.addBook(&book1);
    library.addBook(&book2);

    Book* foundBook = library.findBookInCatalog("1234");
    if (foundBook) {
        cout << "Book found: " << foundBook->getTitle() << " by " << foundBook->getAuthor() << "\n";
    } else {
        cout << "Book not found in catalog.\n";
    }

    library.removeBook("1234");

    foundBook = library.findBookInCatalog("1234");
    if (foundBook) {
        cout << "Book found: " << foundBook->getTitle() << " by " << foundBook->getAuthor() << "\n";
    } else {
        cout << "Book not found in catalog.\n";
    }

    return 0;
}
Question3.cpp
Displaying Question3.cpp.
