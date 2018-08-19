/* Philip Tenteromano 1/30/2017
 *
 * Lab 7.3 
 *
 * two dimensional arrays
 * using prices
 *
 */

#include <iostream>
#include <iomanip>

using namespace std;

const int MAXROWS = 10;
const int MAXCOLS = 10;

typedef float PriceType[MAXROWS][MAXCOLS];

void getPrices(PriceType, int &, int &);
void printPrices(PriceType, int, int);
float findHighestPrice(PriceType, int, int);
float findLowestPrice(PriceType, int, int);

int main() {

	float highest;
	float lowest;
	int rowsUsed;
	int colsUsed;
	PriceType priceTable;

	getPrices(priceTable, rowsUsed, colsUsed);
	printPrices(priceTable, rowsUsed, colsUsed);

	//exercise 4 and 5:
	highest = findHighestPrice(priceTable, rowsUsed, colsUsed);
	lowest = findLowestPrice(priceTable, rowsUsed, colsUsed);

	cout<<"The highest price is $"<<highest<<endl;
	cout<<"The lowest price is $"<<lowest<<endl;
	//the highest of the given prices is 102.34
	//the lowest is 1.45

	return 0;
}

void getPrices(PriceType table, int &numOfRows, int &numOfCols) {
	cout<<"Please input the number of rows from 1 to "<<MAXROWS<<endl;
	cin>>numOfRows;

	cout<<"Please input the number of columns from 1 to "<<MAXCOLS<<endl;
	cin>>numOfCols;

	for(int row = 0; row < numOfRows; row++) {
		for(int col = 0; col < numOfCols; col++) {
			cout<<"Input a price, a break signals the next row: ";
			cin>>table[row][col];
		}
		cout<<endl;
	}
}
//exercise 2: getPrices() passes numOfRows and numOfCols by reference so it can store that data in main
//for further use in printPrices(). printPrices() only needs the values of the rows and cols, it does
//not manipulate those values

void printPrices(PriceType table, int numOfRows, int numOfCols) {
	cout<<fixed<<showpoint<<setprecision(2);

	for(int row = 0; row < numOfRows; row++) {
		for(int col = 0; col < numOfCols; col++) {
			cout<<table[row][col]<<' ';
		}
		cout<<endl;
	}
}

float findHighestPrice(PriceType table, int numOfRows, int numOfCols) {
	float highestPrice;

	highestPrice = table[0][0];

	for(int row = 0; row < numOfRows; row++)
		for(int col = 0; col < numOfCols; col++)
			if(highestPrice < table[row][col])
				highestPrice = table[row][col];

	return highestPrice;
}

float findLowestPrice(PriceType table, int numOfRows, int numOfCols) {
	float lowestPrice;

	lowestPrice = table[0][0];

	for(int row = 0; row < numOfRows; row++)
		for(int col = 0; col < numOfCols; col++)
			if(lowestPrice > table[row][col])
				lowestPrice = table[row][col];

	return lowestPrice;
}

