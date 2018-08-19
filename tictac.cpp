/* Phil Tenteromano
 *
 * Tic Tac Toe Final 12/21/2016
 *
 * This Program is a Tic Tac Toe Game
 * using functions and arrays 
 *
 */


#include <iostream>

using namespace std;

//global variables provide a method of passing values to functions and maintaining them
const int Crow = 3, Ccol = 3; //constant 2D board variables
int input, row, col; //dynamic variables based on player input and switch statement
int counter = 0, player1win = 0, player2win = 0; //turn counter, as well as player statistics 
const char playerX = 'X', playerO = 'O'; //player1 will always go first as X
char winner = '*'; //a sentinel value for winner, if not X or O

//two arrays are used to create and play the board
int board[Crow][Ccol] = { {1,2,3}, {4,5,6}, {7,8,9} }; //displays position values
char box[Crow][Ccol] = { {' ',' ',' '}, {' ',' ',' '}, {' ',' ',' '} }; //a cleared board, only spaces

main () {

	bool resp = false;//replay variable for outer do... while loop
	
	//functions which are used in primary function (more functions are embedded in these functions) 
	bool winStatus(), checkWin(const char &);
	void displayBoard(), makeMove(), updateBoard(), clearBoard();

	//begin program
	cout<<"Welcome to Tic Tac Toe, Let's Play!\n";
	
	//primary program loop
	do { 
		winner = '*'; //reset sentinel win value to begin new game
		counter = 0; //reset turn counter to begin new game
		clearBoard(); //clear the board

		displayBoard(); //display board using numbers 1-9 for positions
	
		do {
			makeMove(); //player turn
		
			updateBoard(); //input X or O onto cleared board
	
			winner = checkWin(playerX); //uses tally to find winner
		
			if (winner != playerX) //if X is not winner, O may be winner
				winner = checkWin(playerO);
	
		}while (winner == '*'); //if checkWin function returns sentinel, continue playing
	
		resp = winStatus(); //after win, display stats and ask to play again

	}while(resp);
	

	cout<<"Thanks for playing!! Happy Holidays!\n";
	
}//main close


//valid move is used in the makeMove function
//checks for the range of 1-9, as well as if the position is empty
bool validMove() {
	bool inrange = true, valid = false;
	
	//the dynamic variables of row and col are changed based on the player move
	switch (input) {
		case 1:
			row = 0;
			col = 0;
			break;		
		case 2:
			row = 0;
			col = 1;
			break;
		case 3:
			row = 0;
			col = 2;
			break;
		case 4:
			row = 1;
			col = 0;
			break;
		case 5:
			row = 1;
			col = 1;
			break;
		case 6:
			row = 1;
			col = 2;
			break;		
		case 7:
			row = 2;
			col = 0;
			break;
		case 8:
			row = 2;
			col = 1;
			break;
		case 9:
			row = 2;
			col = 2;
			break;
		default:
			inrange = false;
			break;
	}
	if (inrange) { //if in range of switch, continue
		if (box[row][col] != playerX && box[row][col] != playerO) {
			//if empty space, count turn and input X or O       
			if (counter%2 == 0) 
				box[row][col] = playerX; //const char variable
			else
				box[row][col] = playerO; //const char variable
			valid = true;
			counter++;
		}
		else
			cout<<"That position has already been filled, pick another\n";
	}
	else
		cout<<"That is not a valid positiion on the board, pick another\n";

	return(valid);
}

//displaying the board with numbers 1-9
void displayBoard() {
	string border = "+---+---+---+";

	cout<<border<<endl;

	for (int r = 0; r < Crow; r++) {
	      	for (int c = 0; c < Ccol; c++) {
			cout<<'|'<<' '<<board[r][c]<<' ';
		}
		cout<<'|'<<endl<<border<<endl;
	}
}

//updating the board uses the empty box[][] array to fill in with X and O
void updateBoard() {
	string border = "+---+---+---+";

	cout<<border<<endl;

	for(int r = 0; r < Crow; r++) {
		for (int c = 0; c < Ccol; c++) {
			cout<<'|'<<' '<<box[r][c]<<' ';
		}
		cout<<'|'<<endl<<border<<endl;
	}
}

