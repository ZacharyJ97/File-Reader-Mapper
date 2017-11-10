#ifndef DATA_H
#define DATA_H
#include <string>;
#include <vector>;
#include "Student.h";

class DataManager
{
public:
	DataManager(const std::string &);
	void addStudent(Student);
	void display();
	Student& findStudent(const std::string &);

	~DataManager();

private:
	//2nd data member?
	std::vector<Student> Students;
	std::vector<std::string> splitString(const std::string &, char);
	void readDataFile(const std::string &);
	void writeDataFile();

};

#endif

