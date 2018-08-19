/*Phil Tenteromano 1/27/2016
 *
 * Lab 7.4 option 1 Arrays
 *
 * Age Population Program
 *
 */

#include <iostream>

using namespace std;

main() {
	//variables to form an array holding age frequency
	int size = 100;
	int agePop[size] = {0};
	
	//prototypes
	void input(int [], int);	
	void output(int [], int);

	//calling the functions in main()
	input(agePop, size);
	output(agePop, size);

}

//declaring functions
void input(int agePop[], int size) {
	int input;

	do {
		cout<<"Please input an age from 1 to 100, enter -99 to stop\n";
		cin>>input;

		for (int pos = 1; pos <= size; pos++) {
			if (input == pos)
				agePop[pos-1]++;
		}

	}while (input != -99); 
	
}

void output(int agePop[], int size) {
	
	for (int pos = 1; pos <= size; pos++) {
		if (agePop[pos-1] > 0) {
			cout<<"The number of people "<<pos<<" years old is "<<agePop[pos-1];
			cout<<endl;
		}
	}
}



