// Copyright(c): 2017 Bing-Hui WANG
//
// Author: Bing-Hui WANG
//
// Date: 2017-10-3
//
// Description: This code has build a Complex Number class named "Complex".
//
// See usage details in "./README.md"
// See examples in "./examples/"

#ifndef COMPLEX_H
#define COMPLEX_H

#include <iostream>
#include <cmath>
#include <stdlib.h>
#include <stdbool.h>

using namespace std;

class Complex
{
	// Define the cout format of Complex.
	friend ostream & operator <<(ostream &o, const Complex& x);

private:
	double real;	// Store the real part of a complex number.
	double imag;	// Store the imaginary part of a complex.

public:
	// Complex's constructor without initial value.
	Complex();

	// Complex's constructor with real part and imaginary part passed in.
	Complex(const double& re, const double& im);

	// Complex's constructor with only real part passed in.
	Complex(const double& x);

	// Complex's copy constructor.
	Complex(const Complex& x);

	// Reload Complex's operator "="
	// Make it possible to clone a Complex to another just use "=".
	Complex& operator =(const Complex& x);

	// Reload Complex's operator "="
	// Make it possible to assign value from double to Complex.
	Complex& operator =(const double& k);

	// Make it possible to get opposite number of Complex by using "-X".
	Complex operator -()const;

	// To judge if a Complex is zero or not.
	bool isZero()const;

	// Return the real part of a Complex.
	double  Re()const;

	// Return the imaginary part of a Complex.
	double  Im()const;

	// Calculate the module of current Complex.
	double  module()const;

	// Calculate the argumet of current Complex.
	double  arg()const;

	// Calculate the conjugation of current Complex.
	Complex conj()const;

	// Construct operations between complex and complex, complex and real.
	friend bool operator ==(const Complex& x, const Complex& y);
	friend bool operator !=(const Complex& x, const Complex& y);
	friend Complex operator +(const Complex& x, const Complex& y);
	friend Complex operator +(const double&  k, const Complex& x);
	friend Complex operator +(const Complex& x, const double&  k);
	friend Complex operator -(const Complex& x, const Complex& y);
	friend Complex operator -(const double&  k, const Complex& x);
	friend Complex operator -(const Complex& x, const double&  k);
	friend Complex operator *(const Complex& x, const Complex& y);
	friend Complex operator *(const double&  k, const Complex& x);
	friend Complex operator *(const Complex& x, const double&  k);
	friend Complex operator /(const Complex& x, const Complex& y);
	friend Complex operator /(const double&  k, const Complex& x);
	friend Complex operator /(const Complex& x, const double&  k);
	friend Complex operator ^(const Complex& x, const double&  n);
	friend Complex operator ^(const double&  a, const Complex& z);
};

// Calculate the Complex x powers of n.
Complex pow(const Complex& x, const double& n);

// Calculate exp(x) when x is a Complex number.
Complex exp(const Complex& x);

// To judge if a double number is zero or not.
bool isZero(const double& x);

#endif
