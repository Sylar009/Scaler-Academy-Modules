/*
Problem Description

Construct a class Rectangle that represents a rectangle.

The class should support the following functionalities:-

perimeter() -> returns the perimeter of the rectangle
area() -> returns the area of the rectangle
Input format:

First argument A is an integer representing the number of testcases.
For each case, x (length) and y (breadth) are taken as input in new line.
Output format:

The perimeter and area of the constructed rectangle are printed.
Sample Input:

1 # number of cases
1 # radius of first case
2 # radius of second case
Sample output:

4 #perimeter of rectangle
1 #area of rectangle

*/

class Rectangle {
	public :
	    // Define properties here
		int length;
        int width;
		
		// Define constructor here
        Rectangle(int len, int wid) 
            : length (len)
            , width (wid) {}
		
		
		int perimeter(){
			// Complete the function
            return (2 * (this->length + this->width));			
		}
		
		int area(){
			// Complete the function
			return (this->length * this->width);
		}
};

/*
    Rectangle a = new Rectangle(2, 3)  // Length = 2, Breadth = 3
	a.perimeter() // Should give 10
    a.area() // Should give 6
*/