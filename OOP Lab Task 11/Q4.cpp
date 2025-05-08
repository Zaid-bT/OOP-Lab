#include <iostream>

using namespace std;

template<typename T>
class Base {
protected:
    T a, b;
public:
    Base(T x, T y) : a(x), b(y) {}
    T multiplyBase() const {
        return a * b;
    }
};

template<typename T>
class Derived : public Base<T> {
    T c, d;
public:
    Derived(T x, T y, T m, T n) : Base<T>(x, y), c(m), d(n) {}

    T multiplyDerived() const {
        return c * d;
    }

    void displayProducts() const {
        cout << "Base Multiplication: " << this->multiplyBase() << endl;
        cout << "Derived Multiplication: " << multiplyDerived() << endl;
    }
};

int main() {
    Derived<int> obj(2, 3, 4, 5);
    obj.displayProducts();

    Derived<float> obj2(1.5f, 2.0f, 3.0f, 4.0f);
    obj2.displayProducts();

    return 0;
}

