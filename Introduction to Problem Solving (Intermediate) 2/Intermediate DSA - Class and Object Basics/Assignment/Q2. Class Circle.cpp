/*
Problem Description


Construct a class Circle that represents a Circle.

The class should support the following functionalities:-

perimeter() -> returns the perimeter of the circle
area() -> returns the area of the circle

Note: Assume Π (pi) = 3.14 for calculations.

Input Format:

First argument A is an integer representing the number of testcases.
For each case, the radius r is taken as input in new line.
Output Format:

The perimeter and area of the constructed circle is printed.
Sample Input:

2     # number of cases
1     # radius of first case
2     # radius of second case
Sample output:

6.28     #perimeter of first case
3.14     #area of first case
12.56    #perimeter of second case
12.56    #area of second case
*/

class Circle {
	public :
	    // Define properties here
        int radius;
        const float pi = 3.14; 
		
		
		// Define constructor here
		Circle (int rad) : radius(rad){}
		
		float perimeter(){
			// Complete the function
            return (2 * pi * this->radius);			
		}
		
		float area(){
			// Complete the function
			return (pi * this->radius * this->radius);
		}
};

/*
    Circle a = new Circle(3)  // Radius = 3
	a.perimeter() // 18.84
    a.area() // 28.26
*/