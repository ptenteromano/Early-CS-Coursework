/* Philip Tenteromano 2/17/2017
 *
 * Name class definitions using the header file name.h
 *
 */

#include <iostream>
#include <string>

using namespace std;

#include "name.h"

//default constructor
Name::Name() 		
{
	fName = "John";
	lName = "Doe";
	middleI = 'A';
}

//specific constructor
Name::Name(string f, char m, string l)
{
	fName = f;
	lName = l;
	middleI = m;
}

//external user input function
void Name::setName()
{
	cout<<"Input the first name: ";
	cin>>fName;
	cout<<"Input the middle initial: ";
	cin>>middleI;
	cout<<"Input the last name: ";
	cin>>lName;
}

//mutator for first
void Name::setFirst(string f)
{
	fName = f;
}

//mutator for last
void Name::setLast(string l)
{
	lName = l;
}

//mutator for middle
void Name::setMiddle(char m)
{
	middleI = m;
}

//accessor for first
string Name::getFirst()
{
	return fName;
}

//accessor for last
string Name::getLast()
{
	return lName;
}

//accessor for middle
char Name::getMiddle()
{
	return middleI;
}

//full display method for entire name
void Name::printFull()
{
	cout<<fName<<' '<<middleI<<' '<<lName<<endl;
}

