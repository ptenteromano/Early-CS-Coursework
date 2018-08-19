//test run of functions
//
//

#include <iostream>

using namespace std;

main () {

	void getEquation(int&, char, int&);
	int op1 = -1, op2 = -1;
	char op = 'z';

	
	getEquation (op1, op, op2);
	cout<<"back in main()"<<endl;	
	cout<<op1 << op <<op2 << endl;
	

}
	void getEquation (int &op1, char op, int &op2) {
		cout<<"getEquation()"<<endl;
		cout<<op1 << op<< op2<< endl;
		cout<<"Enter Equation";
		cin >> op1 >> op >> op2;
		cout<<op1 << op << op2;
		cout<<"done in function"<<endl;
	}










