/* This tests the file IO */

#include <iostream>
#include <fstream> //needed to use files

using namespace std;

main() {

	ofstream outputFile;
	outputFile.open("demofile.txt");

	cout<<"Now writing information to the file.\n";
	//write 3 great names to the file
	outputFile<<"Bach\n";
	outputFile<<"Beethoven\n";
	outputFile<<"Mozart\n"; 

	//close the file
	outputFile.close();
	cout<<"Done.\n";
}
