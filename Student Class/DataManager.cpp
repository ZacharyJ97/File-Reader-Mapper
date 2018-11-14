#include "stdafx.h"
#include "DataManager.h"
#include <string>
#include <vector>
#include <iostream>
#include <fstream> 
#include <sstream> 
#include <iomanip>
#include <numeric>
#include <algorithm>

//DataManager constructor that accepts a file path string and calls readFile
DataManager::DataManager(const std::string &path)
{

	//std::vector<Student> Students;
	readDataFile(path);
}

//Deconstructor that calls a write vector back to file form function
DataManager::~DataManager()
{
	writeDataFile();

}

//Display the contents of the Student Vector
void DataManager::display()
{
	//Table header formatting
	std::cout << std::left << std::setw(20) << "Student ID" << std::left << std::setw(25) << "Name" << std::left << std::setw(20) << "Major" << std::right << std::setw(5) << "Year" << std::endl;
	std::cout << std::string(70, '-') << std::endl;

	//Loops through the map and asks student class for its display
	for (auto it = studentMap.cbegin(); it != studentMap.cend(); it++)
	{
		//the value of the iterator is a student stored in s
		Student s = it->second;
		//ask the found student to display itself
		std::cout << s.display();
	}

	//More formatting
	std::cout << std::string(70, '-') << std::endl;
}

//Takes the passed vector student contents and writes them to a tab delimited file
void DataManager::writeDataFile()
{
	std::ostringstream ostream;
	std::ofstream outputFileStream("studentdata.txt");

	//For each student in the map, parse up its elements, separate by tabs for file format specifications and put into ostream
	//Error with constant iterator?
	for (auto it = studentMap.begin(); it != studentMap.end(); it++)
	{
		//Taking the parts of the iterator returned second component, which is the value corresponding to a student
		std::string name = it->second.getStudentName();
		int id = it->second.getStudentID();
		std::string major = it->second.getStudentMajor();
		std::string year = it->second.getStudentYear();

		ostream << name << '\t' << id << '\t' << major << '\t' << year << std::endl;

	}

	//storing stream as string
	std::string output = ostream.str();
	//inserting string into output file stream
	outputFileStream << output;
	//Close file stream
	outputFileStream.close();

	
}


//This function aids reading files by parsing the lines into individual fields by the separating character (tabs)
std::vector<std::string> DataManager::splitString(const std::string &text, char sep)
{
	// Stores a single field
	std::string field;
	// Stores all fields in a vector
	std::vector<std::string> fields;

	// Open an input string stream passing it the file path text	
	std::istringstream inputStr(text);

	// Get a line of text from the stream but
	// split on the separator character (sep = \t); store token in 'field'
	while (getline(inputStr, field, sep))
	{
		//Putting that individual field into the fields vector
		fields.push_back(field);
	}

	return fields;
}

//This function reads the data file, calls splitstring, forms a student from each complete line of data and returns it
void DataManager::readDataFile(const std::string &file)
{
	
	// Stores all fields
	std::vector<std::string> fields;
	//Get text
	std::ifstream input(file);
	//Lines containing fields
	std::string line;
	//Student Object to be Made from data file fields
	Student newStu;

	//Test input correction
	if (input.fail())
	{
		std::cout << "File not found, Will exit..." << std::endl;
		exit(1);
	}

	//While we aren't at the end of the data file
	while (!input.eof())
	{
		//store a line from the input file into line
		getline(input, line);

		//fields stores the data found in line that is separated by tabs
		fields = splitString(line, '\t');

		//As long as there are four items in our fields vector
		//We will assign them to variables
		if (fields.size() == 4)
		{
			std::string name = fields[0];
			int id = std::stoi (fields[1]);
			std::string major = fields[2];
			std::string year = fields[3];

			//Forming new Student
			newStu.setStudentID(id);
			newStu.setStudentYear(year);
			newStu.setStudentName(name);
			newStu.setStudentMajor(major);

			int newStudentID = newStu.getStudentID();
			studentMap.insert({ newStudentID, newStu });

		}


	}
	input.close();
}

//Adds a passed student object to our student vector if not already present
void DataManager::addStudent(Student student)
{
	//Bool for testing
	bool ok = true;
	//new student variable
	Student new_student = student;
		//loop for each object in studentMap then compare student IDs for match
		for (auto it = studentMap.begin(); it != studentMap.end(); it++)
		{
			//If match, change the bool because we can't allow duplicate data
			int dif_id = it->second.getStudentID();
			if (new_student.getStudentID() == dif_id)
			{
				ok = false;
				break;
			}
			
		}

	//if ok is still true then we can add student to the vector
	if (ok)
	{
		int newStudentID = new_student.getStudentID();
		studentMap.insert({ newStudentID,new_student});
	}
	else
	{
		std::cout << "Student not added due to duplicate data";
	}
	
}

//Loops through Student map looking for matching student ID

//The parameter being the Map's key
Student& DataManager::findStudent(int stu_id)
{
	auto found_student_it = studentMap.find(stu_id);
	//Throwing possible out of range error
	if (found_student_it == studentMap.end())
	{
		throw std::out_of_range ("Student not Found");
		
	}
	//If not out of range then return the student iterator
	else
	{
		Student &found_Student = found_student_it->second;
		return found_Student;
		
	}
}
