#include "stdafx.h"
#include "Student.h"
#include <string>
#include <iostream>

//Default Student
Student::Student()
{
	name = "Unknown";
	stu_major = "Undecided";
	stu_id = "11111111";
	stu_year = 0;
}

//Overloaded/4-parameter student
Student::Student(std::string new_name, std::string new_id, std::string new_major, int new_year) : name(new_name), stu_major(new_major), stu_id(new_id), stu_year(new_year) {}


//Set methods for each private variable
void Student::setStudentName(const std::string &input_name)
{
	name = input_name;
}

void Student::setStudentMajor(const std::string &input_major)
{
	stu_major = input_major;
}

//Set student ID with verfication of length requirement
void Student::setStudentID(const std::string &input_id)
{
	const int REQ_SIZE = 8;
	bool all_digits = false;
	stu_id = input_id;

	if (stu_id.length() != 8)
	{
		std::cout << "The entered student ID is not exactly 8 characters/digits long. The ID will be set to default 11111111." << std::endl;
		stu_id = "11111111";
	}
}

void Student::setStudentYear(int input_year)
{
	stu_year = input_year;
}


Student::~Student()
{
}
