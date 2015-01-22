/*
* SquareMatrices.cpp
* By Pedro Garate on 10/17/2014
* Description: Implementation of the ADT for a Square Matrices Handler
* 				For this program we only consider square matrices.
* 				This program adds and multiplies matrices given
* 				that both matrices have the same size. It also
* 				multiplies matrices by a scalar and transpose
* 				matrices as well.
*/

#include "SquareMatrices.h"

#include <iostream>
#include <vector>

using namespace std;

//	int dimen; --> number of rows & columns is the same (square matrix)
//	std::vector<std::vector<int>> matrix; --> elements

//default constructor. initialize size to 0x0
SquareMatrices::SquareMatrices() :dimen{ 0 }
{
}//end of SquareMatrices

//2nd constructor. initialize matrix from vector of vectors
SquareMatrices::SquareMatrices(std::vector<std::vector<int>>& vector)
{
	dimen = vector.size();
	matrix = vector;
}//end of 2nd constructor.

//set the size of matrix to sizeXsize and then initialize all to zero
void SquareMatrices::setAllToZero(int size)
{
	dimen = size;
	// resize matrix to dimen X dimen
	matrix.resize(dimen);
	for (int i = 0; i < dimen; i++)
		matrix[i].resize(size);
}//end setAllToZero

//retrieves value at position(row,col)
int SquareMatrices::getValue(int row, int col) const
{
	if (row <= dimen && col <= dimen)
		return matrix[row - 1][col - 1];
	else {
		cout << "Zero was returned because there is no (" <<
			row << "," << col << ") item." << endl;
		return 0;
	}
}// end of getValue

//set value at position(row,col) to newValue
void SquareMatrices::setValue(int row, int col, int newValue)
{
	if (row <= dimen && col <= dimen)
		matrix[row - 1][col - 1] = newValue;
	else
		return;
}// end of setValue

//transposes a matrix
SquareMatrices SquareMatrices::transPose()
{
	SquareMatrices temp;
	temp.setAllToZero(dimen);

	for (int col = 0; col < dimen; col++)
		for (int row = 0; row < dimen; row++)
			temp.matrix[col][row] = matrix[row][col];

	return temp;
}// end of transPose

// multiply a matrix by another if dimensionality matches
// returns an empty matrix (0x0) if dimensionality does not match
SquareMatrices operator*(SquareMatrices matrix1, SquareMatrices matrix2)
{
	if (matrix1.dimen == matrix2.dimen)
	{
		int size = matrix1.dimen;
		vector<vector<int> > result(size);
		for (int i = 0; i < size; i++)
			result[i].resize(size); // set up matrix matrix1 X matrix2

		for (int row = 0; row < size; row++) {
			for (int col = 0; col < size; col++) {
				for (unsigned int k = 0; k < size; k++)
					// <row of matrix1>.<col of matrix2> dot product.
					result[row][col] += matrix1.matrix[row][k] * matrix2.matrix[k][col];
			}
		}
		SquareMatrices res(result); //make an object to return
		return res;
	}
	else {
		// return an empty matrix of dimension 0
		SquareMatrices temp;
		return temp;
	}

}//end of operator*

// multiply a matrix by a scalar
SquareMatrices operator*(SquareMatrices matrix, int scalar)
{
	vector<vector<int>> result(matrix.dimen);
	for (int row = 0; row < matrix.dimen; row++)
		result[row].resize(matrix.dimen);

	for (int row = 0; row < matrix.dimen; row++)
		for (int col = 0; col < matrix.dimen; col++)
			result[row][col] = matrix.matrix[row][col] * scalar;

	SquareMatrices res(result);
	return res;
}// end of operator*

// substract a matrix from another if dimensionality matches
// returns an empty matrix (0x0) if dimensionality does not match
SquareMatrices operator-(SquareMatrices matrix1, SquareMatrices matrix2)
{
	if (matrix1.dimen == matrix2.dimen)
	{
		int size = matrix1.dimen;
		vector<vector<int> > result(size);
		for (int i = 0; i < size; i++)
			result[i].resize(size); // set up matrix matrix1 X matrix2

		for (int row = 0; row < size; row++) {
			for (int col = 0; col < size; col++) {
				result[row][col] = matrix1.matrix[row][col] - matrix2.matrix[row][col];
			}
		}
		SquareMatrices res(result);
		return res;
	}
	else {
		// return an empty matrix of dimension 0
		SquareMatrices temp;
		return temp;
	}
}// end of operator-

// output a matrix
std::ostream& operator<<(std::ostream& os, const SquareMatrices& matrix)
{
	for (int row = 0; row<matrix.dimen; row++) {
		for (int col = 0; col<matrix.dimen; col++){
			os << matrix.matrix[row][col] << "\t"; // show matrix
		}
		os << endl;
	}
	return os;
}// end of operator<<
