#include<iostream>
#include<vector>
#include<string>
using namespace std;

class User{
protected:
    string name;
    int id;
    string email;
    string hashed_password;
    vector<string> permissions;
public:
    User(string name, int id, string email, string password){
        this->name = name;
        this->id = id;
        this->email = email;
        this->hashed_password = hashPassword(password);
    }
    virtual void display() = 0;
    string hashPassword(string password){
        unsigned long hash = 5381;
        for(char c : password){
            hash = (hash*33)+c;
        }
        return to_string(hash);
    }

    bool authenticate(string password){
        return hashPassword(password) == hashed_password;
    }

    virtual void accessLab(){
        for(const auto& perm : permissions){
            cout<<perm<<endl;
        }
    }

    void addPermission(string permission){
        permissions.push_back(permission);
    }
};

class Student : public User{
    vector<int> assignments;
public:
    Student(string name, int id, string email, string password, int num_assignments)
        : User(name, id, email, password){
        for(int i=0;i<num_assignments;i++){
            assignments.push_back(0);
        }
        addPermission("submit assignment");
    }

    void display() override{
        cout<<"Student Name: "<<name<<", ID: "<<id<<", Email: "<<email<<endl;
    }

    void submitAssignment(int index){
        if(index >= 0 && index < assignments.size()){
            assignments[index] = 1;
            cout<<"Assignment "<<index + 1<<" submitted."<<endl;
        }
    }

    void viewAssignments(){
        for(int i=0;i<assignments.size();i++){
            cout << "Assignment " << i + 1 << ": " << (assignments[i] == 1 ? "Submitted" : "Not Submitted") << endl;
        }
    }
};

class TA : public Student{
    vector<Student*> students;
    vector<string> projects;
public:
    TA(string name, int id, string email, string password, int num_assignments)
        : Student(name, id, email, password, num_assignments){
        addPermission("view projects");
        addPermission("manage students");
    }

    void display() override{
        cout<<"TA Name: "<<name<<", ID: "<<id<<", Email: "<<email<<endl;
    }

    void assignStudent(Student* student){
        if(students.size()<10){
            students.push_back(student);
            cout<<"Student "<<student->name<<" assigned to TA."<<endl;
        }
    }

    void viewProjects(){
        for(const auto& project : projects){
            cout<<"Project: "<<project<<endl;
        }
    }

    void startNewProject(string project){
        if(projects.size()<2){
            projects.push_back(project);
            cout<<"Project '"<<project<<"' started."<<endl;
        }
    }

    void assignProject(string project){
        if(projects.size()<2){
            projects.push_back(project);
            cout<<"Assigned project: "<<project<<endl;
        }
    }
};

class Professor : public User{
    vector<TA*> tas;
    vector<string> projects;
public:
    Professor(string name, int id, string email, string password)
        : User(name, id, email, password){
        addPermission("assign projects");
        addPermission("full lab access");
    }

    void display() override{
        cout<<"Professor Name: "<<name<<", ID: "<<id<<", Email: "<<email<<endl;
    }

    void assignProject(string project){
        projects.push_back(project);
        cout<<"Project '"<<project<<"' assigned to lab."<<endl;
    }

    void workWithTA(TA* ta){
        if(tas.size()<10){
            tas.push_back(ta);
            cout<<"TA "<<ta->name<<" is working with Professor."<<endl;
        }
    }

    void viewProjects(){
        for(const auto& project : projects){
            cout<<"Project: "<<project<<endl;
        }
    }
};

void authenticateAndPerformAction(User* user, string action){
    string password;
    cout<<"Enter password: ";
    cin>>password;

    if(user->authenticate(password)){
        cout<<"Authentication successful!"<<endl;

        if(action == "submit assignment"){
            if(Student* student = dynamic_cast<Student*>(user)){
                student->viewAssignments();
                int assignmentNum;
                cout<<"Enter assignment number to submit: ";
                cin>>assignmentNum;
                student->submitAssignment(assignmentNum - 1);
            }
        }else if(action == "view projects"){
            if(TA* ta = dynamic_cast<TA*>(user)){
                ta->viewProjects();
            }else if(Professor* prof = dynamic_cast<Professor*>(user)){
                prof->viewProjects();
            }
        }else if(action == "manage_students"){
            if(TA* ta = dynamic_cast<TA*>(user)){
                Student* student = new Student("Student A", 1001, "studentA@mail.com", "12345", 3);
                ta->assignStudent(student);
            }
        }else if(action == "assign projects"){
            if(Professor* prof = dynamic_cast<Professor*>(user)){
                string project;
                cout<<"Enter project name to assign: ";
                cin>>project;
                prof->assignProject(project);
            }
        }else if(action == "full_lab_access"){
            cout<<"Full lab access granted."<<endl;
        }else{
            cout<<"Invalid action!"<<endl;
        }
    }else{
        cout<<"Authentication failed!"<<endl;
    }
}

int main(){
    Student student1("John Doe", 1001, "john.doe@mail.com", "password123", 5);
    TA ta1("Alice", 2001, "alice@mail.com", "password123", 5);
    Professor prof1("Dr. Smith", 3001, "dr.smith@mail.com", "password123");

    student1.display();
    ta1.display();
    prof1.display();

    authenticateAndPerformAction(&student1, "submit assignment");
    authenticateAndPerformAction(&ta1, "view projects");
    authenticateAndPerformAction(&prof1, "assign projects");

    return 0;
}

