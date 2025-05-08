#include <iostream>
#include <vector>
#include <stdexcept>

using namespace std;

class StackUnderflowException : public exception {
public:
    const char* what() const noexcept override {
        return "Stack underflow: no elements in the stack";
    }
};

template<typename T>
class Stack {
    vector<T> elements;
public:
    void push(const T& item) {
        elements.push_back(item);
    }

    void pop() {
        if (elements.empty()) throw StackUnderflowException();
        elements.pop_back();
    }

    T top() const {
        if (elements.empty()) throw StackUnderflowException();
        return elements.back();
    }

    bool empty() const {
        return elements.empty();
    }

    size_t size() const {
        return elements.size();
    }
};

int main() {
    try {
        Stack<int> s;
        s.push(10);
        s.push(20);
        cout << "Top: " << s.top() << endl;
        s.pop();
        cout << "Top after pop: " << s.top() << endl;
        s.pop();
        s.pop(); // This will throw StackUnderflowException
    } catch (const exception& e) {
        cerr << "Exception: " << e.what() << endl;
    }

    return 0;
}

