/* Philip Tenteromano 2/3/2017
 *
 * lab 11.3 Arrays of structures
 *
 */

#include <iostream>
#include <iomanip>

using namespace std;

struct taxPayer {
	float taxRate;
	float income;
	float taxes;
};

main() {

	taxPayer citizen[5];

	cout<<fixed<<showpoint<<setprecision(2);

	cout<<"Please enter the annual income and tax rate for 5 tax payers: "
		<<endl<<endl<<endl;

	for(int count = 0; count < 5; count++) {
		
		cout<<"Enter this year's income for tax payer #"<<(count+1)<<": ";
		cin>>citizen[count].income;

		cout<<"Enter the tax rate for the tax payer #"<<(count+1)<<": ";
		cin>>citizen[count].taxRate;

		citizen[count].taxes = citizen[count].income * citizen[count].taxRate;
		cout<<endl;
	}

	cout<<"Taxes due for this year: "<<endl<<endl;

	for(int count = 0; count < 5; count++) {

		cout<<"Tax Payer #"<<(count+1)<<": "<<"$"<<citizen[count].taxes<<endl;
	}
	//above, count+1 is needed to show the position, but [count] is used 
	//to locate the index of the array (since arrays begin with index 0
}
