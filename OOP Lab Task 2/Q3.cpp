#include <iostream>
using namespace std;

int* resizeArray(int* oldArray, int oldSize, int newSize) {
    int* newArray = new int[newSize];
    for (int i = 0; i < oldSize; ++i) {
        newArray[i] = oldArray[i];
    }
    delete[] oldArray;
    return newArray;
}

int main() {
    int capacity = 5;
    int* array = new int[capacity];
    int count = 0;
    int input;

    cout << "Enter integers (non-integer to stop):" << endl;

    while (cin >> input) {
        if (count >= 2 * capacity) {
            int newCapacity = capacity * 2;
            array = resizeArray(array, capacity, newCapacity);
            capacity = newCapacity;
            cout << "Resized array to capacity: " << capacity << endl;
        }

        if (count >= capacity) {
            int newCapacity = capacity * 2;
            array = resizeArray(array, capacity, newCapacity);
            capacity = newCapacity;
            cout << "Resized array to capacity: " << capacity << endl;
        }

        array[count] = input;
        count++;
    }

    int* finalArray = resizeArray(array, count, count);
    array = finalArray;
    capacity = count;

    cout << "\nFinal array contents (" << capacity << " elements): ";
    for (int i = 0; i < capacity; ++i) {
        cout << array[i] << " ";
    }
    cout << endl;

    delete[] array;
    return 0;
}

