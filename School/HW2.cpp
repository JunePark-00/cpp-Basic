#include <iostream>
#include <time.h>
#define ROW 3
#define COL 3
using namespace std;

/*
HW 2 (5pts, Due: 10/4 23:59PM)
Provide a class Matrix to complete this code.
This class should support the following functionalities:

1. Matrix Creation
A 3 by 3 matrix is created. All values are intialized as non-zero integers.
You may want to use rand for this.

2. Matrix Addtion and Multiplication
You may want to use operator overloading.

3. Display
The values of a matrix are "well" displayed.

Submit this file to the LMS.
*/

//Your code goes here.
class Matrix{
private:
	int m[ROW][COL];
	
public:
	Matrix(){
		for(int i = 0; i < ROW; i++){
			for (int j = 0; j < COL; j++){
				m[i][j] = rand() % 100 + 1;
			}
		}
	}

	Matrix operator+(Matrix);
	Matrix operator*(Matrix);
	void show();
};

Matrix Matrix::operator+(Matrix ma){
	Matrix temp;
	for(int i = 0; i < ROW; i++){
		for (int j = 0; j < COL; j++){
			(temp.m)[i][j] = (this->m)[i][j] + (ma.m)[i][j];
		}	
	}
    return temp;
}

Matrix Matrix::operator*(Matrix ma){
	Matrix temp;
	for(int i = 0; i < ROW; i++){
		for (int j = 0; j < COL; j++){
			(temp.m)[i][j] = (this->m)[i][j] * (ma.m)[i][j];
		}	
	}
    return temp;
}

void Matrix::show(){
	for(int i = 0; i < ROW; i++){
		for (int j = 0; j < COL; j++){
			cout << m[i][j] << " ";
		}
		cout << endl;		
	}
}

//DO NOT TOUCH THE MAIN FUNCTION.
int main() {

	Matrix A, B, C;		// 3 by 3 matrix created. All values are intialized as non-zero integers.

	Matrix D = A + B;	// Matrix Addition
	Matrix E = A * C;	// Matrix Multiplication

	cout << "A" << endl;
	A.show();		// display the values
	cout << "B" << endl;
	B.show();
	cout << "C" << endl;
	C.show();


	cout << "A + B" << endl;
	D.show();

	cout << "A * C" << endl;
	E.show();

	return 0;
}