#include "TeamMember.h"
#include <iostream>
using std::string;
using std::cout;

TeamMember::TeamMember(int mo, string name, string nickname,
	int maxScore, int maxFouls,
	string coach, string specialty,
	int p1, int p2, int p3, int p4, int p5)
{
	this->mo = mo;
	this->name = name;
	this->nickname = nickname;
	this->maxScore = maxScore;
	this->maxFouls = maxFouls;
	this->coach = coach;
	this->specialty = specialty;

	player1 = p1;
	player2 = p2;
	player3 = p3;
	player4 = p4;
	player5 = p5;
}

int TeamMember::getMO() { return mo; }

string TeamMember::getName() { return name; }

string TeamMember::getNickname() { return nickname; }

int TeamMember::getMaxScore() { return maxScore; }

int TeamMember::getMaxFouls() { return maxFouls; }

string TeamMember::getCoach() { return coach; }

string TeamMember::getSpecialty() { return specialty; }

void TeamMember::setName(std::string name)
{
	this->name = name;
}

void TeamMember::setNickname(std::string nickname)
{
	this->nickname = nickname;
}

void TeamMember::setMaxScore(int maxScore)
{
	this->maxScore = maxScore;
}

void TeamMember::setMaxFouls(int maxFouls)
{
	this->maxFouls = maxFouls;
}

void TeamMember::setCoach(std::string coach)
{
	this->coach = coach;
}

void TeamMember::setSpecialty(std::string specialty)
{
	this->specialty = specialty;
}

void TeamMember::print() const
{
	cout << "==============================\n";
	cout << "Team MO: " << mo << '\n';
	cout << "Team Name: " << name << " (" << nickname << ")" << '\n';
	cout << "Coach: " << coach << '\n';
	cout << "Specialty: " << specialty << '\n';
	cout << "Max Score: " << maxScore << '\n';
	cout << "Max Fouls: " << maxFouls << '\n';
	cout << "Players (AM): "
		<< player1 << ", " << player2 << ", " << player3 << ", " << player4 << ", " << player5
		<< '\n';
}
