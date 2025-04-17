#include<iostream>
#include<string>
using namespace std;

class Student{
public:
    virtual double getTuition(string status, int creditHours) = 0;
    virtual ~Student() {}
};

class GraduateStudent : public Student{
    string researchTopic;

public:
    double getTuition(string status, int creditHours) override {
        if(status == "undergraduate"){
            return creditHours * 200;
        }else if(status == "graduate"){
            return creditHours * 300;
        }else if(status == "doctoral"){
            return creditHours * 400;
        }
        return 0;
    }

    void setResearchTopic(string topic){
        researchTopic = topic;
    }

    string getResearchTopic() const{
        return researchTopic;
    }
};

int main(){
    GraduateStudent gradStudent;
    gradStudent.setResearchTopic("Quantum Computing");

    string status = "graduate";
    int creditHours = 12;

    cout << "Research Topic: " << gradStudent.getResearchTopic() << endl;
    cout << "Tuition for " << status << " student with " << creditHours << " credit hours: $"<< gradStudent.getTuition(status, creditHours) << endl;

    return 0;
}

