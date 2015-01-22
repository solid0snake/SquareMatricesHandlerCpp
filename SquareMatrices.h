/*
* SquareMatrices.h
* By Pedro Garate on 10/17/2014
* Description: Definition of an ADT for a Square Matrices Handler
* 				For this program we only consider square matrices.
* 				This program adds and multiplies matrices given
* 				that both matrices have the same size. It also
* 				multiplies matrices by a scalar and transpose
* 				matrices as well.
*/

#ifndef SQUAREMATRICES_H_
#define SQUAREMATRICES_H_

#include <iostream>
#include <vector>

class SquareMatrices {
private:
	int dimen; // number of rows & columns is the same (square matrix)
	std::vector<std::vector<int>> matrix; // elements
public:
	//default constructor. initialize size to 0x0
	SquareMatrices();
	//initialize matrix from vector of vectors
	SquareMatrices(std::vector<std::vector<int>>& vector);
	//set the size of matrix to sizeXsize and then initialize all to zero
	void setAllToZero(int size);
	//retrieves value at position(row,col)
	int getValue(int row, int col) const;
	//set value at position(row,col) to newValue
	void setValue(int row, int col, int newValue);
	SquareMatrices transPose(); //transposes a matrix
	// multiply a matrix by another if dimensionality matches
	friend SquareMatrices operator*(SquareMatrices matrix1, SquareMatrices matrix2);
	// multiply a matrix by a scalar
	friend SquareMatrices operator*(SquareMatrices matrix, int scalar);
	// substract a matrix from another if dimensionality matches
	friend SquareMatrices operator-(SquareMatrices matrix1, SquareMatrices matrix2);
	// output a matrix
	friend std::ostream& operator<<(std::ostream& os, const SquareMatrices& matrix);
};// end of SquareMatrices

#endif /* SQUAREMATRICES_H_ */
