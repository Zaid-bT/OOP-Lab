#include <iostream>
#include <vector>
using namespace std;

struct Subject {
    string name;
};

struct Student {
    int id;
    Subject subjects[3];  // fixed array of subjects
};

int main() {
    int n;
    cout << "Enter number of students: ";
    cin >> n;

    vector<Student> students(n);

    for (int i = 0; i < n; ++i) {
        cout << "Enter ID for student " << i + 1 << ": ";
        cin >> students[i].id;

        for (int j = 0; j < 3; ++j) {
            cout << "Enter subject " << j + 1 << ": ";
            cin >> students[i].subjects[j].name;
        }
    }

    cout << "\nStudent Data:\n";
    for (int i = 0; i < n; ++i) {
        cout << "ID: " << students[i].id << "\nSubjects: ";
        for (int j = 0; j < 3; ++j) {
            cout << students[i].subjects[j].name << " ";
        }
        cout << "\n";
    }

    return 0;
}

