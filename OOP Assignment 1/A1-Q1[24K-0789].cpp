#include <iostream>
#include <string>
using namespace std;

//class Skill{};
class Student{};
//class Mentor{};
//class Sport{};

class Skill{
    int skillID;
    string skillName;
    string description;
    
	public:
    	Skill(int id = 0, const string& name = "", const string& desc = "")
        	: skillID(id), skillName(name), description(desc) {}

    	void showSkillDetails() const {
        	cout<<"Skill ID: "<<skillID<<"\nSkill Name:"<<skillName<<"\nDescription: "<<description<<endl;
    	}	

    	void updateSkillDescription(const string& newDescription) {
        	description = newDescription;
    	}

    	int getSkillID() const{ 
			return skillID; 
		}

    	void clearSkill(){
        	skillID = 0;
        	skillName = "";
        	description = "";
    	}
};

class Sport{
    int sportID;
    string name;
    string description;
    Skill requiredSkills[10];
    int skillCount;

	public:
    	Sport(int id = 0,const string& sportName = "",const string& desc = "")
        	: sportID(id), name(sportName), description(desc), skillCount(0) {}

    	void addSkill(const Skill& skill){
        	if(skillCount < 10){
            	requiredSkills[skillCount++] = skill;
        	}else{
            	cout<<"Skills limit reached.\n";
        	}
    	}

    	void removeSkill(int skillID){
        	for(int i = 0;i<skillCount;i++){
            	if(requiredSkills[i].getSkillID() == skillID){
                	requiredSkills[i].clearSkill();
                	cout<<"Skill removed.\n";
                	return;
            	}
        	}
        	cout<<"Skill not found.\n";
    	}

    	void showSportDetails() const{
        	cout<<"Sport ID: "<<sportID<<"\nName: "<<name<<"\nDescription: "<<description<<"\nRequired Skills:\n";
        	for(int i = 0;i<skillCount;i++){
            	requiredSkills[i].showSkillDetails();
        	}
    	}
};

class Mentor{
    int mentorID;
    string name;
    Sport sportsExpertise[3];
    int expertiseCount;
    int maxLearners;
    Student assignedLearners[5];
    int learnerCount;

	public:
    	Mentor(int id = 0,const string& mentorName = "",int capacity = 3)
        	: mentorID(id),name(mentorName),expertiseCount(0),maxLearners(capacity),learnerCount(0) {}

//   	void assignLearner(Student& student);

    	void removeLearner(const string& studentName){
        	for(int i=0;i<learnerCount;i++){
            	if(assignedLearners[i].getName() == studentName){
                	assignedLearners[i] = assignedLearners[learnerCount-1];
                	learnerCount--;
            	    break;
            	}
        	}
    	}

    	void viewLearners() const{
        	cout<<"Mentor "<<name<<"'s Learners:\n";
        	for(int i=0;i<learnerCount;i++){
            	cout<<assignedLearners[i].getName()<<endl;
        	}
    	}

    	void provideGuidance() const{
        	cout<<"Providing guidance to all learners.\n";
    	}

    	void showMentorDetails() const{
        	cout<<"Mentor ID: "<<mentorID<<"\nName: "<<name<<"\nMax Learners: "<<maxLearners<<endl;
    	}

    	string getName() const{ 
			return name; 
		}

    	void assignLearner(Student& student){
    		if(learnerCount<maxLearners){
        		assignedLearners[learnerCount++] = student;
    		}else{
        		cout<<"Mentor limit reached.\n";
    		}
		}
};

class Student{
    int studentID;
    string name;
    int age;
    Sport sportsInterests[5];
    int interestCount;
    Mentor mentorAssigned;

	public:
    	Student(int id=0,const string& studentName = "", int studentAge=0)
        	: studentID(id),name(studentName),age(studentAge),interestCount(0),mentorAssigned() {}

    	void updateSportsInterest(const Sport& sport){
        	if(interestCount < 5){
            	sportsInterests[interestCount++] = sport;
        	}else{
            	cout<<"Cannot add more sports interests.\n";
        	}
    	}

    	void registerForMentorship(Mentor& mentor){
        	mentor.assignLearner(*this);
        	mentorAssigned = mentor;
    	}

   		void viewMentorDetails() const{
    	    mentorAssigned.showMentorDetails();
   		}

    	void showStudentDetails() const{
        	cout<<"Student ID: "<<studentID<<"\nName: "<<name<<"\nAge: "<<age<<endl;
    	}

    	string getName(){ 
			return name; 
		}
};

int main(){
	cout<<"Zaid Bin Tariq....24K-0789\n\n";
	
    Skill s1(1, "Fronthand", "Improve your fronthand shot.");
    Sport tennis(1, "Table Tennis", "A competitive racket sport.");
    TableTennis.addSkill(s1);

    Student waqas(1001, "Waqas", 18);
    Mentor ali(2002, "Ali", 3);

    waqas.updateSportsInterest(TableTennis);
    waqas.registerForMentorship(ali);
    ali.viewLearners();

    waqas.viewMentorDetails();
    TableTennis.showSportDetails();

    return 0;
}
