/* Simple Calculator 11/16/2016
 *
 * Phil Tenteromano
 *
 * Program using functions which runs a simple calculator.
 *
*/

#include <iostream>

using namespace std;

main () {

	//program functions
	void getEquation(int &, char &, int &);
	float processEquation(int &, char &, int &);
	bool continueCalc(float &, int &, int &);
	
	//operator functions found within processEquation
	int add(int,int);
	int subtraction(int, int);
	int multiply(int, int);
	float division(int &);
	
	//variables - value is used to loop, based off of sentinel values
	int op1 = 0, op2 = 0;
	char op;
	float result;
	bool value;
	
	do {
		
		//function to input equation
		getEquation(op1, op, op2);
	
		//function which processes and returns the resulting variable
		result = processEquation(op1, op, op2);
		
		//using both the result and the sentinel value, determine whether to 
		//repeat program, or show an error: division by 0  
		value = continueCalc(result, op1, op2);
			
		
		cout<<endl;
		

		//if statement will not show result if division by 0, only the error
		if (result != -9999)
			cout<<result<<endl;
	
		

	}while(value);

	cout<<"\tTime to register for that algebra course now!"<<endl;

		
}//main close***

	
	

	int add(int, int);
	int subtract(int, int);
	int multiply(int, int);
	float division(int, int);
		
	
	//this is the function which determines loop	
	bool continueCalc(float &result, int &op1, int &op2) {
		bool val;
		
		if (op1 == 0 && op2 == 0)
			val = 0;
		else
		if (result == -9999) {
			cout<<"\nCan't divide by 0!!! Try again!\n";
			val = 1;
		}
		else
			val = 1;
		
		return(val);
	}	
		


	//the simple input function
	void getEquation (int &op1,char &op,int &op2) {
			
		cout<<"\nEnter your equation using integers. If you want to terminate, input 0*0\n";
				
		cin>> op1 >> op >> op2;
	}

	
	//the processing function
	float processEquation(int &op1,char &op, int &op2) {
		float res;
	
		//this switch has the operator functions within this function
		switch (op) {
			case '+':
			res = add(op1, op2);
			break;
			case '-':
			res = subtract(op1, op2);
			break;
			case '*':
			res = multiply(op1, op2);
			break;
			case '/':
			res = division(op1, op2);
			break;
		}

		return(res);
	}
		                

	//operator functions!!
	int add(int op1, int op2) {
		int res;
		res = op1+op2;
		return(res);
	}

	int subtract(int op1, int op2) {
		int res;
		res = op1-op2;
		return(res);	
	}

	int multiply(int op1, int op2) {
		int res;
		res = op1*op2;
		return (res);
	}

	float division(int op1, int op2) {
		float res = -9999;
		if (op2 != 0)
			res = (float) op1/op2;
		return (res);
	}

	
