/* Philip Tenteromano 2/11/2017
 *
 * Date class declarations
 *
 */



#ifndef DATE_H
#define DATE_H



class Date {
	
	private:
		int month;
		int day;
		int year;
		void validDate(int m, int d, int y); //private helper function
	public:
		Date(); //default constructor
		Date(int m, int d, int y); //overloaded constructor
		void setDate(int m, int d, int y);
		int getMonth() const;
		int getDay() const;
		int getYear() const;

};

#endif
