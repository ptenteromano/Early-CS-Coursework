/* Philip Tenteromano 2/11/2017
 *
 * Student Class Definitions
 * Holding Data members and 
 * member function declarations
 *
 */

#ifndef STUDENT_H
#define STUDENT_H

class Student {
	private:
		int studentID;
		string firstName;
		string lastName;
		char middleInitial;
		char gender;
		int month;
		int day;
		int year;
		void SetBirth(int m, int d, int y); //private helper to get birth
	public:
		Student();
		Student(string firstname, char middle, string lastname, int m, int d, int y);				 //includes private helper
		
		void SetName(string fname, char middle, string lname);
		void SetID (int Id);
		void SetGender (char sex);
		//accessors to print out given data
		int getID() const;
		void getBirth() const;
		void getName() const;
		char getGender() const;
};

#endif
