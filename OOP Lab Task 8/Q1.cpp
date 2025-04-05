#include<iostream>
using namespace std;

class Number{
    int value;
public:
    Number(int v) : value(v){}
    
    Number& operator--(){
        value *= 4;
        return *this;
    }
    Number operator--(int){
        Number temp = *this;
        value /= 4;
        return temp;
    }

    void display() const{
        cout<<"Value: "<<value<<endl;
    }
};

int main(int argc, char* argv[]){
    Number num(16);
    cout<<"Original: ";
    num.display();

    --num;
    cout<<"After prefix...(multiplied by 4): ";
    num.display();

    num--;
    cout<<"After postfix...(divided by 4): ";
    num.display();

    return 0;
}

