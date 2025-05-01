#include<iostream>
#include<fstream>
#include<sstream>
#include<vector>
using namespace std;

struct Employee{
    int id;
    string name, designation;
    int years;
};

vector<Employee> readData(const string& filename) {
    ifstream file(filename);
    vector<Employee> data;
    string line;
    while(getline(file, line)){
        stringstream ss(line);
        Employee e;
        ss >> e.id >> e.name >> e.designation >> e.years;
        data.push_back(e);
    }
    return data;
}

void writeData(const string& filename, const vector<Employee>& data){
    ofstream file(filename, ios::trunc);
    for(auto& e : data)
        file << e.id << " " << e.name << " " << e.designation << " " << e.years << endl;
}

int main(){
    ofstream file("employees.txt");
    file << "1 John Manager 3\n2 Alice Engineer 1\n3 Bob Manager 2\n4 Carol Clerk 5\n";
    file.close();
    vector<Employee> all = readData("employees.txt");
    vector<Employee> filtered;
    for(auto& e : all)
        if (e.designation == "Manager" && e.years >= 2)
            filtered.push_back(e);

    writeData("employees.txt", filtered);
    for(auto& e : filtered){
        e.id += 100;
        e.years += 1;
    }

    writeData("employees.txt", filtered);
    return 0;
}

