/* Philip Tenteromano 2/11/2017
 *
 * Date.cpp holding the definitions of functions of 
 * class Date
 *
 */

#include <iostream>

using namespace std;

#include "date.h"

//the private helper function, embedded in other functions
void Date::validDate(int m, int d, int y) {
	
	int maxday;
	int minday = 1;
	
	do {
		cout<<"Input a valid month (1-12): ";
		cin>>m;
	
	}while(m > 12 || m < 1);


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
			maxday = 31;
			break;
	}


	do {
		cout<<"Input a valid day: ";
		cin>>d;
	
	}while(d > maxday || d < minday);

	do {
		cout<<"Input a year between 0 and the current year: ";
		cin>>y;

	}while(y > 2017 || y < 0);

	month = m;
	day = d;
	year = y;

}

//default constructor
Date::Date() {
	month = 8;
	day = 31;
	year = 1990;
};

//overloaded constructor
Date::Date(int m, int d, int y) {
	
	validDate(m, d, y);
}

void Date::setDate(int m, int d, int y) {

	validDate(m, d, y);
}

int Date::getMonth() const {
	cout<<"The number month is: "<<month<<endl;
	return month;
}

int Date::getDay() const {
	cout<<"The day of the month is: "<<day<<endl;
	return day;
}

int Date::getYear() const {
	cout<<"The year is: "<<year<<endl;
	return year;
}




