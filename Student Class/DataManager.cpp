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

	//Loops through the vector and asks student class for its display
	for (Student s : Students)
	{
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

	//For each student in the pass vector, parse up its elements, separate by tabs for file format specifications and put into ostream
	for (Student s : Students)
	{
		std::string name = s.getStudentName();
		std::string id = s.getStudentID();
		std::string major = s.getStudentMajor();
		std::string year = s.getStudentYear();

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
			std::string id = fields[1];
			std::string major = fields[2];
			std::string year = fields[3];

			//Forming new Student
			newStu.setStudentID(id);
			newStu.setStudentYear(year);
			newStu.setStudentName(name);
			newStu.setStudentMajor(major);

			Students.push_back(newStu);

		}


	}
	input.close();
}

//Adds a passed student object to our student vector if not already present
void DataManager::addStudent(Student student)
{
	//Bool for testing
	bool ok = true;
		//loop for each object in student then compare student IDs for match
		for (auto s : Students)
		{
			//If match, change the bool because we can't allow duplicate data
			std::string dif_id = s.getStudentID();
			if (student.getStudentID() == dif_id)
			{
				ok = false;
				break;
			}
			
		}

	//if ok is still true then we can add student to the vector
	if (ok)
	{
		Students.push_back(student);
	}
	else
	{
		std::cout << "Student not added due to duplicate data";
	}
	
}

//Loops through Student vector looking for matching student ID
Student& DataManager::findStudent(const std::string &stu_id)
{
	try
	{
		for (Student s : Students)
		{
			std::string testID = s.getStudentID();
			if (stu_id == testID)
			{
				return s;
			}
		}
		
	}
	catch (const std::out_of_range& error)
	{
		std::cout << "Out of Range Error " << error.what() << std::endl;
		
	}
}
