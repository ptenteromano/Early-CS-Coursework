/* Phil Tenteromano 1/30/2017
 *
 * Lab 7 part 1
 *
 * Store grades and produce averages
 *
 */

#include <iostream>

using namespace std;

typedef int GradeType[100];

float findAverage(const GradeType, int);
int findHighest(const GradeType, int);
int findLowest (const GradeType, int);

int main() {

	GradeType grades;
	int numberOfGrades;
	int pos = 0;

	float avgOfGrades;
	int highestGrade;
	int lowestGrade;

	do {

		cout<<"Please input a grade from 1 to 100, or -99 to stop"<<endl;
		cin>>grades[pos];
		if (grades[pos] != -99)
			pos++;

	}while (grades[pos] !=-99);

	numberOfGrades = pos;
	
	//find average and output
	avgOfGrades = findAverage(grades, numberOfGrades);
		cout<<"The average of the "<< numberOfGrades<<" grades input is "
			<<avgOfGrades<<"."<<endl;
	
	//find highest and output
	highestGrade = findHighest(grades, numberOfGrades);
		cout<<endl<<"The highest grade is "<<highestGrade<<endl;

	//find lowest and output
	lowestGrade = findLowest(grades, numberOfGrades);
		cout<<endl<<"The lowest grades is "<<lowestGrade<<endl;

	//excerise 2: an Input of 90, 45, 73, 62, -99 gets:
	//average of 4 grades: 67.5, highest 90, lowest 45


} //end main

//functions
int findHighest(const GradeType grades, int size) {
	int highest = grades[0];

	for(int pos = 0; pos < size; pos++) {
		if (grades[pos] > highest)
			highest = grades[pos];
	}
	return highest;

}

int findLowest(const GradeType grades, int size) {
	int lowest = grades[0];

	for(int pos = 0; pos < size; pos++) {
		if (grades[pos] < lowest) 
			lowest = grades[pos];
	}
	return lowest;
}

float findAverage(const GradeType grades, int size) {
	int sum = 0;

	for(int pos = 0; pos < size; pos++) {
		sum +=  grades[pos];
	}
	return float(sum)/size;
}
