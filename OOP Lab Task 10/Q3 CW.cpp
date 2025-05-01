#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <map>

using namespace std;

struct User {
    string id, first_name, last_name, address, email;
};

struct Product {
    string id, name, description;
    int price;
};

struct Order {
    string id, user_id, product_id;
    int total_paid;
};

int main() {
    ofstream usersFile("users.txt");
    usersFile << "1,Linus,Torvalds,Helsinki,linus@example.com\n";
    usersFile << "2,Alan,Turing,UK,alan@example.com\n";
    usersFile.close();

    ofstream productsFile("products.txt");
    productsFile << "101,Laptop,High-end laptop,1500\n";
    productsFile << "102,Keyboard,Mechanical keyboard,100\n";
    productsFile.close();

    ofstream ordersFile("orders.txt");
    ordersFile << "201,1,101,1500\n";
    ordersFile << "202,1,102,100\n";
    ordersFile << "203,2,102,100\n";
    ordersFile.close();

    map<string, string> users;
    ifstream inUsers("users.txt");
    string line;
    while (getline(inUsers, line)) {
        stringstream ss(line);
        string id, fname, lname, address, email;
        getline(ss, id, ',');
        getline(ss, fname, ',');
        getline(ss, lname, ',');
        getline(ss, address, ',');
        getline(ss, email, ',');
        if (fname == "Linus") {
            users[id] = fname;
        }
    }
    inUsers.close();

    map<string, string> products;
    ifstream inProducts("products.txt");
    while (getline(inProducts, line)) {
        stringstream ss(line);
        string id, name, desc, price;
        getline(ss, id, ',');
        getline(ss, name, ',');
        getline(ss, desc, ',');
        getline(ss, price, ',');
        products[id] = name;
    }
    inProducts.close();

    ifstream inOrders("orders.txt");
    while (getline(inOrders, line)) {
        stringstream ss(line);
        string order_id, user_id, product_id, paid;
        getline(ss, order_id, ',');
        getline(ss, user_id, ',');
        getline(ss, product_id, ',');
        getline(ss, paid, ',');
        if (users.find(user_id) != users.end()) {
            cout << products[product_id] << endl;
        }
    }
    inOrders.close();

    return 0;
}

