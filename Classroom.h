#pragma once
	#include <bits/stdc++.h>
	#include "LinkList.h"
	#include "StudentInfo.h"

using namespace std;

class Classroom {
	public:
		string name;
		int numberOfStudent;
		LinkedList<StudentInfo> listStudent;

		/* Constructor */
		Classroom(){
		}
		Classroom(string name, int numberOfStudent, LinkedList<StudentInfo> listStudent){
			this->name = name;
			this->numberOfStudent = numberOfStudent;
			this->listStudent = listStudent;
		}

		/* Add a new student into classroom,
		input: StudentInfo Object
		This function add a new Node into StudentInfo LinkedList */
		void addNewStudent(StudentInfo data){
		};

		
		void modifyStudent(string StudentId){
		};
		
		void deleteStudent(string StudentId){
		};

		void printStudentList(){
		};
};

/* Print to file Operator */
fstream& operator << (fstream& fs, const Classroom& data){
	fs << data.name << endl
		<< data.numberOfStudent << endl;
	LinkedList<StudentInfo> listStudent = data.listStudent;
	listStudent.printLinkedList();
	return fs;
}

/* Debug operator : Print classroom with Students */
ostream& operator << (ostream& os, const Classroom& data){
	os << "Class name: " << data.name << endl
		<< "┌──────────┬────────────────────┬──────────┬─────────────┬─────┐\n"
		<< "|   MSSV   |     Ho va ten      | Gioi tinh|   Ngay Sinh |KTLT |\n"
		<< "├──────────┼────────────────────┼──────────┼─────────────┼─────┤\n";
	LinkedList<StudentInfo> listStudent = data.listStudent;
	listStudent.printNodeWithBorder(StudentInfo::bottomBorder());
	return os;
}


