/*
Problem Description
Construct a class Fraction which stores a fraction. It should contain the

-Numerator
-Denominator

Assume denominator will never be 0.

The class should support the following functionalities

add(Fraction) -> Returns the sum of two fractions

subtract(Fraction) -> Returns the difference of two fractions

multiply(Fraction) -> Returns the product of two fractions

The fraction returned needs to be in the simplest form. If the fraction is p/q then p and q must be co-prime.

You may define any properties in the class as you see appropriate.


*/

class Fraction {
	public :
	    int numerator, denominator;
		
		// Define constructor here
        Fraction (int num, int denom) {
            int hcf = __gcd(abs(num),abs(denom));
            this->numerator = num / hcf;
            this->denominator = denom / hcf;
        }
		
		
		Fraction add(Fraction a){
			// Complete the function
            int n = (this->numerator * a.denominator) 
                    + (this->denominator * a.numerator);
			int d = (this->denominator * a.denominator);
            return Fraction(n, d);
		}
		
		Fraction subtract(Fraction a){
			// Complete the function
            int n = (this->numerator * a.denominator) 
                    - (this->denominator * a.numerator);
			int d = (this->denominator * a.denominator);
            return Fraction(n, d);			
		}
		
		Fraction multiply(Fraction a){
			// Complete the function
			int n = (this->numerator * a.numerator);
			int d = (this->denominator * a.denominator);
            return Fraction(n, d);
		}
};

/*
    Fraction x = new Fraction(2, 3)  // 2/3
	Fraction y = new Fraction(4, 5) // 4/5
    Fraction z = x.add(y) // 22/15
    Fraction z = x.subtract(y) // -2/15
    Fraction z = x.multiply(y) // 8/15
*/