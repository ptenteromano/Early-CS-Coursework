#include <iostream>
using namespace std;


int board[3][3] = { 1,2,3, 4,5,6, 7,8,9 };

int main() {

	for ( int r = 0; r <= 2; r++ ) {
		for (int c = 0; c<= 2; c++ )
			cout << board[r][c];

		cout << endl;
	}

}
