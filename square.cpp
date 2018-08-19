// This program declares the Square class and uses member functions to find
// the perimeter and area of the square

// Philip Tenteromano 2/13/2017
// Lab 13.1 

#include <iostream>
using namespace std;

class Square {
	private: 
		int side;
	public:
		Square();
		Square(float length);
		void setSide(float length);
		float findArea();
		float findPerimeter();
		~Square();
};

int main()
{
	Square box;	// box is defined as an object of the Square class
	float size;	// size contains the length of a side of the square
	
	//FILL IN THE CLIENT CODE THAT WILL ASK THE USER FOR THE LENGTH OF THE SIDE OF 
	//THE SQUARE (this is stored in size)
	cout<<"Enter the side of a square: ";
	cin>>size;

	//FILL IN THE CODE THAT CALLS SetSide.
	box.setSide(size);
	
	// FILL IN THE CODE THAT WILL RETURN THE AREA FROM A CALL TO A FUNCTION
	// AND PRINT OUT THE AREA TO THE SCREEN.
	cout<<"The area of the square is: "<<box.findArea()<<endl;

	// FILL IN THE CODE THAT WILL RETURN THE PERIMETER FROM A CALL TO A
	// FUNCTION AND PRINT OUT THAT VALUE TO THE SCREEN.
	cout<<"The perimeter of the square is: "<<box.findPerimeter()<<endl;

	//second object for exercise 2:
	Square box1(9);

	cout<<"The area of box1 is: "<<box1.findArea()<<endl;

	cout<<"The perimeter of box1 is: "<<box1.findPerimeter()<<endl;


	return 0;
}

// _______________________________________________________
//
// Implementation section	Member function implementation

//**************************************************
//  setSide
//
//  task:	 This procedure takes the length of a side and
//	         places it in the appropriate member data
//  data in: length of a side
//***************************************************

void Square::setSide(float length)
{
	side = length;
}

//**************************************************
//	findArea
//
//  task:	       This finds the area of a square
//  data in:       none (uses value of data member side)
//  data returned: area of square
//***************************************************

float Square::findArea()
{
	return side * side;
}

//**************************************************
//	findPerimeter
//
//  task:	       This finds the perimeter of a square
//  data in:       none (uses value of data member side)
//  data returned: perimeter of square
//***************************************************

float Square::findPerimeter()
{
	return 4 * side;
}



//Exercise 2:

Square::Square() {
	side = 1;
}

Square::Square(float length) {
	side = length;
}

Square::~Square() {}


