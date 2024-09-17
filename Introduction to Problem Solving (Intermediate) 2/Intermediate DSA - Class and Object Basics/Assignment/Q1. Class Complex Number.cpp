/*
Construct a class called ComplexNumber which stores two properties

real - The real part
imaginary - The imaginary part

The name of the properties should be strictly real and imaginary


Implement the following functionalities inside this class :-

add(ComplexNumber) -> Returns an object of ComplexNumber having sum of the two complex numbers.

subtract(ComplexNumber) -> Returns an object of ComplexNumber having difference of the two complex numbers.

multiply(ComplexNumber) -> Returns an object of ComplexNumber having multiplication of the two complex numbers.

divide(ComplexNumber) -> Returns an object of ComplexNumber having division of the two complex numbers.
*/

class ComplexNumber {
	public :
	    
	    float real, imaginary;
		
		// Define constructor here
		ComplexNumber(float real_val, float img_val) {
			this->real = real_val;
			this->imaginary = img_val;
		}
		
		
		ComplexNumber add(ComplexNumber x){
			// Complete the function
			float temp_real = this->real + x.real;
			float temp_img = this->imaginary + x.imaginary;
			ComplexNumber com_num(temp_real, temp_img);
			return com_num;
		}
		
		ComplexNumber subtract(ComplexNumber x){
			// Complete the function
			float temp_real = this->real - x.real;
			float temp_img = this->imaginary - x.imaginary;
			ComplexNumber com_num(temp_real, temp_img);
			return com_num;			
		}
		
		ComplexNumber multiply(ComplexNumber x){
			// Complete the function
			float temp_real = this->real * x.real 
                            - this->imaginary * x.imaginary;
			float temp_img = this->real*x.imaginary 
                            + this->imaginary * x.real;
			ComplexNumber com_num(temp_real, temp_img);
			return com_num;			
		}
		
		ComplexNumber divide(ComplexNumber x){
			// Complete the function
			float temp_real = (this->real * x.real + this->imaginary * x.imaginary)
                                / (x.real * x.real + x.imaginary * x.imaginary);
			float temp_img = (this->imaginary * x.real - this->real * x.imaginary)
                                / (x.real * x.real + x.imaginary * x.imaginary);
			ComplexNumber com_num(temp_real, temp_img);
			return com_num;			
		}
};

/*
    ComplexNumber a = new ComplexNumber(10, 5)
	ComplexNumber b = new ComplexNumber(2, 3)
	ComplexNumber c1 = a.add(b) 
	ComplexNumber c2 = a.subtract(b)
	ComplexNumber c3 = a.multiply(b)
	ComplexNumber c4 = a.divide(b)

*/