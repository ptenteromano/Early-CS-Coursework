/* Philip Tenteromano 2/11/2017
 *
 * File contains the function definitions 
 * for the Student class
 *
 */

#include <iostream>
#include <string>
using namespace std;

#include "student.h"


//default constructor
Student::Student() {
	studentID = 100100;
	firstName = "None";
	lastName = "None";
	middleInitial = ' ';
	gender = 'M';
	month = 01;
	day = 01;
	year = 2000;
}	

//overloaded constructor, with embedded private helper to set birthdate
Student::Student(string fname, char middle, string lname, int m, int d, int y) {
	firstName = fname;
	lastName = lname;
	middleInitial = middle;
	SetBirth(m, d, y);
}

//user input to change the first, last, and middle names
void Student::SetName(string fname, char middle, string lname) {
	firstName = fname;
	lastName = lname;
	middleInitial = middle;
	return;
}

//user input to change the studentID
void Student::SetID(int Id) {
	cout<<"Input a 6 digit Student ID#: ";
	cin>>Id;

	studentID = Id;
	return;
}

//user input function to change gender
void Student::SetGender(char sex) {
	
	do {
		cout<<"Input a gender (M/F): ";
		cin>>sex;

		gender = sex;

	}while(sex != 'M' && sex != 'F');
	
	return;

}

//this function allows user to change the birthday but creating loops
//to ensure a valid birthdate is entered
void Student::SetBirth(int m, int d, int y) {
	int maxday;
	int minday = 1;

	do {
		cout<<"Input a valid birth month: ";
		cin>>m;

	} while(m > 12 || m < 1);

	month = m;

	switch (m) {
		case 1:
		case 3:
		case 5:
		case 7:
		case 8:
		case 10:
		case 12:
			maxday = 31;
			break;
		case 2:
			maxday = 28;
			break;
		case 4: 
		case 6:
		case 9:
		case 11:
			maxday = 30;
			break;
	}
	
	do {
		cout<<"Input the birth day: ";
		cin>>d;

	} while(d > maxday || d < minday);

	day = d;
	
	do {
		cout<<"Input the birth year: ";
		cin>>y;

	} while(y > 2017 || y < 1900);

	year = y;

}

//accessor functions to print out data
int Student::getID() const {
	cout<<"Student ID: "<<studentID<<endl;
	return studentID;
}

void Student::getBirth() const {
	cout<<month<<'/'<<day<<'/'<<year<<endl;
}

void Student::getName() const {
	cout<<firstName<<' '<<middleInitial<<' '<<lastName<<endl;
}

char Student::getGender() const {
	cout<<"Gender: "<<gender<<endl;
	return gender;
}
