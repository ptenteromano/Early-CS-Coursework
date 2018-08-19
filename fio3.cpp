/* Philip Tenteromano 2/5/2017
 *
 * File IO Lab task 3
 *
 * 
 *
  */

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {

	ifstream inFS;
	string line;

	//find and open the file
	inFS.open ("population.csv");
	//output warning if file does not open
	if (!inFS.is_open()) 
		cout<<"Could not open the file!"<<endl;

	//array sizes
	const int MAXCOUNTRIES = 229; 
	const int THREE = 3; //size for three most populous
	
	struct Size { //creating a struct to store 3 largest populations
		string popname;
		double population;
	};

	struct Country {
		string name;
		double p1950;
		double p1970;
		double p1990;
		double p2010;
		double p2015;
	};

	struct World {
		int numCountries;
		Country countries[MAXCOUNTRIES];
		Size largest[THREE]; //nesting Size in World and create a const int 3 array
	} myWorld;	

	//read all the data from the file
	for(int pos = 0; pos < MAXCOUNTRIES; pos++) {
		inFS>>myWorld.countries[pos].p1950;
		inFS>>myWorld.countries[pos].p1970;
		inFS>>myWorld.countries[pos].p1990;
		inFS>>myWorld.countries[pos].p2010;
		inFS>>myWorld.countries[pos].p2015;
		getline(inFS, myWorld.countries[pos].name);
	}

	//storing dummy populations to 1,2,3 to compare populations off of
	myWorld.largest[0].population = myWorld.countries[0].p2015;
	myWorld.largest[1].population = myWorld.countries[0].p2015;
	myWorld.largest[2].population = myWorld.countries[0].p2015;

	//looping through 2015 population data, comparing and storing accordingly (multiple branches) 
	for(int pos = 0; pos < MAXCOUNTRIES; pos++) {
		if (myWorld.countries[pos].p2015 > myWorld.largest[0].population) {
			myWorld.largest[0].population = myWorld.countries[pos].p2015;
			myWorld.largest[0].popname = myWorld.countries[pos].name;
		}
		else if (myWorld.countries[pos].p2015 > myWorld.largest[1].population) {
			myWorld.largest[1].population = myWorld.countries[pos].p2015;
			myWorld.largest[1].popname = myWorld.countries[pos].name;
		}
		else if (myWorld.countries[pos].p2015 > myWorld.largest[2].population) {
			myWorld.largest[2].population = myWorld.countries[pos].p2015;
			myWorld.largest[2].popname = myWorld.countries[pos].name;
		}
	}

	//output the three largest, with explaination and name first
	for(int pos = 0; pos < THREE; pos++) {
		cout<<endl<<"The #"<<(pos+1)<<" most populous country in 2015:\n";
		cout<<myWorld.largest[pos].popname<<' ';
		cout<<myWorld.largest[pos].population<<' '<<endl;
	}
		
	//report that file is at the end and is terminating
	if(!getline(inFS, line)) {
		cout<<endl<<"File end, closing now!\n";
		inFS.close(); //close file
		cout<<endl<<endl;
	}

} //end main
