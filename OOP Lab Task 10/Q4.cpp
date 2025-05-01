#include<iostream>
#include<fstream>
#include<filesystem>
using namespace std;
namespace fs = std::filesystem;

void writeLog(const string& message, const string& baseFile = "log.txt", size_t maxSize = 1024 * 1024) {
    ifstream in(baseFile, ios::binary | ios::ate);
    size_t size = in ? in.tellg() : 0;
    in.close();
    if(size >= maxSize){
        int index = 1;
        string newName;
        do{
            newName = "log" + to_string(index++) + ".txt";
        }while(fs::exists(newName));
        fs::rename(baseFile, newName);
    }
    ofstream out(baseFile, ios::app);
    out << message << endl;
    out.close();
}

int main(){
    for(int i = 0; i < 10000; ++i)
        writeLog("Log entry " + to_string(i));
    return 0;
}

