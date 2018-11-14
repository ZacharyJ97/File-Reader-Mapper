#include "stdafx.h"
#include "Student.h"
#include <string>
#include <iostream>
#include <fstream> 
#include <sstream> 
#include <iomanip>
#include <vector>
using namespace std;

//Default Student
Student::Student()
{
	name = "Unknown";
	stu_major = "Undecided";
	stu_id = 11111111;
	stu_year = "0";
}

//Overloaded/4-parameter student
Student::Student(std::string new_name, int new_id, std::string new_major, string new_year) : name(new_name), stu_major(new_major), stu_id(new_id), stu_year(new_year) {}


//Set methods for each private variable
void Student::setStudentName(const std::string &input_name)
{
	name = input_name;
}

//Setter function
void Student::setStudentMajor(const std::string &input_major)
{
	stu_major = input_major;
}

//Set student ID 
void Student::setStudentID(int input_id)
{
	stu_id = input_id;
}

//Setter function
void Student::setStudentYear(const std::string &input_year)
{
	stu_year = input_year;
}

//Display formmating for the student class
string Student::display()
{
	std::ostringstream stu_display;
	stu_display << std::left << std::setw(20) << Student::getStudentID() << std::left << std::setw(25) << Student::getStudentName() << std::left << std::setw(20) << Student::getStudentMajor() << std::right << std::setw(5) << Student::getStudentYear() << std::endl;
	string result_display = stu_display.str();
	return result_display;

}


Student::~Student()
{
}
