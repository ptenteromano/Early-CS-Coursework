/* Philip Tenteromano 2/3/2017
 *
 * Lab 11.2 initializing structures
 *
 */

#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

struct taxPayer {
	string name;
	long socialSecNum;
	float taxRate;
	float income;
	float taxes;
};

main() {
	taxPayer citizen1 = {"Tim Mcguiness", 255871234, 0.35};
	taxPayer citizen2 = {"John Kane", 278990582, 0.29};

	cout<<fixed<<showpoint<<setprecision(2);

	cout<<"Please enter the income for the first citizen:";
	cin>>citizen1.income;
	
	citizen1.taxes = citizen1.income * citizen1.taxRate;

	cout<<"Name: "<<citizen1.name<<endl;
	cout<<"Social Security Number: "<<citizen1.socialSecNum<<endl;

	cout<<"Taxes due for this year: $"<<citizen1.taxes<<endl<<endl;

	cout<<"Please enter the income for the second citizen:";
	cin>>citizen2.income;

	citizen2.taxes = citizen2.income * citizen2.taxRate;

	cout<<"Name: "<<citizen2.name<<endl;
	cout<<"Social Security Number: "<<citizen2.socialSecNum<<endl;
	
	cout<<"Taxes due for this year: $"<<citizen2.taxes<<endl<<endl;

}
