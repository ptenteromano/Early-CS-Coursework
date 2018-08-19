/* Philip Tenteromano 2/5/2017
 *
 * File IO Lab task 0
 *
 * Using population.csv
 *
 * Reading and outputting data from an excel file
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
	
	//warning message if file does not open
	if (!inFS.is_open()) 
		cout<<"Could not open the file!"<<endl;
	
	//const array size
	const int MAXCOUNTRIES = 229; 

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
	} myWorld;	

	//read the data from the file using for loop
	for(int pos = 0; pos < MAXCOUNTRIES; pos++) {
		inFS>>myWorld.countries[pos].p1950;
		inFS>>myWorld.countries[pos].p1970;
		inFS>>myWorld.countries[pos].p1990;
		inFS>>myWorld.countries[pos].p2010;
		inFS>>myWorld.countries[pos].p2015;
		getline(inFS, myWorld.countries[pos].name);
	}

	//output the data from the file, with name first
	for(int pos = 0; pos < MAXCOUNTRIES; pos++) {
		cout<<myWorld.countries[pos].name<<' ';
		cout<<myWorld.countries[pos].p1950<<' ';
		cout<<myWorld.countries[pos].p1970<<' ';
		cout<<myWorld.countries[pos].p1990<<' ';
		cout<<myWorld.countries[pos].p2010<<' ';
		cout<<myWorld.countries[pos].p2015<<' '<<endl;
	}
	
	//check for file end and close the file	
	if(!getline(inFS, line)) {
		cout<<endl<<"End of File, closing now!";
		inFS.close(); //file close
		cout<<endl<<endl;
	}

} //end main

