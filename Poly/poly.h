// Copyright(c): 2017 Bing-Hui WANG
//
// Author: Bing-Hui WANG
//
// Date: 2017-10-3
//
// Description: This code has build a Polynomial class named "Poly"
//				and implement almost all operation of Polynomials.
//
// Example:
//	 Poly P;
//	 cin >> P;
//	 // Get a polynomial from the screen.
//	 // Just using writing format. For example just input "-X^5 + 2*X - 3.64*X^3".
//
//	 vector<Complex> Roots = P.roots(); // Calculate all complex roots of current polynomial.
//
// See usage details in "./README.md"
// See more examples in "./examples/"

#ifndef POLY_H
#define POLY_H

#include <sortlink.h>
#include <matrix.h>

using namespace std;

// Define a class "Term" to store a term of polynomial.
class Term
{
public:
	double coef;	// Store the coefficient of a polynomial term.
	int exp;		// Store the exponent of a polynomial term.

public:
	// Term's constructor without initial value.
	Term();

	// Term's constructor with initial value.
	Term(double Coef, int Exp);

	// Construct an order structure in this class.
	friend bool operator  >(const Term& term1, const Term& term2);
	friend bool operator  <(const Term& term1, const Term& term2);
	friend bool operator ==(const Term& term1, const Term& term2);
	friend bool operator !=(const Term& term1, const Term& term2);
	friend bool operator >=(const Term& term1, const Term& term2);
	friend bool operator <=(const Term& term1, const Term& term2);
};

// Define the polynomial class "Poly"
class Poly
{
	// Define the cout format of a polinomial
	friend ostream & operator <<(ostream& o, const Poly& P);

	// Define the cin method of a polinomial
	friend istream & operator >>(istream& i, Poly& P);

private:
	SortLink<Term> term_array;
	// To store the polynomial in a sorted link list.
	// Why not just use a C style array to store it?
	// Just think about how to store "X^100 + 1".
	// If you use a normal array [1 0 0 ... 0 1], you have to store 99 zero. It is too space wasted.
	// But if you choose to store it with sorted link list, you just need to store 2 term: Term(1,100) and Term(1,0)

public:
	// Poly's constructor without initial value.
	Poly();

	// Poly's copy constructor.
	Poly(const Poly& P);

	// Poly's constructor with initial value a double or int number.
	// So just creat a polymonial which has only a normal term.
	Poly(const double& x);
	Poly(const int& x);

	// Poly's constructor with initial value a C++ style string or a C style string.
	// Convert the string into polynomial.
	Poly(const string& P_str);
	Poly(const char* P_cstr);

	// Poly's destructor
	~Poly();

	//-------------------------------------------------------------------------------

	// Function: void Poly::clear();
	//
    // Description: Clear Poly's memory.
    //
    // Input Parameter: Nothing
    //
    // Output Parameter: Nothing
    //
    // Return: void.
	Poly clear();

	//-------------------------------------------------------------------------------

	// Function: void Poly::newTerm(const double&, const int&);
	//
    // Description: Add a new term to current polynomial.
    //
    // Input Parameter: const double& Coef:	New term's coefficient
    //					const int& Exp: New term's exponent
    //
    // Output Parameter: Nothing
    //
    // Return: void.
	void newTerm(const double& Coef, const int& Exp);

	//-------------------------------------------------------------------------------

	// Function: Poly Poly::read(const string&);
	//
    // Description: Creat a polynomial from the string.
    //
    // Input Parameter: const string& P_str: The string wating to be converted into polynomial.
    //
    // Output Parameter: Nothing
    //
    // Return: A polynomial converted from string in type "Poly".
	Poly read(const string& P_str);

	//-------------------------------------------------------------------------------

	// Function: int Poly::deg()const;
	//
    // Description: Return the degree of current polynomial.
    //
    // Input Parameter: Nothing
    //
    // Output Parameter: Nothing
    //
    // Return: The degree of current polynomial in type "int".
	int  deg()const;

	//-------------------------------------------------------------------------------

