#include "Student.h"

#include <iostream>
#include <string>
using std::string;
using std::cout;

Student::Student(int am, string lastName, string firstName,
	string fatherName, string birthDate,
	string phone, string address, string specialty)
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

Student::Student(int am, string lastName, string firstName)
{
	this->am = am;
	this->lastName = lastName;
	this->firstName = firstName;
}

int Student::getAM() { return am; }

string Student::getLastName() { return lastName; }

string Student::getFirstName() { return firstName; }

string Student::getFatherName() { return fatherName; }

string Student::getBirthDate() { return birthDate; }

string Student::getPhone() { return phone; }

string Student::getAddress() { return address; }

string Student::getSpecialty() { return specialty; }

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
	cout << "------------------------------\n";
	cout << "Student AM: " << am << '\n';
	cout << "Name: " << firstName << " " << lastName << '\n';
	cout << "Father's Name: " << fatherName << '\n';
	cout << "Birth Date: " << birthDate << '\n';
	cout << "Phone: " << phone << '\n';
	cout << "Address: " << address << '\n';
	cout << "Specialty: " << specialty << '\n';
}
