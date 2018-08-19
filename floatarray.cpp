// This program reads floating point data from a data file and places those
// values into the private data member called values (a floating point array)
// of the FloatList class. Those values are then printed to the screen.
// The input is done by a member function called GetList. The output
// is done by a member function called PrintList. The amount of data read in
// is stored in the private data member called length. The member function
// GetList is called first so that length can be initialized to zero.

// Philip Tenteromano 2/16/2017

#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;

const int MAX_LENGTH = 50;		// MAX_LENGTH contains the maximum length of our list 
class FloatList					// Declares a class that contains an array of
								// floating point numbers
{
public:
	void getList(ifstream&);	// Member function that gets data from a file 
	void printList() const;		// Member function that prints data from that
	float getAvg();						// file to the screen.

	FloatList();				// constructor that sets length to 0.
	~FloatList();				// destructor

private:
	int length;			//	Holds the number of elements in the array
	float values[MAX_LENGTH];	//	The array of values

};

int main()
{
	ifstream tempData;	// Defines a data file

	// Fill in the code to define an object called list of the class FloatList
	FloatList list;

	cout << fixed << showpoint;

	cout << setprecision(2);

	tempData.open("temperatures.txt");

	// Fill in the code that calls the getList function.
	list.getList(tempData);
	
	// Fill in the code that calls the printList function.
	list.printList();     //exercise 2 output

	cout<<"The average of the list is: "<<list.getAvg()<<endl<<endl;

	return 0;
}

FloatList::FloatList()
{
	length = 0;
}

// Fill in the entire code for the getList function
// The getList function reads the data values from a data file
// into the values array of the class FloatList
void FloatList::getList(ifstream &data)
{
	for(int pos = 0; pos < MAX_LENGTH; pos++) {
		if(!data.eof()) {
			data>>values[pos];
			length++;
		}else
			break;
	}
}

// Fill in the entire code for the printList function
// The printList function prints to the screen the data in
// the values array of the class FloatList
void FloatList::printList() const 
{
	for(int pos = 0; pos < length; pos++) {
		cout<<values[pos]<<endl;
	}
} //exercise 1:
  //print list has a const because it is dealing with private data members
  //in this case, values[] is a private array which is output, but cannot be manipulated

//destructor definition
FloatList::~FloatList() 
{
	cout<<"This concludes FloatList class."<<endl;
}

//exercise 3:
float FloatList::getAvg() 
{
	float sum = 0;
	for(int pos = 0; pos < length; pos++) {
		sum += values[pos];
	}
	return sum/length;
}
