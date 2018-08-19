/* Array Manipulator 12/7/2016
 *
 * Phil Tenteromano
 *
 * Working with a set range to control values and elements in arrays
 *
*/

#include <iostream>

using namespace std;


main() {

	

	const int max = 4;
	int array [max] = {0};
	int sum = 0, min = 0, largest = 0;
	float avg;
	int cnum, ncount, snum, scount, rnum, rcount;
	bool mod, format;
	

	void input(int [], int);	
	void display(int [], int);
	void statistics(int [], int, int &, int &, int &, float &);
	int count(int [], int, int &);		
	int search(int [], int, int &);	
	int replace(int [], int, int &);
	bool modify(int [], int);
	bool clear(int [], int);
	
	cout<<"Let's get started with arrays!!\n";

	input (array, max);

	display (array, max);

	statistics(array, max, sum, min, largest, avg);
		cout<<"The sum is "<<sum<<"\nThe smallest number is "<<min
		<<"\nThe largest number is "<<largest
		<<"\nThe average of the numbers is "<<avg<<endl;

	ncount = count(array, max, cnum);
		cout<<"The number "<<cnum<<" appears "<<ncount<<" times\n";

	scount = search(array, max, snum);
		if (scount != -1)
			cout<<"The number "<<snum<<" is found in position "<<scount<<endl;
		else
			cout<<"The number "<<snum<<" is not found in any position\n";
	
	rcount = replace(array, max, rnum);
		if (rcount > 0)
			cout<<"The number "<<rnum<<" was replaced "<<rcount<<" times\n";
		else
			cout<<"The number "<<rnum<<" was not found\n";
	
	mod = modify(array, max);
		if (!mod)
			cout<<"No modification took place\n";
	
	format = clear(array, max);
		if (!format)
			cout<<"No clearing took place\n";
	

	

}//main close



void input(int array [], int max) {

	for (int in=0; in<max; in++) {
		cout<<"Enter value "<<in+1<<":";
		cin>>array[in];
	}
}


void display(int array [], int max) { 

	cout<<"Position\tValue"<<endl
	    <<"--------\t-----"<<endl;
	
	for (int dis=0; dis<max; dis++) {
		cout<<dis+1<<"       \t"<<array[dis]<<endl;
	}

	cout<<endl;

}	


void statistics(int array [], int max, int &sum, int &min, int &largest, float &avg) {
		
	largest = array [0];
	min = array [0];
	sum = 0;

	for (int stat=0; stat<max; stat++) {
		sum += array[stat];

		if (array [stat] < min)
			min = array [stat];

		if (array [stat] > largest)
			largest = array [stat];
	}
	avg = (float) sum/max;
}


int count(int array [], int max, int &cnum) {

	int result = 0;

	cout<<"What number would you like to count?";
	cin>>cnum;
	
	for (int cntr=0; cntr<max; cntr++) {
		if (cnum == array[cntr])
			result++;
	}
	
	return(result);
}


int search(int array [], int max, int &snum) {
	
	int result = -1;
	
	cout<<"What number would you like to search for?";
	cin>>snum;
	
	for (int srch=0; srch<max; srch++) {
		if (snum == array[srch]){
			result = srch + 1;
			break;
		}
	}
	return(result);
}

int replace(int array [], int max, int &rnum) {
       
	int nvalue;
	int counter = 0;
	bool result = false;
	
	cout<<"What value would you like to replace?";
	cin>>rnum;
	
	for (int repl=0; repl < max; repl++) {
		if (rnum == array[repl]) {
			cout<<"Enter new value:";	
			cin>>nvalue;
			break;
		}
	}
	//this second for loop is created so that 
	//the above 'enter new value' is not repeated
	for (int repl=0; repl < max; repl++) {
		if (rnum == array[repl]) {
			array [repl] = nvalue;
			
			counter++;

			result = true;
		}
	}
	if (result)
		display(array, max);
		
	return(counter);
}	


bool modify(int array [], int max) {

	int num, newvalue;
	bool result = false;
	
	cout<<"What position would you like to modify?";
	cin>>num;

	for (int tryagain = 0; tryagain <= 2; tryagain++) {
		if (num >= 1 && num <= max) {
			result = true;
			break;
		}
		else {
			cout<<"That is not in the range. "
			<<"Please enter a position between 1 and "<<max<<":";
			cin>>num;
		}
	}

	if (result) {
		cout<<"Enter the new value:";
		cin>>newvalue;
		
		for (int mod = 0; mod < max; mod++) {
		       if (num == (mod+1)) {
				array[mod] = newvalue;
		       		break;
			}
		}
		
		cout<<"Position "<<num<<" has been modified to a value of "<<newvalue<<endl;

		display(array, max);
	}
	
	return(result);
}

bool clear(int array[], int max) {
		
	int num;
	bool result = false;
	
	cout<<"What position would you like to clear? Enter -1 to clear entire array:";
	cin>>num;

	for (int tryagain = 0; tryagain < 2; tryagain++) {
		if (num >= 1 && num <= max) {
			array[num-1] = 0;
			result = true;
			break;
		}
		if (num == (-1)) {
			for (int all=0; all<max; all++) {
				
				array[all] = 0;
				result = true;
			}
			break;
		}
		else
		       	cout<<"That is an invalid position, please enter a position between 1 and "
			<<max<<", or -1 to clear entire array:\n";
			cin>>num;
	}

	if (result) {
		cout<<"The contents of your array are now:\n";
		display (array, max);
	}

	return(result);
}


