#include "TeamMember.h"
#include <iostream>
using std::string;
using std::cout;

TeamMember::TeamMember(int mo, string name, string nickname,
	int maxScore, int maxFouls,
	string coach, string specialty,
	Student st1, Student st2, Student st3, Student st4, Student st5)
	: mo(mo),
	name(name),
	nickname(nickname),
	maxScore(maxScore),
	maxFouls(maxFouls),
	coach(coach),
	specialty(specialty),
	team{st1, st2, st3, st4, st5} 
{}

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
	// Student getters are not const; copy each player before reading names.
	Student p1 = team[0];
	Student p2 = team[1];
	Student p3 = team[2];
	Student p4 = team[3];
	Student p5 = team[4];

	cout << "==============================\n";
	cout << "Team MO: " << mo << '\n';
	cout << "Team Name: " << name << " (" << nickname << ")" << '\n';
	cout << "Coach: " << coach << '\n';
	cout << "Specialty: " << specialty << '\n';
	cout << "Max Score: " << maxScore << '\n';
	cout << "Max Fouls: " << maxFouls << '\n';
	cout << "Players: "
		<< p1.getLastName() << ", "
		<< p2.getLastName() << ", "
		<< p3.getLastName() << ", "
		<< p4.getLastName() << ", "
		<< p5.getLastName() << '\n';
		
}
