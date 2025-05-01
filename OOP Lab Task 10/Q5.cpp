#include<iostream>
#include<fstream>
#include<vector>
#include<string>
using namespace std;

void addTask(const string& task){
    ofstream file("tasks.txt", ios::app);
    file << task << ",not done\n";
    file.close();
}

void viewTasks(){
    ifstream file("tasks.txt");
    string line;
    int index = 1;
    while(getline(file, line)){
        cout << index++ << ". " << line << endl;
    }
    file.close();
}

void markTaskDone(int taskNumber){
    ifstream file("tasks.txt");
    vector<string> lines;
    string line;
    int count = 0;
    while(getline(file, line)){
        count++;
        if(count == taskNumber && line.find(",not done") != string::npos){
            line.replace(line.find(",not done"), 9, ",done");
        }
        lines.push_back(line);
    }
    file.close();

    ofstream out("tasks.txt");
    for(const auto& l : lines)
        out << l << endl;
    out.close();
}

int main(){
    int choice;
    cout << "1. Add Task\n2. View Tasks\n3. Mark Task Done\nChoice: ";
    cin >> choice;
    cin.ignore();
    if(choice == 1){
        string task;
        cout << "Enter task: ";
        getline(cin, task);
        addTask(task);
    }else if(choice == 2){
        viewTasks();
    }else if(choice == 3){
        int taskNum;
        viewTasks();
        cout << "Enter task number to mark as done: ";
        cin >> taskNum;
        markTaskDone(taskNum);
    }
    return 0;
}

