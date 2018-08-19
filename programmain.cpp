/* Philip Tenteromano 2/17/2017
 *
 * Program main using the header and defintions of class program
 *
 */

#include <iostream>
#include <string>

using namespace std;

#include "program.h"

int main() {

	//declare an array of 3 objects
	Program student[3];
	
	//define an object with specific constructor
	Program student1("LC");

	student[0].setProgram();

	//mutate individual data members
	student[1].setCampus("LC");
	student[1].setDegree("BS");
	student[1].setMajor("CS");
	student[1].setMinor("None");
	

	//print each object
	student[0].print();

	student[1].print();

	student[2].print();

	student1.print();

} //end main
