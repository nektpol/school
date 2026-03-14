#pragma once

#include <string>

class Student
{
private:

	int am;
	std::string lastName;
	std::string firstName;
	std::string fatherName;
	std::string birthDate;
	std::string phone;
	std::string address;
	std::string specialty;

public:

	// Constructors
	Student(int am, std::string lastName, std::string firstName,
		std::string fatherName, std::string birthDate,
		std::string phone, std::string address, std::string specialty);

	Student(int am, std::string lastName, std::string firstName);

	// Getters
	int getAM();
	std::string getLastName();
	std::string getFirstName();
	std::string getFatherName();
	std::string getBirthDate();
	std::string getPhone();
	std::string getAddress();
	std::string getSpecialty();

	// Setters
	void setLastName(std::string lastName);
	void setFirstName(std::string firstName);
	void setFatherName(std::string fatherName);
	void setBirthDate(std::string birthDate);
	void setPhone(std::string phone);
	void setAddress(std::string address);
	void setSpecialty(std::string specialty);

	// Prints student details in a readable multi-line format.
	void print() const;
};

