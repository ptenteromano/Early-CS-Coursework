/* Midterm Lab
 *
 * Philip Tenteromano 11/16/2016
 *
 * Midterm Lab that will constantly create rectangles, filled or hollow,
 *
 * based on user input. Statistics shown when done with loop.
 *
 */



#include <iostream>

using namespace std;

main () {
	
	char resp, resp2, type, border, fill;
	int frect = 0;
	int hrect = 0;
	int area = 0;
	int perimeter = 0;
	int total;
	float avarea, avperim;
	
	cout<<"Welcome! Let's draw some rectangles.\n\n"
	<<"\tWould you like to play?\n";
		
	cin>>resp;

	if (resp!='y'&&resp!='Y')
		cout<<"I'll find someone who appreciates my shapes!\n";
	
	else {//begin program with y/Y response
		
	do {
	
	//these variables reset with each iteration, only in loop
	int width, length, row, col;
	int currentp = 0; 
	int currenta = 0;	
	
	cout<<"Great! Let's begin!\n";
	cout<<"Do you want to make a (f)illed or (h)ollow rectangle?\n";
	cin>>type;
	
	//user will be denied if input is not either F or H
	if (type!='f'&&type!='F'&&type!='h'&&type!='H')
		cout<<"\tYou think I'm stupid!? Get out of my face!\n\n";
	
	else { //Program cont. with F or H input
		cout<<"Enter Length:";
		cin>>length;
		cout<<"\nEnter Width:";
		cin>>width;
		cout<<"\nEnter border character:";
		cin>>border;
	
	//filled rectangle start
	if (type=='f'||type=='F') {	
		cout<<"\nEnter fill character:";
		cin>>fill; 
	
		cout<<"Filled rectangle, let's do it!\n";
		
	for (row = 1; row <= width; row++) {
		
		for (col = 1; col <= length; col++) {
			if ( row == 1||row == width||
			col == 1 ||col == length)

				cout<<border;
			else
				cout<<fill;
		}
		cout<<endl;
	}//for close 

	frect++;
	currenta = length * width;
	currentp = (2 * length) + (2 * width);
	
	}//if close - filled rectangle
	
	//hollow rectangle start
	if (type=='h'||type=='H') {
	
		cout<<"One hollow rectangle coming up!\n";
	
	for (row = 1; row <= width; row++) {
		
		for (col = 1; col <= length; col++) {
			if (row == 1||row == width||
			col == 1||col == length)
		
				cout<<border;
			else
				cout<<" ";
		}
		cout<<endl;
	}//for close

	hrect++;
	currenta = length * width;
	currentp = (2 * length) + (2 * width);
	
	}//if close - hollow retangle

	area += currenta;
	perimeter += currentp;	
	//Two looped, resetting variables hold the A and P values
	//Then add themselves to the true area and perimeter values
	//This will be the basis for finding the averages
		
	cout<<"would you like to make another rectangle?\n";
	cin>>resp2; //asks user to repeat do... while	

	}//else close if proper TYPE is input

	}while (resp2=='y'||resp2=='Y');//do... while close

	
	total = frect + hrect;
	avarea = (float) area/total;
	avperim = (float) perimeter/total;	

	if (total > 0) {
		
		cout<<"That's all!? Fine, here is what you've done.\n";	
	
		cout<<"\n\tRectangle Statistics:\n";
		cout<<"Filled:"<<frect<<"\nHollow:"<<hrect
		<<"\nTotal:"<<total;
		cout<<"\nAverage Area:"<<avarea
		<<"\nAverage Perimeter:"<<avperim<<endl;		

		}//if any rectangles, output stats
	
	}//else close - program body




}//main close
