#include<iostream>
using namespace std;

class Currency{
protected:
    double amount;
    string currencyCode;
    double exchangeRate; 

public:
    Currency(double amt, string code, double rate) : amount(amt), currencyCode(code), exchangeRate(rate) {}
    virtual double convertToBase() = 0;
    virtual void displayCurrency() = 0;
};

class Dollar : public Currency{
public:
    Dollar(double amt) : Currency(amt, "USD", 1.0) {} // USD is base currency

    double convertToBase() override{
        return amount;
    }

    void displayCurrency() override{
        cout<<"Amount: $"<<amount<<" (USD)"<<endl;
    }
};

class Euro : public Currency{
public:
    Euro(double amt) : Currency(amt, "EUR", 1.1) {} // 1 EUR = 1.1 USD 

    double convertToBase() override{
        return amount * exchangeRate;
    }

    void displayCurrency() override{
        cout<<"Amount: €"<<amount<<" (EUR)"<<endl;
    }
};

class Rupee : public Currency{
public:
    Rupee(double amt) : Currency(amt, "PKR", 0.012) {} // 1 PKR = 0.012 USD 

    double convertToBase() override {
        return amount * exchangeRate;
    }

    void displayCurrency() override {
        cout<<"Amount: ?"<<amount<<" (PKR)"<<endl;
    }
};

int main(){
    Dollar d(100);
    Euro e(100);
    Rupee r(1000);

    d.displayCurrency();
    cout << "Converted to USD: " << d.convertToBase() << " USD" << endl;

    e.displayCurrency();
    cout << "Converted to USD: " << e.convertToBase() << " USD" << endl;

    r.displayCurrency();
    cout << "Converted to USD: " << r.convertToBase() << " USD" << endl;

    return 0;
}

