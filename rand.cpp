/* Guess my Number Lab 11/9/2016
 *
 * Phil Tenteromano
 *
 * Using random number generator to produce a 
 *
 * guessing game.
 *
 */

#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

main () {

	char resp, resp2;
	int guess, rnum, seed = time(0), guessnum;	
	
	cout<<"Welcome to the guessing game!\n\t"
	<<"Can you guess my number?(y/n)\n";
	cin>>resp;

	if (resp!='y'&&resp!='Y')
		cout<<"You wouldn't figure it out anyway!\n";

	else {
		srand (seed);
		int randmax = 100;
		int shift = 1;
		int playtime = 0;
	do {
		rnum = rand()%randmax+shift;
		
		cout<<"My number is between 1-100! You only get 10 guesses!\n";
		guessnum = 0;
		playtime++;
				
		do { 
			
			cin>>guess;
			guessnum++;
			
			if (guess > rnum) 
				cout<<"You're too high!\n";
		
			else
			if (guess < rnum) 
				cout<<"You're too low!\n";
			
		
		}while (guess != rnum && guessnum <= 12);
		
		if (guessnum <=  6) 
			cout<<"Wow, you got it right in "<<guessnum<<" tries!\n";
		else
		if (guessnum <= 12)
			cout<<"Not bad, you did it in "<<guessnum<<" tries!\n";
		else
			cout<<"It took you more than 12 tries! GAME OVER!\n";

			
		cout<<"\n\tWant to play again!?(y/n)\n";
		cin>>resp2;

	}while (resp2 == 'y'|| resp2 == 'Y');//entire game do... while loop
	
	cout<<"\nYou've played the game "<<playtime<<" times!";
	cout<<"\nCome back when you want to play more!\n";
	
		
	}//else close to start program
		


}//main close
