/* Philip Tenteromano
 *
 * Review of CS1 - late turn in
 *
 * Array functionality
 *
 */

#include <iostream>
#include <iomanip>

using namespace std;

int main() {

	//const array sizes
	const int SINGLE_D = 10;
	const int ROW = 4;
	const int COL = 7;
	
	//one dimensional arrays
	int evenArr[SINGLE_D];
	int oddArr[SINGLE_D];

	//function prototypes
	void swap(int x, int y);
	void swapArray(int x[], int y[], int s);
	void displayArray(int x[], int y[], int s);
	void initialize(int twoD[][COL], int r, int c, int x[], int y[], int s);
	void displayTable(int twoD[][COL], int r, int c);

	//initialize one dimensional arrays
	for(int pos = 0; pos < SINGLE_D; pos++) {
		evenArr[pos] = (pos*2 + 2);
		oddArr[pos] = (pos*2 + 1);
	}
	
	//declaring two dimension array
	int tableArr[ROW][COL];

	//display even and odd arrays	
	cout<<"Before Swap: "<<endl;
	displayArray(evenArr, oddArr, SINGLE_D);

	cout<<endl;
	//swap arrays
	swapArray(evenArr, oddArr, SINGLE_D);

	//swapped at even indices, display swap
	cout<<"After Swap: "<<endl;
	displayArray(evenArr, oddArr, SINGLE_D);

	cout<<endl;
	//call initialize function to initialize two dimension array
	initialize(tableArr, ROW, COL, evenArr, oddArr, SINGLE_D);
	
	displayTable(tableArr, ROW, COL);


	cout<<endl;

}//end main


//function swap that accepts two integers values, and swaps the values
void swap(int x, int y)
{
	int temp = 0;

	temp = x;
	x = y;
	y = temp;

	cout<<"x: "<<x<<endl<<"y: "<<y<<endl;
}

//function swap array that accepts two integer arrays and swaps all elements at even index
void swapArray(int x[], int y[], int s)
{
	int temp = 0;
	
	for(int pos = 0; pos < s; pos+=2) {
		temp = x[pos];
		x[pos] = y[pos];
		y[pos] = temp;
	}
}

void displayArray(int x[], int y[], int s)
{
	for(int pos = 0; pos < s; pos++) {
		cout<<"First Array: "<<x[pos]<<setw(10)<<" Second Array: "<<y[pos]<<endl;
	}
}

void initialize(int twoD[][7], int r, int c, int x[], int y[], int s) 
{
	for(int rows = 0; rows < r; rows++) {
		for(int cols = 0; cols < c; cols++) {
			if (rows == 0)
				twoD[rows][cols] = x[cols];		
			if (rows == 1)
				twoD[rows][cols] = y[cols];
			if (rows == 2)
				twoD[rows][cols] = x[rows + cols];
			if (rows == 3)
				twoD[rows][cols] = y[rows + cols];
		}
	}
}

void displayTable(int twoD[][7], int r, int c)
{
	for(int rows = 0; rows < r; rows++) {
		for (int cols = 0; cols < c; cols++) {
			cout<<twoD[rows][cols]<<' ';
		}
		cout<<endl;
	}
}
