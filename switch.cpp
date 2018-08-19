/*Switch Practice Lab
 *
 * Phil Tenteromano 10/19/2016
 *
 * 
*/

#include <iostream>

include namespace std;
main() {

	string resp;
	char seas;
	float temp;

	cout<<"Welcome to the seasons game! Want to play? Answer with yes, y or Y.\n";
	cin>>resp;
	
	if (resp=="yes"||resp=="y"||resp=="Y") {
	cout<<"Enter the first letter of the current season "
	<<"- Summer is denoted with M or m.\n"
	cin>>seas;
	cout<<"Also input today's temperature!\n";
	cin>>temp;
	
	switch (seas) {
		case 'W':
		case 'w':
			season="Winter";
			normtemp="55-65";
				break;
		case 'S':
		case 's':
			season="Spring";
			normtemp="70-80";
				break;
		case 'M':
		case 'm':
			season="Summer";
			normtemp="90-100";
				break;
		case 'F':
		case 'f':
			season="Fall";
			normtemp"70-80";
				break;
		default:
			season="Unknown";
		}
	
	if (seas=="Spring"||seas=="Fall") {
		cout<<"Your normal temperature range is 70-80 degrees!\n";
		cout<<"You input "<<temp;".\n";
	}

}
