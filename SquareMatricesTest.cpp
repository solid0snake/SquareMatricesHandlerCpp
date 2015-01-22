/*
* SquareMatricesTest.cpp
* By Pedro Garate on 10/17/2014
* Description: Test the ADT for a Square Matrices Handler
* 				For this program we only consider square matrices.
* 				This program adds and multiplies matrices given
* 				that both matrices have the same size. It also
* 				multiplies matrices by a scalar and transpose
* 				matrices as well.
*/

#include "SquareMatrices.h"
#include <vector>
#include <iostream>

using namespace std;

vector<vector<int>> setUpMatrix(int dimension);

int main() {
	cout << "SQUARE MATRICES HANDLER:" << endl;
	cout << "For this program we only consider square matrices.\n"
		"This program adds and multiplies matrices given\n"
		"that both matrices have the same size. It also\n"
		"multiplies matrices by a scalar and transpose\n"
		"matrices as well." << endl;

	//harcoded matrices
	//it can be implemented to get input from user
	vector<vector<int>> a = { { 1, 2, 3 }, { 4, 5, 6 }, { 7, 8, 9 } }; // 3x3
	vector<vector<int>> b = { { -2, -4, -6 }, { 8, 10, 12 }, { 3, -5, -7 } };// 3x3
	vector<vector<int>> c = { { 2, 4 }, { 6, 8 } }; // 2x2

	SquareMatrices matrixA(a);
	cout << endl << "Matrix A:\n" << matrixA << endl;
	SquareMatrices matrixB(b);
	cout << "Matrix B:\n" << matrixB << endl;
	SquareMatrices matrixC(c);
	cout << "Matrix C:\n" << matrixC << endl;

	//test setAllToZero function
	//make a matrix of 2x2 all initialized to zero.
	SquareMatrices matrixD;
	matrixD.setAllToZero(2);
	cout << "Matrix D:\n" << matrixD << endl;

	//test getValue and setValue functions
	//get value (2,3) from matrix A
	cout << "This is the value at (2,3) in Matrix A: " << matrixA.getValue(2, 3);
	//set value (2,3) from matrix A to -6
	cout << "\nLet's change this value to -6.\n";
	matrixA.setValue(2, 3, -6);
	cout << "The new matrix A is:\n" << matrixA << endl;

	//test transPose function on matrix B
	cout << "Let's transpose matrix B.\nThe resulting matrix would be:\n";
	cout << matrixB.transPose();

	//test multiplication of two matrices. overloaded operator *
	//if dimensionality is not equal a matrix of 0x0 is returned
	cout << "\nAxC is:\n";
	cout << matrixA * matrixC;
	cout << "\nAxB is:\n";
	cout << matrixA * matrixB;

	//test multiplication by a scalar
	cout << "\n5C is:\n";
	cout << matrixC * 5;

	//test substraction of two matrices. overloaded operator -
	//if dimensionality is not equal a matrix of 0x0 is returned
	cout << "\nA-C is:\n";
	cout << matrixA - matrixC;
	cout << "\nA-B is:\n";
	cout << matrixA - matrixB;

	return 0;
} // end of main
