/*
Construct a class called Matrix which stores a 2D Array. It should store

The number of rows

The number of columns

The 2D Array itself

Implement the following functionalities inside this class :-

input() -> Reads the input from the user. This method should read the input from the user and populate the entire array. Each row will be in a new line and all the elements in a row will be space-separated.

add(Matrix) -> Returns the sum of two matrices. Assume the matrices provided have the same dimensions.

subtract(Matrix) -> Returns the sum of two matrices. Assume the matrices provided have the same dimensions.

transpose() -> Returns a new matrix containing the transpose of the given original matrix.

print() -> prints the entire matrix row by row. Each row will be in a new line and values in each row should be separated by a single space.

You may define any properties in the class as you see appropriate.
*/
class Matrix {
	public :
	    // Define properties here
        int rows;
        int columns;
        vector<vector<int> > matrix_var;		
		
		// Define constructor here
		Matrix (int row, int col) 
        : rows (row)
        , columns (col) {
            for (int i = 0; i < rows; i++) {
                vector<int> vec_col(columns);
                matrix_var.push_back(vec_col);
            }
        }
		
		void input(){
			// Complete the function
			for (int i = 0; i < rows; i++) {
                for (int j = 0; j < columns; j++) {
                    cin >> matrix_var[i][j];
                }
            }
		}
		
		Matrix add(Matrix x){
			// Complete the function
			Matrix res = Matrix(rows, columns);
            for (int i = 0; i < rows; i++) {
                for (int j = 0; j < columns; j++) {
                    res.matrix_var[i][j] = this->matrix_var[i][j] 
                                        + x.matrix_var[i][j]; 
                }
            }
            return res;
		}
		
		Matrix subtract(Matrix x){
			// Complete the function
			Matrix res = Matrix(rows, columns);
            for (int i = 0; i < rows; i++) {
                for (int j = 0; j < columns; j++) {
                    res.matrix_var[i][j] = this->matrix_var[i][j] 
                                        - x.matrix_var[i][j]; 
                }
            }
            return res;
		}
		
		Matrix transpose(){
			// Complete the function
            Matrix res = Matrix(columns, rows);
            for (int i = 0; i < rows; i++) {
                for (int j = 0; j < columns; j++) {
                    res.matrix_var[j][i] = this->matrix_var[i][j]; 
                }
            }
            return res;			
		}
		
		void print(){
			// Complete the function
			for (int i = 0; i < rows; i++) {
                for (int j = 0; j < columns; j++) {
                    cout << this->matrix_var[i][j] << " "; 
                }
                cout << endl;
            }
		}
};

/*
    Matrix a = new Matrix(10, 5)  // 10 rows, 5 columns
	a.input() 
	Matrix b = new Matrix(10, 5)  // 10 rows, 5 columns
	b.input()
    Matrix c1 = a.add(b)
    Matrix c2 = a.subtract(b)
    Matrix c3 = a.transpose()
    a.print()
*/