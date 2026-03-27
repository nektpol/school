#pragma once

#include <string>
#include "Student.h"

class TeamMember
{
private:

	int mo;
	std::string name;
	std::string nickname;
	int maxScore;
	int maxFouls;
	std::string coach;
	std::string specialty;

	Student team[5];
	

public:

	TeamMember(int mo, std::string name, std::string nickname,
		int maxScore, int maxFouls,
		std::string coach, std::string specialty,
		Student st1, Student st2, Student st3, Student st4, Student st5);

	// Getters
	int getMO();
	std::string getName();
	std::string getNickname();
	int getMaxScore();
	int getMaxFouls();
	std::string getCoach();
	std::string getSpecialty();

	// Setters
	void setName(std::string name);
	void setNickname(std::string nickname);
	void setMaxScore(int maxScore);
	void setMaxFouls(int maxFouls);
	void setCoach(std::string coach);
	void setSpecialty(std::string specialty);

	// Prints team details and roster in a readable multi-line format.
	void print() const;
	
};
