/* Written Midterm 11/16/2016
 *
 * Philip Tenteromano
 *
 * Simple program written for last question on midterm
 *
 */

#include <iostream>

using namespace std;

main () {

	string name;
	int scale;
	
	cout<<"I see you're taking Computer Science!\n"
	<<"What's your name?\n";
	cin>>name;

	cout<<"Okay, "<<name<<", on a scale of 1 to 5 (with 5 being the best),\n"
	<<"how would your rate your professor?\n";
	cin>>scale;

	if (scale == 1) 
		cout<<"Feel sorry for you, "<<name<<"!";
	if (scale == 2)
		cout<<"Well, "<<name<<", not totally horrible!!";
	if (scale == 3)
		cout<<"Don't you hate the average ones, "<<name<<"!!!";
	if (scale == 4)
		cout<<"Cool, "<<name<<"!!!!";
	if (scale == 5)
		cout<<"Lucky you, "<<name<<"!!!!!";
	if (scale > 5 || scale < 1)
		cout<<"That's not on the scale!";


 	cout<<endl;

}
			
