/*
 * Math Challenge
 *
 * Philip Tenteromano 10/14/2016
 *
 * This is a program which runs a game when prompt.
 *
 * The game will ask for three numbers, then solve simple arithmetic problems. 
*/


#include <iostream>
using namespace std;
main() {

	char response1;
	string name1;
	int num1, num2, num3, sum, lnum, snum, gsum;
	float average, gaverage;


	cout<<"Welcome! Would you like to play a game? (y/Y).\n";
	cin>>response1;
	
	if (response1!='y'&&response1!='Y')
		cout<<"Ok then, come back when you're ready!\n";
	else{
		cout<<"Let's play! What's your first name?\n";
		cin>>name1;
		cout<<"Okay, "<<name1<<" nice to meet you. Please input three numbers (no fractions), with spaces in between.\n";
		
		cin>>num1>>num2>>num3;
		sum=num1+num2+num3;
		average=(float)sum/3;
		
		cout<<"Can you guess the following?\n";
		cout<<"Sum?";
		cin>>gsum;
		
		cout<<"\nAverage?";
		cin>>gaverage;
		
		cout<<"\nLet's see if you were right!\n";
		if (gsum==sum)
			cout<<"\tYou're right! The sum is "<<sum<<".\n";
		else{
			cout<<"\tSorry, the correct sum is "<<sum<<"!\n";}
		if (gaverage==average)
			cout<<"\tYou're right! The average is "<<average<<".\n";
		else
			cout<<"\tSorry, the correct average is "<<average<<"!\n";
		
		cout<<"I bet I can figure out your largest and smallest numbers!\n";
		if (num1>=num2&&num1>=num3)
			lnum=num1;
		else
		if (num2>=num3&&num2>=num1)
			lnum=num2;
		else 
			lnum=num3;

		cout<<"\tYour largest number is "<<lnum<<"!\n";
		
		if (num2>=num1&&num3>=num1)
			snum=num1;
		else
		if (num3>=num2&&num1>=num2)
			snum=num2;
		else
			snum=num3;
		
		cout<<"\tYour smallest number is "<<snum<<"!\n";
		cout<<"Thank you for participating, "
		<<name1<<"! I hope you enjoyed playing!\n";
}
}
