/* Philip Tenteromano 2/3/2017
 *
 * Lab 11.1 Basic Structures
 *
 */

#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

struct rectangle {
	float length;
	float width;
	float area;
	float perimeter;
};

main() {

	string type = "rectangle";

	rectangle box;
	
	cout<<"Enter the length of a rectangle: ";
	cin>>box.length;

	cout<<"Enter the width of a rectangle: ";
	cin>>box.width;
	
	cout<<endl<<endl;

	box.area = box.length * box.width;
	box.perimeter = (2*box.length) + (2*box.width);
	
	cout<<fixed<<showpoint<<setprecision(2);

	if (box.length == box.width)
		type = "square";

	cout<<"The area of the "<<type<<" is "<<box.area<<".\n";
	cout<<"The perimeter of the "<<type<<" is "<<box.perimeter<<".\n";

}	
