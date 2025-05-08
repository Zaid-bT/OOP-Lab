#include<iostream>
#include<vector>
#include<stdexcept>
using namespace std;



class StackUnderflowException : public exception{
    const char* what() const noexcept override{
        return "Stack underflow: No elements in stack";
    }
};

template<typename T>
class Base{
protected:
    T a, b;
public:
    Base(T x, T y) : a(x), b(y) {}
    T multiplyBase() const{ return a * b; }
};

template<typename T>
class Derived : public Base<T>{
    T c, d;
public:
    Derived(T x, T y, T m, T n) : Base<T>(x, y), c(m), d(n) {}
    T multiplyDerived() const{ return c * d; }
    void displayProducts() const{
        cout << "Base Multiplication: " << this->multiplyBase() << endl;
        cout << "Derived Multiplication: " << multiplyDerived() << endl;
    }
};



template<typename T>
class Stack{
    vector<T> elements;
public:
    void push(const T& item){
        elements.push_back(item);
    }

    void pop(){
        if (elements.empty()) throw StackUnderflowException();
        elements.pop_back();
    }

    T top() const{
        if (elements.empty()) throw StackUnderflowException();
        return elements.back();
    }

    bool empty() const{
        return elements.empty();
    }
};

int main(){
    try{
        cout << "Template Inheritance" <<endl;
        Derived<int> obj(2, 3, 4, 5);
        obj.displayProducts();

        cout << "\n Stack Template "  <<endl;
        Stack<int> s;
        s.push(10);
        s.push(20);
        cout << "Top: " << s.top() << endl;
        s.pop();
        cout << "Top after pop: " << s.top() << endl;
        s.pop();
        s.pop(); 
    }catch (const exception& e){
        cerr << "Exception: " << e.what() << endl;
    }



    return 0;
}
 
