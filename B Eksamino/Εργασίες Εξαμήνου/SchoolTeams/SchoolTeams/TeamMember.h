#pragma once

#include <string>

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

	int player1;
	int player2;
	int player3;
	int player4;
	int player5;

public:

	TeamMember(int mo, std::string name, std::string nickname,
		int maxScore, int maxFouls,
		std::string coach, std::string specialty,
		int p1, int p2, int p3, int p4, int p5);

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
