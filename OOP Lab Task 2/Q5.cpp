#include <iostream>
#include <algorithm>
using namespace std;

struct Person {
    int id;
    string name;
};

int main() {
    int N;
    cin >> N;

    Person people[100];

    for (int i = 0; i < N; i++) {
        cin >> people[i].id >> people[i].name;
    }

    sort(people, people + N, [](Person a, Person b) {
        return a.id < b.id;
    });

    for (int i = 0; i < N; i++) {
        cout << people[i].id << " " << people[i].name << endl;
    }

    sort(people, people + N, [](Person a, Person b) {
        return a.name[0] < b.name[0];
    });

    for (int i = 0; i < N; i++) {
        cout << people[i].id << " " << people[i].name << endl;
    }

    return 0;
}

