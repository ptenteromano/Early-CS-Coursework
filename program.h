/* Philip Tenteromano 2/17/2017
 *
 * Program header file with class declarations
 *
 */


#ifndef PROGRAM_H
#define PROGRAM_H

class Program {
	private:
		string campus;
		string degree;
		string major;
		string minor;
		void checkCampus(string camp);	//private helper
		void checkDegree(string degr);	//private helper
	public:
		Program();
		Program(string campus);
		void setProgram();
		void setCampus(string camp);
		void setDegree(string degr);
		void setMajor(string maj);
		void setMinor(string min);
		void print();
};

#endif
