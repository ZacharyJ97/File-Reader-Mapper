//Student Class Header
#ifndef STU_H
#define STU_H

#include <string>

//Student class with private variables and public functions including Set and Get
class Student
{
	//Get functions fully defined in public, set functions defined in Student.cpp
public:
	//Default and multi-parameter functions
	Student(std::string, std::string, std::string, std::string);
	Student();
	~Student();

	//Operational functions to get and set
	void setStudentName(const std::string &);
	std::string getStudentName() const { return name; }

	void setStudentMajor(const std::string &);
	std::string getStudentMajor() const { return stu_major; }

	void setStudentID(const std::string &);
	std::string getStudentID() const { return stu_id; }

	void setStudentYear(const std::string &);
	std::string getStudentYear() { return stu_year; }

	//Display function
	std::string display();

private:
	//name of student
	std::string name;
	//major of study
	std::string stu_major;
	//student id number at least 8 digits
	std::string stu_id;
	//student class year in numbers from 1-4
	std::string stu_year;
	


};

#endif