/*
 * Guessing Game
 *
 * Phil Tenteromano 11/2/2016
 *
 * Using random number generator
 *
*/


#include <ctime>

#include <cstdlib>

#include <iostream>

using namespace std;

main() {

	int seed;
	srand (seed);
	seed = time(0);
	rnum = rand();
	
	char resp;
	
	cout<<"Greetings! Let's play a guessing game! (y/n)\n";
	cin>>resp;

	if (resp!='y'&&resp!='Y')
		cout<<"You wouldn't have guess it anyway!\n";
	
	else {

	



	}//else close

}//main close
