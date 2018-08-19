/* 
 * A Hollow Box
 *
 * Philip Tenteromano 10/26/2016
 *
 * MAKING A BOX... HOLLOW
 *
 */

#include <iostream>

using namespace std;

main () {

	
	
	for (int row = 1; row <= 6; row++) {
				
			
		for (int col = 1; col <= 6; col++) {
			if ( row == 1 || row == 6 || col == 1 || col == 6)					cout<<"*";
			else
				cout<<" ";
		}
	cout<<endl;

	}
	
	cout<<endl;
}
