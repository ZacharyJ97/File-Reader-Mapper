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
	Student s1 = Student("Jian Yang", "11100011", "International Studies", "1");
	Student s2 = Student("Patrick Brocato", "11100010", "Women's Studies", "1");
	Student s3 = Student("Taylan Thomas", "10100011", "Liberal Arts", "1");
	Student s4 = Student("Meghan Raymond", "11000011", "Communications", "1");
	dm.addStudent(s1);
	dm.addStudent(s2);
	dm.addStudent(s3);
	dm.addStudent(s4);

	dm.display();
	std::cout << "\n" << std::endl;

	//Default test variable of Student Class
	Student myStudent;

	//Multi parameter made Students
	Student myStudent2("Chase", "00000001", "Computer Science", "2");
	Student myStudent3("Jasmine", "00000142", "Psychology", "3");
    
	//Vector to hold students
	std::vector<Student> students = { myStudent, myStudent2, myStudent3 };

	//Print out each student info in the vector
	for (Student s : students)
	{
		std::cout << "Name: " << s.getStudentName() << std::endl << "ID: " << s.getStudentID() << std::endl << "Major: " << s.getStudentMajor() << std::endl << "Current Year: " << s.getStudentYear() << std::endl << std::endl;
	}

	//Vector re-assignment variables
	Student first_student = students[0];
	Student *p_second_student = &students[1];
	Student &r_third_student = students[2];

	//Setting different variables among the vector elements
	first_student.setStudentID("00000011");
	p_second_student->setStudentMajor("Liberal Arts"); 
	r_third_student.setStudentYear("1");

	//This is just formatting some clarity for my purpose in the output
	std::cout << "------------------------------" << std::endl;

	//Printing new vector results
	for (Student s1 : students)
	{
		std::cout << "Name: " << s1.getStudentName() << std::endl << "ID: " << s1.getStudentID() << std::endl << "Major: " << s1.getStudentMajor() << std::endl << "Current Year: " << s1.getStudentYear() << std::endl << std::endl;
	}

	/* The pointer successfully changed the Major of Chase to Liberal Arts
		The reference successfully changed the year of Jasmine to 1 from 3
		The first student's ID was not changed because of a copy by value issue where I have a version
		of that student with ID 00000011, but the vector still holds the value of the first student
		with an ID 11111111
	*/

}

