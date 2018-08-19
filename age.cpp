/* Age Calculator 11/30/2016
 *
 * Phil Tenteromano
 *
 * This program uses functions and user input to calculate age
 *
*/

#include <iostream>

using namespace std;

main () {
	
	//day is the birth, day2 is the current day, etc...
	
	int monthb, dayb, yearb, monthc, dayc, yearc, yage, ymonth, yday;
	int counter1 = 0, counter2 = 0;
	char slash1, slash2, slash3, slash4, resp;
	bool val1, val2, birthday;	
	bool val3 = 0;

	
	bool inputBirthday(int &, int &, int &, char, char);
	bool inputDate(int &, int &, int &, char, char);
	bool todayVsbirth(int &, int &, int &, int &, int &, int &);
	bool validDate(int &, int &);
	void happyBirthday(int &, int &, int &, int &);
	void calculateAge(int &, int &, int &, int &, int &, int &, int &, int &, int &);
	
	cout<<"Want to see how old you are? (y/n)\n";
	cin>>resp;
	
	if(resp != 'y' && resp != 'Y') 
		cout<<"You can't hide forever!\n";
	else {

		//begin program with 3 chances to input current date correctly 
		do {
			if (counter1 >= 1)
				cout<<"Try again!!\n";
			
			val1 = inputDate(monthc, dayc, yearc, slash3, slash4);
			
			counter1++;
			
			if (counter1 >= 3)
				cout<<"Don't waste my time.\n";
			
		}while(val1 == 0 && counter1 < 3);

		
		//if current date is entered correctly, give 3 chances to input a valid birthdate
		if (val1 == 1) {
			do { 
				if (counter2 >= 1)
					cout<<"Try again!!\n";
			
				val2 = inputBirthday(monthb, dayb, yearb, slash1, slash2);
	
				counter2++;
				
				if (counter2 >= 3)
					cout<<"Don't waste my time.\n";
				
			}while(val2 == 0 && counter2 < 3);
		}	

		
		//check to validate the that birtdate is prior than today's date
		val3 = todayVsbirth(monthb, dayb, yearb, monthc, dayc, yearc);
		//if invalid, negate program!
		if (val3 == 1)
			cout<<"That doesn't make sense! You wouldn't have been born yet!\n";
		else
		//checking month and day, see if today is user's birthday
			happyBirthday(monthb, dayb, monthc, dayc);
	
		
		//if all values check out, calculate the age!	
		if ((val1 == 1 && val2 == 1) && val3 == 0) {
			
			calculateAge(monthb, dayb, yearb, monthc, dayc, yearc, yage, ymonth, yday);
			
			cout<<"You are "<<yage<<" years old, "<<ymonth<<" months old, and "<<yday<<" days old!\n";

			}
		

	}//else close -- main program



}//main close


bool validDate (int &, int &);


//functions
//this function is to store birthday input by reference
bool inputBirthday(int &monthb, int &dayb, int &yearb, char slash1, char slash2) {
	bool value = 0;
	
	cout<<"Enter your BIRTHDAY in mm/dd/yyyy format:\n";
	cin>>monthb>>slash1>>dayb>>slash2>>yearb;
	cout<<endl;

	//check validity
	value = validDate(monthb, dayb);

	if (slash1 != '/' || slash2 != '/')
		value = 0;

	return(value);
	}

//this function is similiar to above function, but stores current date by reference
bool inputDate(int &monthc, int &dayc, int &yearc, char slash3, char slash4) {
	bool value = 0;
	
	cout<<"Enter TODAY'S DATE in mm/dd/yyyy format:\n";
	cin>>monthc>>slash3>>dayc>>slash4>>yearc;
	cout<<endl;
	
	//check validity
	value = validDate(monthc, dayc);

	if (slash3 != '/' || slash4 != '/')
		value = 0;

	return(value);
	}


//this function sums up all valid 12 months, and their respective days
//if an incorrect date is entered, value will return as false
bool validDate (int &month, int &day) {
	bool value = 1;
	
	if (day < 1)
		value = 0;
	else
	if (month > 12 || month < 1)
		value = 0;
	else	
	if (month == 2 && day > 28)
		value = 0;
	else
	if (day > 30 && (month == 4 || month == 6 || month == 9 || month == 11))
		value = 0;
	else
	if (day > 31)
		value = 0;
	
	return(value);
	}


//this function forces the current date to be after the birthdate, even if by only 1 day
bool todayVsbirth(int &month, int &day, int &year, int &month2, int &day2, int &year2) {
	bool value = 0;

	if (year > year2)
		value = 1;
	else
	if ((year == year2) && (month > month2))
		value = 1;
	else
	if (((year == year2) && (month == month2)) && (day > day2))
		value = 1;	

	return(value);
	}

//comparing referenced months and days, check for birthday
void happyBirthday(int &monthb, int &dayb, int &monthc, int &dayc) {
	
	if ((monthb == monthc) && (dayb == dayc))
		cout<<"Wow, happy birthday! That makes things easier!\n";
	}


//using all stored reference dates, calculate age
void calculateAge(int &monthb, int &dayb, int &yearb, int &monthc, int &dayc, int &yearc,
	          int &yage, int &ymonth, int &yday) {
	int max;
		
	yday = dayc - dayb;
	ymonth = monthc - monthb;
	yage = yearc - yearb;

	switch(monthb) {
	case 1:
	case 3:
	case 5:
	case 7:
	case 8:
	case 10:
	case 12:
		max = 31;
		break;
	case 2:
		max = 28;
		break;
	case 4:
	case 6:
	case 9:
	case 11:
		max = 30;
	}

	if (dayb > dayc) {
		yday = dayc + (max - dayb);
			ymonth -= 1;
		}
				
	if (monthb > monthc) {
		yage = monthc + (12 - monthb);
		yage -= 1;		
		}
	}




