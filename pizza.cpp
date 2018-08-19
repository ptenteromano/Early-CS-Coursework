#include <iostream>
using namespace std;
main(){

	const float scost = 12.39;
	const float lcost = 15.98;

	float due, payment, change;
	int spizza, lpizza;

	
	cout<<"Please place your order.\nHow many 12in Pizzas would you like?\n";
	cin>>spizza;
	cout<<"How many 14in Pizzas would you like?\n";
	cin>>lpizza;
	due=(spizza*scost)+(lpizza*lcost);
	cout<<"You owe $"<<due<<", please input your payment amount.\n";
	cin>>payment;
	if (due > payment){
		cout<<"You think you're slick!? Your order has been cancelled.\n Have a nice day.\n";
	} else {

		change=payment-due;
		cout<<"Your change is $"<<change<<".\n";
		cout<<"\t---------------------------------------------------\n";
		cout<<"\tLittle Italy Pizzeria thanks you for your business!\n";
		cout<<"\t---------------------------------------------------\n";
		cout<<"\tYou have ordered "
            		<<spizza<<" 12inch pizzas at $"<<scost<<" each, and "
            		<<lpizza<<" 14inch pizzas at $"<<lcost<<" each!\n";
		cout<<"\tYou paid $"<<payment<<" and your change is $"<<change<<".\n";
		cout<<"\t---------------------------------------------------\n";
		cout<<"\tYour server is: Billy Bob Thornton\n";
		cout<<"\t---------------------------------------------------\n";
	}


}