	// Function: double Poly::main_coef()const;
	//
    // Description: Return the main coefficient(the coefficient of highest-dgree term) of current polynomial.
    //
    // Input Parameter: Nothing
    //
    // Output Parameter: Nothing
    //
    // Return: The main coefficient of current polynomial in type double. 
	double main_coef()const;

	//-------------------------------------------------------------------------------

	// Function: double Poly::coef(const int&)const;
	//
    // Description: Return the coefficient of k times exponent term of current polynomial.
    //
    // Input Parameter: Nothing
    //
    // Output Parameter: Nothing
    //
    // Return: The coefficient of k times exponent term of current polynomial in type "double".
	double coef(const int& k)const;

	//-------------------------------------------------------------------------------

	// Function: Complex Poly::eval(const Complex&)const;
	//
    // Description: Calculate the value of current Poly at observing point x.
    //
    // Input Parameter: const Complex& x: The observing point.
    //
    // Output Parameter: Nothing
    //
    // Return: The value of current Poly at observing point x in type "Complex"
    //
    // Others: It use the well known Qin Jiushao algorithm.
	Complex eval(const Complex& x)const;

	//-------------------------------------------------------------------------------

	// Function: double Poly::eval(const double&)const;
	//
    // Description: Calculate the value of current Poly at observing point x.
    //
    // Input Parameter: const double& x: The observing point.
    //
    // Output Parameter: Nothing
    //
    // Return: The value of current Poly at observing point x in type "double"
    //
    // Others: It use the well known Qin Jiushao algorithm.
	double eval(const double& x)const;

	//-------------------------------------------------------------------------------

	// Function: Poly Poly::com(const Poly&)const;
	//
    // Description: Calculate the composite Poly from 2 Poly.( P1(P2(X)) ).
    //
    // Input Parameter: const Poly& P: Polynomial which is wated to be composited.
    //
    // Output Parameter: Nothing
    //
    // Return: The composite polynomial in type "Poly".
	Poly com(const Poly& P)const;

	//-------------------------------------------------------------------------------

	// Function: Poly Poly::diff()const;
	//
    // Description: Calculate the differential polynomial of current polynomial.
    //
    // Input Parameter: Nothing.
    //
    // Output Parameter: Nothing
    //
    // Return: The differential polynomial in type "Poly";
	Poly diff()const;

	//-------------------------------------------------------------------------------

	// Function: Poly Poly::integral()const;
	//
    // Description: Calculate the primitive polynomial of current polynomial.
    //
    // Input Parameter: Nothing.
    //
    // Output Parameter: Nothing
    //
    // Return: The primitive polynomial in type "Poly";
	Poly integral()const;

	//-------------------------------------------------------------------------------

	// Function: Poly Poly::integral(const double&, const double&)const;
	//
    // Description: Calculate the integral of current polynomial in interval [a, b].
    //
    // Input Parameter: 1. const double& a: The lower limit of integral.
    //					2. const double& b: The upper limit of integral.
    //
    // Output Parameter: Nothing
    //
    // Return: The result of integral in type "double".
	double integral(const double& a, const double& b)const;

	//-------------------------------------------------------------------------------

	// Function: double Poly::search_zero_point(const double&, const double&, const double&)const;
	//
    // Description: search out a zero point of current polynomial in interval [a, b] ( only when P(a)*P(b) < 0 ).
    //
    // Input Parameter: 1. const double& a: The lower limit of integral.
    //					2. const double& b: The upper limit of integral.
    //
    // Output Parameter: Nothing
    //
    // Return: The zero point in interval [a, b] intype "double".
    //
    // Others: It used the dichotomy method.
	double search_zero_point(const double& a, const double& b, const double& epsilon=1E-6)const;

	//-------------------------------------------------------------------------------

	// Function: vector<Complex> Poly::roots()const;
	//
    // Description: Used to find out all roots of current polynomial.
    //
    // Input Parameter: Nothing.
    //
    // Output Parameter: Nothing
    //
    // Return: All roots of currents polynomial in type "Complex".
    //
    // Others: Firstly, generate the companion matrix C of current polynomial.
    //		   So C's all eigenvalues will be polynomial's all roots.
    //		   Then using QR method to calculate all eigenvalues of matrix C.
	vector<Complex> roots()const;

