#include<iostream>
#include<stdexcept>
using namespace std;


class ArrayIndexOutOfBounds : public exception {
    const char* what() const noexcept override{
        return "Array index out of bounds";
    }
};

template<typename T>
class SafeArray{
    T* arr;
    size_t size;

public:
    SafeArray(size_t n) : size(n){
        arr = new T[n];
    }

    ~SafeArray(){
        delete[] arr;
    }

    T& operator[](int index){
        if(index < 0 || static_cast<size_t>(index) >= size){
            throw ArrayIndexOutOfBounds();
        }
        return arr[index];
    }

    size_t length() const{
        return size;
    }
};



int main(){
    try{
        SafeArray<int> a(5);
        for (int i = 0; i < 5; ++i)
            a[i] = i * 10;

        for (int i = 0; i < 5; ++i)
            cout << a[i] << " ";
        cout << endl;

        cout << a[5] << endl;  // triggers exception

    }catch (const exception& e){
        cerr << e.what() << endl;
    }




    return 0;
}

