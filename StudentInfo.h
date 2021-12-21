#pragma once
	#include <bits/stdc++.h>
using namespace std;
class StudentInfo {
	public:
		string studentId;
		string name;
		int sex;
		int date, month, year;
		double KTLT_Point;

		StudentInfo(){
		}

		StudentInfo(string studentId, string name, int sex, int date, int month, int year, double KTLT_Point){
			this->studentId = studentId;
			this->name = name;
			this->sex = sex;
			this->date = date;
			this->month = month;
			this->year = year;
			this->KTLT_Point = KTLT_Point;
		}

		/* Convert class into String to write/print to file */
		string toString(){
			string ans = "";
			ans += this->studentId;
			ans += ",";
			ans += this->name;
			ans += ",";
			ans += to_string(this->sex);
			ans += ",";
			ans += to_string(this->date);
			ans += ",";
			ans += to_string(this->month);
			ans += ",";
			ans += to_string(this->year);
			ans += ",";
			ans += to_string(this->KTLT_Point);
			ans += "\n";
			return ans;
		}

		static string bottomBorder(){
			return "└──────────┴────────────────────┴──────────┴─────────────┴─────┘\n";
		}
};


bool compareName(StudentInfo a, StudentInfo b){
	string nameA = a.name;	
	string nameB = b.name;
	cout << nameA << " " << nameB;
	return true;
}


/* Print to file Operator */
fstream& operator << (fstream& fs, const StudentInfo& data){
	fs << data.studentId << "," 
		<< data.name << ","
		<< data.sex << ","
		<< data.date << ","
		<< data.month << ","
		<< data.year << ","
		<< data.KTLT_Point << "\n";
	return fs;
}

/* Debug print operator -> Print all class fields */
ostream& operator << (ostream& os, const StudentInfo& data){
	os	<< "|" <<setw(10) << data.studentId << right 
		<< "|" << setw(20) << data.name << right
		<< "|" << setw(10) << data.sex << right
		<< "|" << setw(3) << data.date << right
		<< "/" << setw(3) << data.month << right
		<< "/" << setw(5) << data.year << right
		<< "|" << setw(5) <<data.KTLT_Point << "|\n";

	return os;
}