	//-------------------------------------------------------------------------------

	// Construct most operations between Poly and Poly, Poly and double.
	friend bool operator ==(const Poly& P1, const Poly& P2);
	friend bool operator !=(const Poly& P1, const Poly& P2);

	friend Poly operator  +(const Poly& P1 , const Poly& P2);
	friend Poly operator  +(const Poly& P1 , const double& x);
	friend Poly operator  +(const double& x, const Poly& P2);

	friend Poly operator  -(const Poly& P1 , const Poly& P2);
	friend Poly operator  -(const Poly& P1 , const double& x);
	friend Poly operator  -(const double& x, const Poly& P2);

	friend Poly operator  *(const Poly& P1 , const Poly& P2);
	friend Poly operator  *(const Poly& P1 , const double& k);
	friend Poly operator  *(const double& k, const Poly& P2);

	friend Poly operator  /(const Poly& P1, const Poly& P2);
	friend Poly operator  /(const Poly& P1, const double& k);
	friend Poly operator  /(const double& k, const Poly& P2);

	friend Poly operator  %(const Poly& P1 , const Poly& P2);
	friend Poly operator  %(const Poly& P1 , const double& k);
	friend Poly operator  %(const double& k, const Poly& P2);

	Poly& operator  =(const Poly& P);
	Poly& operator  =(const double& x);
	Poly& operator  =(const string& P_str);
	Poly  operator  -()const;
	Poly  operator +=(const Poly& P);
	Poly  operator +=(const double& x);
	Poly  operator -=(const Poly& P);
	Poly  operator -=(const double& x);
	Poly  operator *=(const Poly& P);
	Poly  operator *=(const double& x);
	Poly  operator /=(const Poly& P);
	Poly  operator /=(const double& x);
	Poly  operator %=(const Poly& P);
	Poly  operator %=(const double& x);
};

//-------------------------------------------------------------------------------

// Function: Poly unite(const int& k);
//
// Description: Generate a single term polynomial. For example unite(3) returns a polynomial of "X^3".
//
// Input Parameter: const int& k: The exponent of target single term.
//
// Output Parameter: Nothing
//
// Return: A single term polynomial with coefficient = 1 and exponent = k in type "Poly".
Poly unite(const int& k);

//-------------------------------------------------------------------------------

// Function: Poly gcd(const Poly& P1, const Poly& P2);
//
// Description: Calculate the greatest common divisor polynomial(gcd) of Poly P1 and Poly P2.
//
// Input Parameter: const Poly& P1:	The first polynomial waited to find gcd.
//					const Poly& P2: The second polynomial waited to find gcd.
//
// Output Parameter: Nothing
//
// Return: The greatest common divisor polynomial of Poly P1 and Poly P2 in type "Poly".
Poly gcd(const Poly& P1, const Poly& P2);

//-------------------------------------------------------------------------------

// Function: Poly gcd(const Poly& P1, const Poly& P2);
//
// Description: Calculate the least common multiple polynomial(lcm) of Poly P1 and Poly P2.
//
// Input Parameter: const Poly& P1:	The first polynomial waited to find lcm.
//					const Poly& P2: The second polynomial waited to find lcm.
//
// Output Parameter: Nothing
//
// Return: The least common multiple polynomial of Poly P1 and Poly P2 in type "Poly".
Poly lcm(const Poly& P1, const Poly& P2);

//-------------------------------------------------------------------------------

// To calculate n times Square of Poly P.
Poly pow(const Poly& P,  const int& n);

// generate Legendre polynomial.
Poly Legendre(const int& n);

// generate Hermite polynomial.
Poly Hermite(const int& n);

// generate Laguerre polynomial.
Poly Laguerre(const int& n);

// generate scaled Laguerre polynomial.
Poly Laguerre_scaled(const int& n);

// generate Chebyshev polynomial.
Poly Chebyshev(const int& n);

#endif