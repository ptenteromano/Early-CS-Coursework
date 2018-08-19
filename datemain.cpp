/* Philip Tenteromano 2/11/2017
 *
 * The execution of the Date class in a program
 *
 */

#include <iostream>
 
using namespace std;

#include "date.h"

int main() {

	Date day1;

	day1.getMonth();
	day1.getDay();
	day1.getYear();

	day1.setDate(2, 12, 2017);
	day1.getMonth();
	day1.getDay();
	day1.getYear();
}
