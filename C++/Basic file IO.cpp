/*

Incomplete class assignment that I assisted another student with file I/O

/************************************************************************************************************
The file semgrades4.txt contains data for an unknown number of students in this format:
Line 1:		student name			
Line 2: 		six int quiz grades separated by a blank space
Line 3:		at least one (but possibly up to six) int project grades, separated by a blank space 
            			and terminated by -1
Line 4:  	two int exam grades
Line 5:  	int number of absences

Example of file entries:

Michael Palin
 70  30  70  80  85  90 
100 -1
 75  85
4
Eric Idle
 75  80  70  75  80  70
 70  80  90 100 -1
 70  88
0
*/

#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <fstream>
#include <string>
#include <stdio.h>

using namespace std;

//************************************************************************************************************
// Global Declarations


// file input object
ifstream inFile ("semgrades4.txt");		// input file stream variable
void testTest (ifstream&);
const int totalClasses = 30;
const int totalQuizzes = 6;
const int maxProjects = 6;
const int totalExams = 2;

//functional prototype
int getInt(ifstream&);

// struct
	class Student		// class for class variable 
	{
		public:
		string studentName;					// Student name variable
		int quizGrades[totalQuizzes];				// quiz grades array
		int projGrades[maxProjects];				// project grades array	
		int totalProjects;	
		int examGrades[totalExams];
		int absences;
		float courseAvg;
		float adjustedAvg;
				
		public:
		void readIn (ifstream &inFile);		// read in function
		void printAll ();
		
	};
	// class variable defined within main

//**************************************************************************************************************
// Local/ Main

int main() {

testTest (inFile);

Student sOne = Student();

while (inFile.peek() != EOF){
	sOne.readIn(inFile);
	sOne.printAll();
}


	
return 0;

}
//****************************************************************************************

// Function definitions

void testTest (ifstream &infile){

// inFile test	
	if (inFile.fail()){ 
		cout << "Error has occured, file not sucessfully opened. " << endl; 
	}
		else {
		 	cout << "File has opened sucessfully. " << endl ; 
		}
		 	 
};

void Student::readIn (ifstream &inFile){			
	
	int i, j;
	getline(inFile, studentName);
	for(i = 0; i < totalQuizzes; ++i){
		quizGrades[i] = getInt(inFile);
	}
	for(i = 0; i < maxProjects; ++i){
		j = getInt(inFile);
		if(j == -1){
			totalProjects = i;
			i = maxProjects;
		}
		else{
			projGrades[i] = j;
		}
	}
	for(i = 0; i < totalExams; ++i){
		examGrades[i] = getInt(inFile);
	}
	absences = getInt(inFile); 	
}

int getInt(ifstream &inFile){
	
	int sign = 1;
	int magnitude = 0;
	char c;
	
	inFile.get(c);	
	while(c < '0' || c > '9'){
		if(c == '-'){
			c = inFile.peek();
			if(c >= '0' && c <= '9')
				sign = -1;
		}
			
		inFile.get(c);
	}
	
	while(c >= '0' && c <= '9'){
		magnitude *= 10;
		magnitude += (c - '0');
		inFile.get(c);
	}
	
	return sign * magnitude;
};

void Student:: printAll(){
	
	cout << studentName << endl;
	
	int i;
	cout << "Quizz Grades: ";
	for(i = 0; i < totalQuizzes; ++i){
		cout << quizGrades[i] << ' ';
	}
	cout << endl;
	
	cout << "Project Grades: ";
	for(i = 0; i < totalProjects; ++i){
		cout << projGrades[i] << ' ';
	}
	cout << endl;
	
	cout << "Exam Grades: ";
	for(i = 0; i < totalExams; ++i){
		cout << examGrades[i] << ' ';
	}
	cout << endl;
	
	cout << absences << endl;
	
};

