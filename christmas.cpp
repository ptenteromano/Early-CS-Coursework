/*
 * 12 Days of Christmas
 *
 * Phil Tenteromano 11/2/2016
 *
 * This program will output the twelve days of Christmas using a do.. while, 
 * and for loops.
 *
 */

#include <iostream>

using namespace std;

main() {

	
	string giftday, name;
	char resp;
	
	cout<<"Christmas is almost here, who's been a good boy/girl? (name)\n";
	cin>>name;
		
	cout<<name<<", feeling festive? (y/n)\n";
	cin>>resp;
	
	if (resp!='y'&&resp!='Y')
		cout<<"Come back in December!\n";
	
	//begin program with y/Y response
	else {
	
	char answer;
	
	do {
		
		//for loop to create initial line of song via switch statement
		for (int day = 1; day <= 12; day++) {

			switch (day) {
				case 1:
					giftday = "first";
					break;
				case 2:
					giftday = "second";
					break;
				case 3:
					giftday = "third";
					break;
				case 4:
					giftday = "fourth";
					break;
				case 5:
					giftday = "fifth";
					break;
				case 6: 
					giftday = "sixth";
					break;
				case 7:
					giftday = "seventh";
					break;
				case 8:
					giftday = "eighth";
					break;
				case 9:
					giftday = "ninth";
					break;
				case 10:
					giftday = "tenth";
					break;
				case 11:
					giftday = "eleventh";
					break;
				case 12:
					giftday = "twelfth";
					break;
			} //switch close
		
		cout<<"\n\nOn the "<<giftday
		<<" day of Christmas, my true love gave to me\n";
	
			//for loop to generate gifts given on specific day
			for (int gift = day; gift >= 1; gift--) {
				
				//switch allows for loop to generate gifts in
				//descending order
				switch (gift) {
					case 1:
					cout<<"a patridge in a pear tree!\n";
					break;
					
					case 12:	
					cout<<"Twelve drummers drumming,\n";
					break;
					
					case 11:
					cout<<"Eleven pipers piping,\n";
					break;
					
					case 10:
					cout<<"Ten lords a-leaping,\n";
					break;
					
					case 9:
					cout<<"Nine ladies dancing,\n";
		                        break;
					
					case 8:
					cout<<"Eight maids a-milking,\n";
					break;
					
					case 7:
					cout<<"Seven swans a-swimming,\n";
					break;
					
					case 6:
					cout<<"Six geese a-laying,\n";
		                        break;
				
					case 5:
					cout<<"FIVE golden rings!!!\n";
		 			break;

					case 4:
			                cout<<"Four calling birds,\n";
					break;
					
					case 3:
					cout<<"Three French hens,\n";
					break;
					
					case 2:				
					cout<<"Two turtle doves,\nand ";
				}//switch close
			
					
			}//for (gift) close
		
		}//for (day)  close

		cout<<"\n\nWould you like to sing again?\n";
		cin>>answer;
		//variable input by user to sing again, using do... while
		
		} while (answer=='y'||answer=='Y'); //do close


	cout<<"That's it? We were supposed to sing forever.. and ever..."
	<<endl;
	
	
	} //else close

} //main close
