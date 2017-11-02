// Copyright(c): 2017 Bing-Hui WANG
//
// Author: Bing-Hui WANG
//
// Date: 2017-10-3
//
// Description: This code has build a Matrix class named "Matrix".
//
// See usage details in "./README.md"
// See examples in "./examples/"

#ifndef MATRIX_H
#define MATRIX_H

#include <vector>
#include <string>
#include <sstream>

#include <complex.h>

using namespace std;

class Matrix
{
	friend ostream & operator <<(ostream &o, const Matrix& A);

public:
	int n_rows;
	int n_cols;
	double **data;

public:
	Matrix exchange_row(const int& row1, const int& row2);
	Matrix scale_row(const double& scale, const int& row);
	Matrix scale_add_row(const int& row1, const double& scale, const int& row2);

	Matrix exchange_col(const int& col1, const int& col2);
	Matrix scale_col(const double& scale, const int& col);
	Matrix scale_add_col(const int& col1, const double& scale, const int& col2);

	Matrix col(const int& it_col);
	Matrix cat(const Matrix& A);

public:
	Matrix();
	Matrix(int rows, int cols);
	Matrix(const Matrix& A);
	~Matrix();
	Matrix input();

	void clear();

	Matrix& operator =(const Matrix& A);
	Matrix  operator -()const;
	Matrix friend operator +(const Matrix& A, const Matrix& B);
	Matrix friend operator -(const Matrix& A, const Matrix& B);
	Matrix friend operator *(const Matrix& A, const Matrix& B);
	Matrix friend operator *(double scale, const Matrix& B);
	Matrix friend operator /(const Matrix& B, double scale);

	bool friend operator ==(const Matrix& A, const Matrix& B);
	bool friend operator !=(const Matrix& A, const Matrix& B);

	Matrix t()const;
	Matrix inv()const;
	Matrix reduce()const;
	
	double det()const;
	double trac()const;
	int rank()const;
	bool empty()const;
	
	vector<Complex> eigenvalue()const;
	vector<Matrix> QR()const;
};

Matrix pow(Matrix A, int n);
Matrix eye(int n);
Matrix Gram_Schmidt(Matrix A);
Matrix correct(Matrix& A);
Matrix Householder(const Matrix& A);

#endif