/* Philip Tenteromano 2/17/2017
 *
 * Name main program using name.h and function definitions
 * to execute the class Name and use functions
 *
 */

#include <iostream>
#include <string>

using namespace std;

#include "name.h"

int main() {


	Name member1;		//declare object 1, cout the default constructor with functions
	cout<<member1.getFirst()<<' '<<member1.getMiddle()<<' '<<member1.getLast()<<endl;

	member1.setFirst("David");  	//mutate the objects data members
	member1.setMiddle('J');
	member1.setLast("Johnson");

	Name member2("Robert", 'M', "Downing");  //declare object 2 with specific constructor

	Name member3;				//declare object 3 with default constructor
	member3.setName();		//user input redefines private data members

	//cout all three objects
	member1.printFull();
	member2.printFull();
	member3.printFull();

}//end main
