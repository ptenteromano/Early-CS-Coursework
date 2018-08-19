/* Philip Tenteromano 2/17/2017
 *
 * Name class header file
 *
 */

#ifndef NAME_H
#define NAME_H

class Name {
	private:
		string fName;
		string lName;
		char middleI;
	public:
		Name();
		Name(string f, char m, string l);
		void setName();
		void setFirst(string f);
		void setLast(string l);
		void setMiddle(char m);
		string getFirst();
		string getLast();
		char getMiddle();
		void printFull();
};

#endif
