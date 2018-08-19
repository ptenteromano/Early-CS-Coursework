/* Phil Tenteromano 1/27/2017
 *
 * CS1 Review
 *
 * This program manipulates arrays
 *
 */

#include <iostream>
#include <iomanip>

using namespace std;

main() {
	//constant size variables
	const int size = 11;
	const int row = 6, col = 4;
	//array declaration
	int even[size];
	int odd[size] = {0};
	int twoD[row][col] = {0};

	void display1(int [], int [], int);
	void swap1(int [], int [], int);
	void display2(int [][], int, int, int [], int [], int);
	
	display1(odd, even, size);
	swap1(odd, even, size);
	display2(twoD, row, col, odd, even, size);
}

//function declarations
void display1(int odd[], int even[], int size) {
	
	//initiliaze even[] and odd[]
	for(int num = 1; num < size; num++) {
		even[num] = (2*num);
		odd[num] = (2*num-1);
	}
	//display loop
	for(int num = 1; num < size; num++) {
		cout<<odd[num]<<setw(6);
		cout<<even[num]<<endl;
	}
}

void swap1(int odd[], int even[], int size) {
	int holder[size];

	cout<<endl<<"After the Swap\n";
	
	//initialize a replacement array for even[]
	for(int num = 0; num <= size; num++) {
		holder[num] = even[num];
	}
	//swap at everyone other index
	for(int num = 1; num < size; num++) {
		if (num%2 == 1) {
			even[num] = odd[num];
			odd[num] = holder[num];
		}
	}
	//display the swap
	for(int num = 1; num < size; num++) {
		cout<<odd[num]<<setw(6);
		cout<<even[num]<<endl;
	}
}

void display2(int twoD[][], int row, int col, int odd[], int even[], int size) {

	for(int r = 0; r < row; r++) {
		for(int c = 0; c < col; c++) {
			if (c%2 == 1)
				twoD[r][c] = odd[c];
			else
				twoD[r][c] = even[c];
			cout<<twoD[r][c]<<' ';
		}
		cout<<endl;
}





