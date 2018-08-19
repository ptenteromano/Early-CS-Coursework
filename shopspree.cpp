/* Shopping Spree 
 *
 * Philip Tenteromano 10/15/2016
 * 
 * This is a program that runs an online shopping spree.
 * 
 * When user selects to shop and inputs their budget a number of 
 * 
 * buying options appears which the user can afford. Upon choosing a
 * 
 * product, the user inputs a code and is asked if they want a receipt.
 * 
 * The receipt will be emailed if requested.   
*/
 #include <iostream>
using namespace std;
main() {

	char resp, buy, recresp, resp2, loop;
	string name, witch, mask, retro, trump, bwitch, email, endnow, 
	bmask, bretro, btrump, purch, browse, howto, ask, eresp, again;
	float budget, change, price, cheap;
	
	witch="\tA $39.00 Witchy Witch costume, purchase code: A\n";
	mask="\tA $50.00 Goooouulish mask, purchase code: B\n";
	retro="\tA $12.99 retro Madonna costume, purchase code: C\n";
	trump="\tA $24.99 Donald Trump costume, purchase code: D\n";
	
	bwitch="\tYou've purchased the $39.00 Witch costume!\n";
	bmask="\tYou've purchased the $50.00 Gooouulish mask!\n";
	bretro="\tYou've purchased the $12.99 Madonna costume!\n";
	btrump="\tYou've purchased the $24.99 Trump costume!\n";

	browse="Let's see what we have!\n";
	howto="Use the case-sensitive purchase code to buy - only one item please!\n";
	ask="Would you like a receipt to be emailed to you?\n";
	email="Please enter your email address.\n";
	endnow="Thank you for shopping with us!\n";
	again="Would you like to shop for another item?";
	cheap= budget - 12.99;

	
	
	
	cout<<"Welcome to HALLOWEEN online super store! Would you like to shop?\n\n";
	cout<<"Respond with y/Y!\n";
	cin>>resp;

	
	
		
	if (resp!='y'&&resp!='Y')
		cout<<"Not buying a costume today!? Please come again soon!\n";
	else {
		cout<<"Okay then, let's get started! What's your first name?\n";
		cin>>name;
		cout<<name<<", what's your budget looking like today?\n";
		cin>>budget;

	if (budget<12.99)
		cout<<"Get a job you bum! You won't be dressing up this year!\n";
	
	else {
	if (budget>=50) {
		cout<<browse;
		cout<<"So we have four items for you!\n"<<witch<<mask<<retro
		<<trump;
		cout<<howto;
		cin>>buy;
		
		switch (buy) {
			case 'A':
				purch = bwitch;
				price = 39;
				change = budget - 39;
				break;
			case 'B':
				purch = bmask;
				price = 50;
				change = budget - 50;
				break;
			case 'C':
				purch = bretro;
				price = 12.99;
				change = budget - 12.99;
				break;
			case 'D':
				purch = btrump;
				price = 24.99;
				change = budget - 24.99;
				break; }
		cout<<purch<<ask;
		cin>>recresp;
	if (recresp!='y'&&recresp!='Y') {
		cout<<"Your remaining balance is: $"<<change<<"!\n";
		
		if (change>=12.99) {
			cout<<again;
			cin>>loop; }
					}
	else {
		cout<<email;
		cin>>eresp;
		cout<<"The email has been sent.\n";
		cout<<"\tYour remaining balance is: $"<<change<<"!\n"; 
		
		if (change>=12.99) {
			cout<<again;
			cin>>loop; }  
	    }
	}
	
	else{
	if (budget>=39) {
		cout<<"We can work with this! Let's see what we have.\n";
		cout<<"we have three items for you!\n"<<witch<<retro<<trump; 
		cout<<howto;
		cin>>buy;
		
		switch (buy) {
			case 'A': 
				purch = bwitch;
				price = 39;
				change = budget - 39;
				break;
			case 'C':
				purch = bretro;
				price = 12.99;
				change = budget -12.99;
				break;
			case 'D':
				purch = btrump;
				price = 24.99;
				change = budget - 24.99;
				break; }
		cout<<purch<<ask;
		cin>>recresp;
	if (recresp!='y'&&recresp!='Y') {
		cout<<"Your remaining balance is: $"<<change<<"!\n"; 
		
		if (change>=12.99) {
			cout<<again;
			cin>>loop; } 
		}
	
	else {
		cout<<email;
		cin>>eresp;
		cout<<"The email has been sent.\n";
		cout<<"Your remaining balance is: $"<<change<<"!\n";
		
		if (change>=12.99) {
			cout<<again;
			cin>>loop; } 
	     }
	}			
	
	else{
	if (budget>=24.99) {
		cout<<"Not a big spender, huh? Let's see what we have for you.\n";
		cout<<"We have two items for you!\n"<<retro<<trump;
		cout<<howto;
		cin>>buy;
		
		switch (buy) {
			case 'C':
				purch = bretro;
				price = 12.99;
				change = budget - 12.99;
				break;
			case 'D':
				purch = btrump;
				price = 24.99;
				change = budget - 24.99;
				break; }
		
		cout<<purch<<ask;
		cin>>recresp;
		if (recresp!='y'&&recresp!='Y') {
			cout<<"Your remaining balance is: $"<<change<<"!\n";
		
		if (change >=12.99) {
			cout<<again;
			cin>>loop; }
						}
	else {
		cout<<email;
		cin>>eresp;
		cout<<"The email has been sent.\n";
		cout<<"Your remaining balance is: $"<<change<<"!\n\n"; 
		
		if (change>=12.99) {
			cout<<again;
			cin>>loop;}
	
	
	else {
		if (budget>=12.99) {
			cout<<"Your budget is looking a bit SCARY!\n\n"; 
			cout<<"We only have the retro Madonna Costume!\n";
			cout<<"\tThe price is a low $12.99, on sale now!\n\n";
			cout<<"Would you like to buy? (y/Y or n/N)\n";
			cin>>resp2; 
	
		if (resp2!='y'&&resp2!='Y')
			cout<<"That's too bad, good luck finding a costume!!\n\n";
		else { 
			cout<<"You just purchased the retro Madonna costume!";
			cout<<ask;
			cin>>recresp;
		if (recresp!='y'&&recresp!='Y') 
			cout<<"Your remaing balance is: $"<<cheap<<"!\n";
		else {
			cout<<email;
			cin>>eresp;
			cout<<"The email has been sent.\n";
			cout<<"Your remaining balance is: $"<<cheap<<"!\n\n"; }
		     }
	
	}}}}}}
	
}}
	cout<<endnow;	
}


