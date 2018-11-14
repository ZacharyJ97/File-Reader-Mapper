#ifndef DATA_H
#define DATA_H
#include <string>
#include <vector>
#include "Student.h"
#include <map>
#include <utility>

class DataManager
{
public:
	DataManager(const std::string &);
	void addStudent(Student);
	void display();
	Student& findStudent(int);

	~DataManager();

private:
	//2nd data member?
	//std::vector<Student> Students; old vector
	//The idea is that the student id will be the unique key id with the value being the corresponding student
	typedef std::map <int, Student > StudentMap;
	StudentMap studentMap;
	std::vector<std::string> splitString(const std::string &, char);
	void readDataFile(const std::string &);
	void writeDataFile();

};

#endif

