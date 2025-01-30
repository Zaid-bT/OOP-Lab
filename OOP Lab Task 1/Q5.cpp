#include <iostream>
using namespace std;

int main(int argc, char* argv[]){
    string movieName;
    float adultTicketPrice, childTicketPrice;
    int adultTicketsSold, childTicketsSold;
    float donationPercentage;
    cout<<"Enter movie name: ";
    cin>>movieName;
    cout<<"Enter adult ticket price: ";
    cin>>adultTicketPrice;
    cout<<"Enter child ticket price: ";
    cin>>childTicketPrice;
    cout<<"Enter number of adult tickets sold: ";
    cin>>adultTicketsSold;
    cout<<"Enter number of child tickets sold: ";
    cin>>childTicketsSold;
    cout<<"Enter percentage of gross amount to be donated to charity: ";
    cin>>donationPercentage;

    float grossAmount = (adultTicketsSold * adultTicketPrice) + (childTicketsSold * childTicketPrice);
    float amountDonated = (donationPercentage / 100.0) * grossAmount;
    float netSale = grossAmount - amountDonated;
    
    cout<<"Movie Name: "<<movieName<<endl;
    cout<<"Tickets Sold: "<< adultTicketsSold+childTicketsSold<<endl;
    cout<<"Gross Amount: "<<grossAmount<<endl;
    cout<<"Percentage of Gross Amount: "<<donationPercentage<<endl;
    cout<<"Donated Amount: "<<amountDonated<<endl;
    cout<<"Net Sales: "<<netSale<<endl;
}
