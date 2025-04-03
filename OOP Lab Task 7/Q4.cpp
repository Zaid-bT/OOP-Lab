#include<iostream>
#include <vector>
using namespace std;


class Person{
protected:
    string name, id;
public:
    Person(string n, string i) : name(n), id(i){}

    virtual void displayInfo(){
        cout<<"Name: "<<name<<"\nID: "<<id<<endl;
    }
};


class Student : public Person{
    double GPA;
public:
    Student(string n, string i, double gpa) : Person(n, i), GPA(gpa){}

    void displayInfo() override{
        Person::displayInfo();
        cout<<"GPA: "<<GPA<<endl;
    }
};


class Professor : public Person{
    string department;
public:
    Professor(string n, string i, string dept) : Person(n, i), department(dept){}

    void displayInfo() override{
        Person::displayInfo();
        cout<<"Department: "<<department<<endl;
    }
};


class Staff : public Person{
    string position;
public:
    Staff(string n, string i, string pos) : Person(n, i), position(pos) {}

    void displayInfo() override{
        Person::displayInfo();
        cout<<"Position: "<<position<<endl;
    }
};


class Course{
    string courseId, courseName;
public:
    Course(string id, string name) : courseId(id), courseName(name) {}

    void displayCourseInfo() {
        cout << "Course ID: " << courseId << "\nCourse Name: " << courseName << endl;
    }
};


int main(){
    Student s1("Alice", "S001", 3.8);
    Professor p1("Dr. Smith", "P101", "Computer Science");
    Staff st1("John Doe", "ST301", "Manager");
    Course c1("CS101", "Intro to Programming");

    
    cout << "\nStudent Info:\n";
    s1.displayInfo();

    cout << "\nProfessor Info:\n";
    p1.displayInfo();

    cout << "\nStaff Info:\n";
    st1.displayInfo();

    cout << "\nCourse Info:\n";
    c1.displayCourseInfo();

    return 0;
}

