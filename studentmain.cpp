/* Philip Tenteromano 2/11/2017
 *
 * Student main.cpp, to create an object Student
 * and manipulate data
 *
 */

#include <iostream>
#include <string>

using namespace std;

#include "student.h"

int main() {
	Student classmate1("Phil",' ', "Tenteromano", 8, 31, 1990);

	classmate1.SetID(654321);
	classmate1.SetGender('M');
	classmate1.getName();
	classmate1.getBirth();
	classmate1.getGender();
}