//the box[][] array stores X's and O's, this function will reset to a space after a win
void clearBoard() {

	for (int r = 0; r < Crow; r++) {
		for (int c = 0; c < Ccol; c++) {
			box[r][c] = ' ';
		}
	}
}

//the first move will output an instructional message, playerX will always go first.
void makeMove() {
	
	bool valid = false;

	do {
		if (counter == 0) //instructional message
			cout<<"Above is the game board, player1 is 'X' and will move first.\n";	
		if (counter%2 == 0) { //even moves are for player X
			cout<<"Player1 ('X') make your move (1-9):\n";
			cin>>input;
		}
		else { //odd moves are for player O
			cout<<"Player2 ('O') make your move (1-9):\n";
			cin>>input;
		}
		//the above validMove function is called to make sure the move is correct
		valid = validMove();
	
	//if an invalid move, continue to ask player to make a valid move
	}while(!valid);		
}

//this function passes the player (X or O) and a win tally by reference, used in the checkWin function
char tallyWin(const char &player, int &tally) {
	
	if (tally == 3)
		winner = player;
	else 
		tally = 0; //if no winner, reset tally to 0 to check another win condition

	return(winner);
}

//this function passes all 8 win conditions to whichever player is called to check for a win
char checkWin(const char &player) {
	char check = '*'; //another sentinel value	
	int tally = 0; //tally must equal 3 for a win
		
	//for loops shift through each row and column to find a win condition
	//calling the tallyWin function immediately after, attempting to change sentinel value
	for(int r = 0; r <Crow; r++) {
       		int c = 0;
 		if (box[r][c] == player)
			tally++;
	}
	check = tallyWin(player, tally);
			
	for(int r = 0; r < Crow; r++) {
	 	int c = 1;
	 	if (box[r][c] == player)
			tally++;
	}
	check = tallyWin(player, tally);
		
	for(int r = 0; r < Crow; r++) {
		int c = 2;
		if (box[r][c] == player)
			tally++;
	}
	check = tallyWin(player, tally);
		
	for(int c = 0; c < Ccol; c++) {
	       	int r = 0;
	 	if (box[r][c] == player)
		 	tally++;
	}
	check = tallyWin(player, tally);	
	
	for(int c = 0; c < Ccol; c++) {
	       	int r = 1;
		if (box[r][c] == player) 
			tally++;	
	}
	check = tallyWin(player, tally);
	
	for(int c = 0; c < Ccol; c++) {
	       	int r = 2;
		if (box[r][c] == player) 
			tally++;
	}
	check = tallyWin(player, tally);	

	//for the two diagnol conditions, do... while loops are used to change the r and c values
	//again, tallyWin is called to see if X or O has tallied 3 boxes
	{
		int r = 0, c = 0;
		do{
			if (box[r][c] == player) 
				tally++;
			r++, c++;
		}while(r < 3 && c < 3);
		check = tallyWin(player, tally);

		r = 2, c = 0; //reset r and c for the next diagnol win condition
		do{
			if (box[r][c] == player)
				tally++;
			r--; c++;
		}while(r >= 0 && c < 3);
		check = tallyWin(player, tally);
	}

	return(check);
}

//this final function displays after a win, with statistical information
//as well as the option to play again
bool winStatus() {
	char play; //Y or N char variable
	bool again = false; //the returned variable to play again

	if (winner == playerX) { //winner is congratulated, and stat incrimented
		cout<<"Player1 ('X') has won!\n";
		player1win++;
	}
	else if (winner == playerO) { //winner is congratulated, and stat incrimented
		cout<<"Player2 ('O') has won!\n";
		player2win++;
	}
	//displayed the stored win statistics
	cout<<"The score is:\n\tPlayer1: "<<player1win<<endl
	<<"\tPlayer2: "<<player2win<<endl<<endl;
	
	//replay question
	cout<<"Would you like to play again? (y/n)";
	cin>>play;
	
	if (play == 'y' || play == 'Y')
	       again = true;	

	return(again);
}




