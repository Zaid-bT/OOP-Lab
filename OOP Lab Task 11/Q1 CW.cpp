#include<iostream>
#include<any>
#include<stdexcept>
#include<string>
using namespace std;


class BadTypeException : public exception{
    const char* what() const noexcept override{
        return "Bad type retrieval";
    }
};

template<typename T>
class TypeSafeContainer{
    any value;
public:
    template<typename U>
    void store(U&& val){
        value = forward<U>(val);
    }

    T get() const{
        if(!value.has_value() || value.type() != typeid(T)){
            throw BadTypeException();
        }
        return any_cast<T>(value);
    }
};

int main(){
    try{
        TypeSafeContainer<int> container;
        container.store(42);
        cout << container.get() << endl;
        TypeSafeContainer<string> strContainer;
        strContainer.store(string("Hello"));
        cout << strContainer.get() << endl;
    }catch(const exception& e){
        cerr << e.what() << endl;
    }
    
    
    return 0;
}

