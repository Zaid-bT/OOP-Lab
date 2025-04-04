#include<iostream>
#include<vector>
#include<cstdlib>
#include<ctime>
#include<string>
using namespace std;

class Visitor;

class Ghost{
protected:
    string name;
    int scareLevel;
public:
    Ghost(string name) : name(name), scareLevel(rand() % 10 + 1) {}
    virtual void haunt(Visitor& visitor) = 0;
    int getScareLevel() const{
        return scareLevel;
    }

    virtual ~Ghost(){}
};

class SimpleGhost : public Ghost{
public:
    SimpleGhost(string name) : Ghost(name) {}
    void haunt(Visitor& visitor) override;
};

class ScaryGhost : public Ghost{
public:
    ScaryGhost(string name) : Ghost(name) {}
    void haunt(Visitor& visitor) override;
};

class VeryScaryGhost : public Ghost{
public:
    VeryScaryGhost(string name) : Ghost(name){}
    void haunt(Visitor& visitor) override;
};

class Visitor{
    string name;
    int bravery;
public:
    Visitor(string name, int bravery) : name(name), bravery(bravery){}
    void visitHouse(class HauntedHouse& hauntedHouse);

    int getBravery() const{
        return bravery;
    }

    string getName() const{
        return name;
    }
};

class HauntedHouse{
    string name;
    vector<Ghost*> ghosts;
public:
    HauntedHouse(string name) : name(name) {}

    void addGhost(Ghost* ghost){
        ghosts.push_back(ghost);
    }

    void showGhosts(){
        for (auto& ghost : ghosts){
            cout << ghost->getScareLevel()<<endl;
        }
    }

    vector<Ghost*> getGhosts(){
        return ghosts;
    }

    string getName() const{
        return name;
    }
};

void SimpleGhost::haunt(Visitor& visitor){
    int bravery = visitor.getBravery();
    if(getScareLevel() < bravery - 2){
        cout << visitor.getName()<<" laughs at the Simple Ghost!"<<endl;
    }else if(getScareLevel()>bravery + 2){
        cout << visitor.getName()<<" screams and runs away from the Simple Ghost!"<<endl;
    }else{
        cout << visitor.getName()<<" gets a shaky voice in front of the Simple Ghost!"<<endl;
    }
}

void ScaryGhost::haunt(Visitor& visitor){
    int bravery = visitor.getBravery();
    if(getScareLevel() < bravery - 2){
        cout << visitor.getName()<<" mocks the Scary Ghost!"<<endl;
    }else if(getScareLevel() > bravery + 2){
        cout << visitor.getName()<<" runs away from the Scary Ghost!"<<endl;
    }else{
        cout << visitor.getName()<<" gets a shaky voice in front of the Scary Ghost!"<<endl;
    }
}

void VeryScaryGhost::haunt(Visitor& visitor){
    int bravery = visitor.getBravery();
    if(getScareLevel() < bravery - 2){
        cout << visitor.getName()<<" taunts the Very Scary Ghost!"<<endl;
    }else if(getScareLevel() > bravery + 2){
        cout << visitor.getName()<<" screams and runs from the Very Scary Ghost!"<<endl;
    }else{
        cout << visitor.getName()<<" gets a shaky voice in front of the Very Scary Ghost!"<<endl;
    }
}

void Visitor::visitHouse(HauntedHouse& hauntedHouse){
    cout << "Visitors entering the Haunted House: "<<hauntedHouse.getName()<<endl;
    for(auto& ghost : hauntedHouse.getGhosts()){
        ghost->haunt(*this);
    }
}

int main(){
    srand(time(0));

    HauntedHouse house1("Spooky Mansion");
    HauntedHouse house2("Ghostly Manor");

    SimpleGhost* g1 = new SimpleGhost("Simple Ghost A");
    ScaryGhost* g2 = new ScaryGhost("Scary Ghost A");
    VeryScaryGhost* g3 = new VeryScaryGhost("Very Scary Ghost A");

    house1.addGhost(g1);
    house1.addGhost(g2);

    house2.addGhost(g3);

    Visitor visitor1("John", 5);
    Visitor visitor2("Alice", 9);
    Visitor visitor3("Bob", 3);

    Visitor visitors[] ={visitor1, visitor2, visitor3};

    cout <<"\n-- Haunted House 1 --\n";
    house1.showGhosts();
    for(Visitor& v : visitors){
        v.visitHouse(house1);
    }

    cout <<"\n-- Haunted House 2 --\n";
    house2.showGhosts();
    for(Visitor& v : visitors){
        v.visitHouse(house2);
    }

    delete g1;
    delete g2;
    delete g3;

    return 0;
}

