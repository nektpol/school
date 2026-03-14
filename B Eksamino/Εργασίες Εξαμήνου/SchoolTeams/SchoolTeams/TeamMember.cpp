#include "TeamMember.h"
#include <iostream>

TeamMember::TeamMember(int mo, std::string name, std::string nickname,
	int maxScore, int maxFouls,
	std::string coach, std::string specialty,
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

std::string TeamMember::getName() { return name; }

std::string TeamMember::getNickname() { return nickname; }

int TeamMember::getMaxScore() { return maxScore; }

int TeamMember::getMaxFouls() { return maxFouls; }

std::string TeamMember::getCoach() { return coach; }

std::string TeamMember::getSpecialty() { return specialty; }

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
	std::cout << "==============================\n";
	std::cout << "Team MO: " << mo << '\n';
	std::cout << "Team Name: " << name << " (" << nickname << ")" << '\n';
	std::cout << "Coach: " << coach << '\n';
	std::cout << "Specialty: " << specialty << '\n';
	std::cout << "Max Score: " << maxScore << '\n';
	std::cout << "Max Fouls: " << maxFouls << '\n';
	std::cout << "Players (AM): "
		<< player1 << ", " << player2 << ", " << player3 << ", " << player4 << ", " << player5
		<< '\n';
}
