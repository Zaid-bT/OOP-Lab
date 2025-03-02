#include <iostream>
#include <string>
#include <tuple> //used for returning multiple values

using namespace std;

class Robot{
    string name;
    int hits;
    
	public:
    	Robot(const string& name) : name(name),hits(0) {}

    	void hitBall(int &ballX,int &ballY,const string &direction){
        if(direction == "up"){
            ballY += 1;
        }else if(direction == "down"){
            ballY -= 1;
        }else if(direction == "left"){
            ballX -= 1;
        }else if(direction == "right"){
            ballX += 1;
        }
        hits++;
    }

    	int getHits() const {
        	return hits;
    	}

    	string getName() const {
        	return name;
    	}
};

class Team{
    string teamName;
    Robot* robot;

	public:
    	Team(const string& teamName, Robot* robot) : teamName(teamName),robot(robot) {}

    	string getTeamName() const{
        	return teamName;
    	}

    	Robot* getRobot() const{
        	return robot;
    	}
};

class Ball{
    int x, y;

	public:
    	Ball() : x(0),y(0) {}

    	void move(int dx, int dy){
        	x += dx;
        	y += dy;
    	}

    	tuple<int, int> getPosition() const{
        	return make_tuple(x, y);
    	}

    	int getX() const{
        	return x;
    	}

    	int getY() const{
        	return y;
    	}

    	bool isGoalReached(int goalX, int goalY) const{
        	return (x == goalX && y == goalY);
    	}
};

class Goal{
    int x, y;

	public:
    	Goal(int x, int y) : x(x),y(y) {}

    	tuple<int, int> getPosition() const{
        	return make_tuple(x, y);
    	}
};

class Game{
    Team* teamOne;
    Team* teamTwo;
    Ball ball;
    Goal goal;

	public:
    	Game(Team* teamOne, Team* teamTwo, Goal goal) : teamOne(teamOne),teamTwo(teamTwo),goal(goal) {}

    	void startGame(){
        	play(teamOne);
        	play(teamTwo);
        	declareWinner();
    	}

    	void play(Team* team){
        	Robot* robot = team->getRobot();
        	int ballX = 0, ballY = 0;
        	string directions[] = {"right", "right", "up", "up"};

        	cout<<team->getTeamName()<<"'s turn:"<<endl;
        	int directionIndex=0;

        	while(!ball.isGoalReached(get<0>(goal.getPosition()),get<1>(goal.getPosition()))){
            	robot->hitBall(ballX, ballY, directions[directionIndex % 4]);
            	cout<<"Ball Position: ("<<ballX<<", "<<ballY<<")"<<endl;

            if(ball.isGoalReached(get<0>(goal.getPosition()),get<1>(goal.getPosition()))){
                cout<<team->getTeamName()<<" reached the goal in "<<robot->getHits()<<" hits!"<<endl;
                break;
            }
            directionIndex++;
        	}
    	}

    	void declareWinner(){
        	int hitsTeamOne = teamOne->getRobot()->getHits();
        	int hitsTeamTwo = teamTwo->getRobot()->getHits();

        	if(hitsTeamOne < hitsTeamTwo){
            	cout<< teamOne->getTeamName()<<" wins!"<<endl;
        	}else if(hitsTeamOne > hitsTeamTwo){
            	cout<<teamTwo->getTeamName()<<" wins!"<<endl;
        	}else{
            	cout<<"It's a tie!"<<endl;
        	}
    	}
};

int main(int argc, char* argv[]){
	cout<<"Zaid Bin Tariq....24K-0789\n\n";
	
	
    Robot robotOne("RobotOne");
    Robot robotTwo("RobotTwo");

    Team teamOne("Team A", &robotOne);
    Team teamTwo("Team B", &robotTwo);

    Goal goal(3, 3);

    Game game(&teamOne, &teamTwo, goal);

    game.startGame();

    return 0;
}

