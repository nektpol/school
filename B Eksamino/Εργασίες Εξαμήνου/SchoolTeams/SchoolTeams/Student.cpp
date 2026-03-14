#include "Student.h"
#include <iostream>

Student::Student(int am, std::string lastName, std::string firstName,
	std::string fatherName, std::string birthDate,
	std::string phone, std::string address, std::string specialty)
{
	this->am = am;
	this->lastName = lastName;
	this->firstName = firstName;
	this->fatherName = fatherName;
	this->birthDate = birthDate;
	this->phone = phone;
	this->address = address;
	this->specialty = specialty;
}

Student::Student(int am, std::string lastName, std::string firstName)
{
	this->am = am;
	this->lastName = lastName;
	this->firstName = firstName;
}

int Student::getAM() { return am; }

std::string Student::getLastName() { return lastName; }

std::string Student::getFirstName() { return firstName; }

std::string Student::getFatherName() { return fatherName; }

std::string Student::getBirthDate() { return birthDate; }

std::string Student::getPhone() { return phone; }

std::string Student::getAddress() { return address; }

std::string Student::getSpecialty() { return specialty; }

void Student::setLastName(std::string lastName)
{
	this->lastName = lastName;
}

void Student::setFirstName(std::string firstName)
{
	this->firstName = firstName;
}

void Student::setFatherName(std::string fatherName)
{
	this->fatherName = fatherName;
}

void Student::setBirthDate(std::string birthDate)
{
	this->birthDate = birthDate;
}

void Student::setPhone(std::string phone)
{
	this->phone = phone;
}

void Student::setAddress(std::string address)
{
	this->address = address;
}

void Student::setSpecialty(std::string specialty)
{
	this->specialty = specialty;
}

void Student::print() const
{
	std::cout << "------------------------------\n";
	std::cout << "Student AM: " << am << '\n';
	std::cout << "Name: " << firstName << " " << lastName << '\n';
	std::cout << "Father's Name: " << fatherName << '\n';
	std::cout << "Birth Date: " << birthDate << '\n';
	std::cout << "Phone: " << phone << '\n';
	std::cout << "Address: " << address << '\n';
	std::cout << "Specialty: " << specialty << '\n';
}
