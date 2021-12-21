#pragma once
	#include <fstream>
	#include "StudentInfo.h"
	#include "Classroom.h"

const string FILE_PATH = "Data.txt";


class FileStructure {
	public:
		int numberOfClass;
		LinkedList<Classroom> classroomList;
};

void writeFile(FileStructure file){
    fstream fileOut;
    fileOut.open(FILE_PATH, ios::out|ios::app);
	fileOut.close();
}

bool compare(Classroom A, Classroom B){
	return A.numberOfStudent <= B.numberOfStudent;
}

bool compare(StudentInfo A, StudentInfo B){
	return A.name.compare(B.name) >= 0;
}

/* Read the record file and convert all file into FileStructure Object */
FileStructure readFile(){
	/* Open input file */
	fstream fileInp;
	fileInp.open(FILE_PATH, ios::in);
	FileStructure file = FileStructure();

	/* Get number of class */
	string line;
	getline(fileInp, line);
	file.numberOfClass = stoi(line);
	
	/* Get infomation of class */
	for (int i = 0; i < file.numberOfClass; i++){
		Classroom classroom;
		getline(fileInp, line);
		classroom.name = line;
		getline(fileInp, line);
		classroom.numberOfStudent = stoi(line);

		/* Get information of students */
		for (int j = 0; j < classroom.numberOfStudent; j++){
			getline(fileInp, line);

			stringstream s(line);
			vector<string> studentInfo;
			string field;
			while(getline(s, field, ',')){
				studentInfo.push_back(field);
			}

			/* Convert info into StudentInfo Object */
			StudentInfo info;
			info.studentId = studentInfo[0];
			info.name = studentInfo[1];
			info.sex = stoi(studentInfo[2]);
			info.date = stoi(studentInfo[3]);
			info.month = stoi(studentInfo[4]);
			info.year = stoi(studentInfo[5]);
			info.KTLT_Point = stof(studentInfo[6]);
			classroom.listStudent.addNodeWithOrder(info, compare);
		}
		cout << classroom;
		file.classroomList.addNodeWithOrder(classroom, compare);
	}
	fileInp.close();
	return file;
}
