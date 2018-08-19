#include <fstream>
#include <iostream>

using namespace std;

main() {
	
	ifstream inFile;
	ofstream outputFile;
	outputFile.open("floatfile.txt");
	int size = 5;
	int floats[size];

	cout<<"Enter five floating-point numbers\n";

	for(int num = 0; num < size; num++) {
		outputFile<< floats[num];
	}

}
