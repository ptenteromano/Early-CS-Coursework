/* The output of the file created in the file IO test */




#include <iostream>
#include <fstream> //needed to use files
#include <string>

using namespace std;

main() {

	ifstream inFile;
	string name;

	inFile.open("demofile.txt");
	cout<<"reading information from the file.\n\n";

	inFile>>name; //read name 1 from the file
	cout<<name<<endl; //display name 1

	inFile>>name;
	cout<<name<<endl; //name 2
	
	inFile>>name;
	cout<<name<<endl; //name 3

	inFile.close(); //close the file

	cout<<"\nDone.\n";
}
