/* Philip Tenteromano 1/30/2017
 *
 * Lab 7.2 
 *
 */

#include <iostream>
#include <iomanip>

using namespace std;


const int MAXGRADE = 25;
const int MAXCHAR = 30;

typedef char StringType30[MAXCHAR+1];
typedef float GradeType[MAXGRADE];

float findGradeAverage(GradeType, int);

char findLetterGrade(float);


int main() {

	StringType30 firstname, lastname;
	int numOfGrades;
	GradeType grades;
	float average;
	char moreInput;
	char letterGrade;

	cout<<setprecision(2)<<fixed<<showpoint;

	do {
		cout<<"Please input the number of grades for each student."<<endl
			<<"this must be a number between 1 and "<<MAXGRADE<<" inclusive"<<endl;	
		cin>>numOfGrades;

	}while(numOfGrades > MAXGRADE || numOfGrades < 1);


	cout<<"Please input a Y if you want to input more students"
		<<"any other character will stop the input"<<endl;
	cin>>moreInput;
	

	while(moreInput == 'y' || moreInput == 'Y') {

		cout<<"Please input the first name of the student"<<endl;
		cin>>firstname;
		cout<<endl<<"Please input the last name of the student"<<endl;
		cin>>lastname;

		for(int count = 0; count < numOfGrades; count++) {
			cout<<endl<<"Please input a grade"<<endl;
			cin>>grades[count];
		}
	
		//outputting names and corresponding grades
		cout<<firstname<<' '<<lastname<<" has an average of ";
	
		average = findGradeAverage(grades, numOfGrades);
	
		letterGrade = findLetterGrade(average);

		cout<<average<<" which is a letter grade of "<<letterGrade<<endl;
	
		cout<<endl<<"Please input a y if you want to input more students"
			<<"any other character will stop the input"<<endl;
		cin>>moreInput;
	}


	
} //end main


//functions
float findGradeAverage(GradeType array, int size) {
	int sum = 0;
	
	for(int pos = 0; pos < size; pos++) {
		sum += array[pos];
	}

	return float(sum)/size;
}

char findLetterGrade(float average) {
	char grade;

	if (average >= 90)
		grade = 'A';
	else if (average < 90 && average >= 80)
		grade = 'B';
	else if (average < 80 && average >= 70)
		grade = 'C';
	else if (average < 70 && average >= 65)
		grade = 'D';
	else
		grade = 'F';

	return grade;
}


