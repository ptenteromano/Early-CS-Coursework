/* Philip Tenteromano 2/17/2017
 *
 * Savings Account Class
 *
 * Declarations, definitions, and main
 *
 * Lab 13.5
 *
 */

#include <iostream>
#include <iomanip>

using namespace std;

//class declaration
class SavingsAccount {
	private:
		int dollars;
		float cents;
		void addCents(int c);	   	//private helper to convert cash;
		void withdrawCents(int c); 	//private helper to subtract cents
	public:
		SavingsAccount();		//default constructor
		SavingsAccount(int d, int c);	//user defined constructor
		void initialDeposit();  //part 2 function
		void setDeposit(int d, int c);
		void setWithdrawal(int d, int c);
		void makeDeposit();		//part 2 function
		void makeWithdrawal();		//part 2 function
		void printBalance();
};

//function definitions
void SavingsAccount::addCents(int c)      //private helper to convert cash
{
	int excess;
	if (c >= 100) {
		excess = c/100;
		cents = c%100;
		dollars = dollars + excess;
	}
}

void SavingsAccount::withdrawCents(int c)  //private helper to subtract proper cents
{
	int excess;
	if (c >= 100) {			
		excess = c/100;
		dollars = dollars - excess;
		cents = 100 - (c%100);
		if (cents < 0)
			cents += 100;
	}
	if (cents < 0) {
		cents += 100;
		dollars -= 1;
	}
}


SavingsAccount::SavingsAccount()		//default constructor 
{
	dollars = 0;
	cents = 0;
}

SavingsAccount::SavingsAccount(int d, int c)  //user initialized constructor
{
	
	dollars = d;
	cents = c;
	addCents(c);
}

void SavingsAccount::initialDeposit()		//user input initial deposit 
{
	cout<<"Input the initial dollar amount: ";
	cin>>dollars;
	cout<<"Input the initial cents amount: ";
	cin>>cents;

	addCents(cents);
}

void SavingsAccount::setDeposit(int d, int c)
{
	dollars += d;
	cents += c;
	addCents(c);
}

void SavingsAccount::setWithdrawal(int d, int c)
{
	dollars -= d;
	cents -= c;
	withdrawCents(c);

}	

void SavingsAccount::makeDeposit()  		//user input deposits, on loop
{
	char resp;
	bool reply = false;
	int d, c;

	do {
		cout<<"Would you like to make a deposit? Y or y for yes ";
		cin>>resp;
		if (resp == 'y' || resp == 'Y') {
			cout<<"Please input the dollars to be deposited: ";
			cin>>d;
			cout<<"Please input the cents to be deposited ";
			cin>>c;
			reply = true;
		
			setDeposit(d, c);
		
		}
		else
			reply = false;

	}while(reply);
}

void SavingsAccount::makeWithdrawal() 		//user input withdrawals, on loop
{
	char resp;
	bool reply = false;
	int d, c;

	do {
		cout<<"Would you like to make a withdrawal? Y or y for yes ";
		cin>>resp;
		if (resp == 'y' || resp == 'Y') {
			cout<<"Please input the dollars to be withdrawn: ";
			cin>>d;
			cout<<"Please input the cents to be withdrawn: ";
			cin>>c;
			reply = true;

			setWithdrawal(d, c);
		}
		else 
			reply = false;

	}while(reply);
}


void SavingsAccount::printBalance()
{
	cout<<"Your balance is: "<<endl<<"Dollars: "<<dollars<<setw(6)<<" Cents: "<<cents
		<<endl;
}



//main
int main() {


	//part 1, bank1 is initiliazed
	SavingsAccount bank1(200, 50);

	bank1.setDeposit(40, 50);
	bank1.setWithdrawal(100, 98);
	
	bank1.printBalance();

	cout<<endl<<endl;


	//part 2: user defines bank2
	SavingsAccount bank2;
	
	bank2.initialDeposit();
	bank2.makeDeposit();
	bank2.makeWithdrawal();

	bank2.printBalance();

	cout<<endl<<endl;

}
