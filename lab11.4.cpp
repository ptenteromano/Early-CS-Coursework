/* Philip Tenteromano 2/3/2017
 *
 * Lab 11.4 Nested Structures
 *
 */

#include <iostream>
#include <iomanip>

using namespace std;


struct dimensions {
	float length;
	float width;
};

struct results {
	float area;
	float perimeter;
};

struct rectangle {
	results attributes;
	dimensions sizes;
};

float computeA(float l, float w) {
	return l*w;
}

float computeP(float l, float w) {
	return (2*l) + (2*w);
}

main() {

	rectangle box;

	cout<<"Enter the length of a rectangle: ";
	cin>>box.sizes.length;

	cout<<"Enter the width of a rectangle: ";
	cin>>box.sizes.width;

	cout<<endl<<endl;

	box.attributes.area = computeA(box.sizes.length, box.sizes.width);
	box.attributes.perimeter = computeP(box.sizes.length, box.sizes.width);

	cout<<fixed<<showpoint<<setprecision(2);

	cout<<"The area of the rectangle is "<<box.attributes.area<<endl;
	cout<<"The perimeter of the rectangle is "<<box.attributes.perimeter<<endl; 

}
