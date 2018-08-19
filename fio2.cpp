/* Philip Tenteromano 2/5/2017
 *
 * File IO Lab task 2
 *
 * Using the population file - determine countries with fastest
 * growth rates at four different time intervals
 *
 */

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {

	ifstream inFS;			//create read-from-file variable
	string line;
	
	inFS.open ("population.csv");	//find and open the file
					
	if (!inFS.is_open()) 		//output warning if file does not open
		cout<<"Could not open the file!"<<endl;

	//array sizes
	const int MAXCOUNTRIES = 229; 	//countries on file
	const int TIMELINE = 4;         //four growth (over time) slots available

	//string array to store four intervals for later use
	string timePeriod[TIMELINE] = {"1950-1970", "1970-1990", "1990-2010", "2010-2015"};

	struct PopGrowth {       	          //struct to store Growth-related variables 
		double difference[TIMELINE]; 	  //difference in population over 4 intervals
		double rate[TIMELINE];            //stores the actual growth rate over 4 intervals
	} Growth[MAXCOUNTRIES];			  //array of countries, holding arrays of 4 intervals

	struct Fastest {   		//struct will store the fastest growth rates
		string fName;		//when compared against PopGrowth structure	
		double fRate;
		double fDifference;
	};				//nested in World structure

	struct Country {		//struct stores data from file
		string name;
		double p1950;
		double p1970;
		double p1990;
		double p2010;
		double p2015;
	};

	struct World {			//the struct to nest other structs
		int numCountries;
		Country countries[MAXCOUNTRIES];
		Fastest	topGrowth[TIMELINE]; //four intervals, 50-70, 70-90, 90-10, 10-15
	} myWorld;	

	//read all the data from the file
	int counter = 0;
	
	do {
		inFS>>myWorld.countries[counter].p1950;
		inFS>>myWorld.countries[counter].p1970;
		inFS>>myWorld.countries[counter].p1990;
		inFS>>myWorld.countries[counter].p2010;
		inFS>>myWorld.countries[counter].p2015;
		getline(inFS, myWorld.countries[counter].name);
		counter++;

	} while (getline(inFS, line));
	
	//once data has been stored, use for loops to find growths for all countries
	//at every interval
	
	//array index 0 is storing 1950-1970 population growth
	for(int pos = 0; pos < MAXCOUNTRIES; pos++) {
		Growth[pos].difference[0] = 
			(myWorld.countries[pos].p1970 - myWorld.countries[pos].p1950);
			
		Growth[pos].rate[0] = 
			(Growth[pos].difference[0] / myWorld.countries[pos].p1950);
	}
	//array index 1 is storing 1970-1990 population growth
	for(int pos = 0; pos < MAXCOUNTRIES; pos++) {
		Growth[pos].difference[1] =
			(myWorld.countries[pos].p1990 - myWorld.countries[pos].p1970);
		
		Growth[pos].rate[1] =
			(Growth[pos].difference[1] / myWorld.countries[pos].p1970);
	}
	//array index 2 is storing 1990-2010 population growth
	for(int pos = 0; pos < MAXCOUNTRIES; pos++) {
		Growth[pos].difference[2] =
			(myWorld.countries[pos].p2010 - myWorld.countries[pos].p1990);
		
		Growth[pos].rate[2] =
			(Growth[pos].difference[2] / myWorld.countries[pos].p1990);
	}
	//array index 3 is storing 2010-2015 population growth
	for(int pos = 0; pos < MAXCOUNTRIES; pos++) {
		Growth[pos].difference[3] =
			(myWorld.countries[pos].p2015 - myWorld.countries[pos].p2010);
		Growth[pos].rate[3] =
			(Growth[pos].difference[3] / myWorld.countries[pos].p2010);
	}


	//initialize the four fastest growths to the rates of some country (the first)
	for(int set = 0; set < TIMELINE; set++) {
		
		myWorld.topGrowth[set].fRate = Growth[0].rate[set];
	}

	//this nested for loop will now scan every country, and every rate for
	//that country. Comparing and storing the fastest growth rates
	for(int pos = 0; pos < MAXCOUNTRIES; pos++) {

		for(int time = 0; time < TIMELINE; time++) {
			if (Growth[pos].rate[time] > myWorld.topGrowth[time].fRate) {
				myWorld.topGrowth[time].fRate = Growth[pos].rate[time];
				myWorld.topGrowth[time].fName = myWorld.countries[pos].name;
				myWorld.topGrowth[time].fDifference = Growth[pos].difference[time];
			}
		}	
	}

	//output the stored data
	for(int pos = 0; pos < TIMELINE; pos++) {

		cout<<endl<<"The fastest growing country from "<<timePeriod[pos]<<" is: "
			<<myWorld.topGrowth[pos].fName<<" with a growth rate of "
			<<(100 * myWorld.topGrowth[pos].fRate)<<"%."<<endl;
		cout<<"The population grew by "<<myWorld.topGrowth[pos].fDifference<<" people.";
		cout<<endl;
	}

	cout<<endl;
		

	//report that file is at the end and is terminating
	if(!getline(inFS, line)) {
		cout<<endl<<"File end, closing now!\n";
		inFS.close(); //close file
		cout<<endl<<endl;
	}

} //end main

