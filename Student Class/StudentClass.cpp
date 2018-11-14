// StudentClass.cpp : Defines the entry point for the console application.
//

//Necessary Header files
#include "stdafx.h"
#include "Student.h"
#include <iostream>
#include <string>
#include <vector>
#include "DataManager.h"

int main()
{
	DataManager dm("../studentdata.txt");
	Student s1 = Student("Jian Yang", 11100011, "International Studies", "1");
	Student s2 = Student("Patrick Brocato", 11100010, "Women's Studies", "1");
	Student s3 = Student("Taylan Thomas", 10100011, "Liberal Arts", "1");
	Student s4 = Student("Meghan Raymond", 11000011, "Communications", "1");
	dm.addStudent(s1);
	dm.addStudent(s2);
	dm.addStudent(s3);
	dm.addStudent(s4);

	dm.display();
	std::cout << "\n" << std::endl;

	try
	{
		dm.findStudent(s2.getStudentID()).setStudentYear("2");
		dm.findStudent(s3.getStudentID()).setStudentMajor("Advanced Memes");
	}
	catch (const std::out_of_range error)
	{
		std::cout << "Student not Found, Map Iterator has gone out of range " << error.what() << std::endl;
	}

	dm.display();
}