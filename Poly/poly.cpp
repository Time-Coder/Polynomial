// Copyright(c): 2017 Bing-Hui WANG
//
// Author: Bing-Hui WANG
//
// Date: 2017-10-3
//
// Description: This file the implementation of interface "./poly.h"

#include <poly.h>

// Term's constructor without initial value.
Term::Term()
{
	coef = 0;
	exp  = 0;
}

// Term's constructor with initial value.
Term::Term(double Coef, int Exp)
{
	coef = Coef;
	exp  = Exp;
}

// Construct an order structure in class "Term".
bool operator >(const Term& term1, const Term& term2)
{
	return (term1.exp > term2.exp);
}
bool operator <(const Term& term1, const Term& term2)
{
	return (term1.exp < term2.exp);
}
bool operator ==(const Term& term1, const Term& term2)
{
	return (term1.exp == term2.exp);
}
bool operator !=(const Term& term1, const Term& term2)
{
	return (term1.exp != term2.exp);
}
bool operator >=(const Term& term1, const Term& term2)
{
	return (term1.exp >= term2.exp);
}
bool operator <=(const Term& term1, const Term& term2)
{
	return (term1.exp <= term2.exp);
}

// Define the cout format of Poly
ostream & operator <<(ostream & o, const Poly & P)  
{
	if( P.main_coef() == 0 )
    {
    	o << "0";
    }
    else
    {
	    SortLink<Term>::const_iterator it = (P.term_array).begin();
	    if( (*it).coef > 0 &&  (*it).coef != 1 )
		{
			if( (*it).exp >= 2 )
			{
				o << (*it).coef << "*X^" << (*it).exp;
			}
			else if( (*it).exp == 1 )
			{
				o << (*it).coef << "*X";
			}
			else if( (*it).exp == 0 )
			{
				o << (*it).coef;
			}
		}
		else if( (*it).coef == 1 )
		{
			if( (*it).exp >= 2 )
			{
				o << "X^" << (*it).exp;
			}
			else if( (*it).exp == 1 )
			{
				o << "X";
			}
			else if( (*it).exp == 0 )
			{
				o << 1;
			}
		}
		else if( (*it).coef < 0 && (*it).coef != -1 )
		{
			if( (*it).exp >= 2 )
			{
				o << " - " << -(*it).coef << "*X^" << (*it).exp;
			}
			else if( (*it).exp == 1 )
			{
				o << " - " << -(*it).coef << "*X";
			}
			else if( (*it).exp == 0 )
			{
				o << " - " << -(*it).coef;
			}
		}
		else if( (*it).coef == -1 )
		{
			if( (*it).exp >= 2 )
			{
				o << " - " << "X^" << (*it).exp;
			}
			else if( (*it).exp == 1 )
			{
				o << " - " << "X";
			}
			else if( (*it).exp == 0 )
			{
				o << " - " << 1;
			}
		}
		it++;
	    for(; it != (P.term_array).end(); it++)
	    {
	    	if( (*it).coef > 0 &&  (*it).coef != 1 )
	    	{
	    		if( (*it).exp >= 2 )
	    		{
	    			o << " + " << (*it).coef << "*X^" << (*it).exp;
	    		}
	    		else if( (*it).exp == 1 )
	    		{
	    			o << " + " << (*it).coef << "*X";
	    		}
	    		else if( (*it).exp == 0 )
	    		{
	    			o << " + " << (*it).coef;
	    		}
	    	}
	    	else if( (*it).coef == 1 )
	    	{
	    		if( (*it).exp >= 2 )
	    		{
	    			o << " + " << "X^" << (*it).exp;
	    		}
	    		else if( (*it).exp == 1 )
	    		{
	    			o << " + " << "X";
	    		}
	    		else if( (*it).exp == 0 )
	    		{
	    			o << " + " << 1;
	    		}
	    	}
	    	else if( (*it).coef < 0 && (*it).coef != -1 )
	    	{
	    		if( (*it).exp >= 2 )
	    		{
	    			o << " - " << -(*it).coef << "*X^" << (*it).exp;
	    		}
	    		else if( (*it).exp == 1 )
	    		{
	    			o << " - " << -(*it).coef << "*X";
	    		}
	    		else if( (*it).exp == 0 )
	    		{
	    			o << " - " << -(*it).coef;
	    		}
	    	}
	    	else if( (*it).coef == -1 )
	    	{
	    		if( (*it).exp >= 2 )
	    		{
	    			o << " - " << "X^" << (*it).exp;
	    		}
	    		else if( (*it).exp == 1 )
	    		{
	    			o << " - " << "X";
	    		}
	    		else if( (*it).exp == 0 )
	    		{
	    			o << " - " << 1;
	    		}
	    	}
	    }
	}
    
    return o;  
}

// Define the cin method of Poly
istream& operator >>(istream& i, Poly& P)
{
	string str;
	getline(cin, str);
	P = str;
	return i;
}

// Function: Poly::Poly();
//
// Description: Poly's constructor without initial value.
//
// Calls: SortLink<DataType>::insert(const DataType&);
//		  // Declared and defined in "../SortLink/sortlink.h".
//
// Input Parameter: Nothing
//
// Output Parameter: Nothing
//
// Return: void.
Poly::Poly()
{
	term_array.insert(Term(0, 0));
}

// Function: Poly::Poly(const Poly&);
//
// Description: Poly's copy constructor.
//
// Calls: SortLink<DataType>& SortLink<DataType>::operator =(const SfortLink<DataType>&);
//		  // Declared and defined in "../SortLink/sortlink.h".
//
// Input Parameter: Nothing
//
// Output Parameter: Nothing
//
// Return: void.
Poly::Poly(const Poly& P)
{
	term_array = P.term_array;
}

// Function: Poly::Poly(const double&);
//
// Description: Poly's constructor with initial value a double number.
// 				So just creat a polymonial which has only a normal term.
//
// Calls: SortLink<DataType>::insert(const DataType&);
//		  // Declared and defined in "../SortLink/sortlink.h".
//
// Input Parameter: Nothing
//
// Output Parameter: Nothing
//
// Return: void.
Poly::Poly(const double& x)
{
	term_array.insert(Term(x, 0));
}

// Function: Poly::Poly(const double&);
//
// Description: Poly's constructor with initial value a int number.
// 				So just creat a polymonial which has only a normal term.
//
// Calls: SortLink<DataType>::insert(const DataType&);
//		  // Declared and defined in "../SortLink/sortlink.h".
//
// Input Parameter: Nothing
//
// Output Parameter: Nothing
//
// Return: void.
Poly::Poly(const int& x)
{
	term_array.insert(Term((double)x, 0));
}

// Function: Poly::Poly(const double&);
//
// Description: Poly's constructor with initial value a C++ style string
// 				Convert the string into polynomial.
//
// Calls: Poly Poly::read(const string&);
//		  // Declared in "./poly.h"
//		  // Defined  in "./poly.cpp"
//
// Input Parameter: Nothing
//
// Output Parameter: Nothing
//
// Return: void.
Poly::Poly(const string& P_str)
{
	read(P_str);
}

// Function: Poly::Poly(const double&);
//
// Description: Poly's constructor with initial value a C style string
// 				Convert the string into polynomial.
//
// Calls: Poly Poly::read(const string&);
//		  // Declared in "./poly.h"
//		  // Defined  in "./poly.cpp"
//
// Input Parameter: Nothing
//
// Output Parameter: Nothing
//
// Return: void.
Poly::Poly(const char* P_cstr)
{
	string P_str(P_cstr);
	read(P_str);
}

// Function: Poly::~Poly();
//
// Description: Poly's destructor.
//
// Calls: void SortLink<DataType>::clear();
//		  void SortLink<DataType>::insert(const DataType&);
//		  // Declared and defined in "../SortLink/sortlink.h"
//
// Input Parameter: Nothing
//
// Output Parameter: Nothing
//
// Return: void.
Poly::~Poly()
{
	term_array.clear();
	term_array.insert(Term(0., 0));
}

// Function: void Poly::clear();
//
// Description: Clear Poly's memory.
//
// Calls: void SortLink<DataType>::clear();
//		  void SortLink<DataType>::insert(const DataType&);
//		  // Declared and defined in "../SortLink/sortlink.h"
//
// Input Parameter: Nothing
//
// Output Parameter: Nothing
//
// Return: void.
Poly Poly::clear()
{
	term_array.clear();
	term_array.insert(Term(0., 0));
	return *this;
}

// Function: void newTerm(const double&, const int&);
//
// Description: Add a new term to current polynomial.
//
// Calls: SortLink<DataType>::const_itrator SortLink<DataType>::find(const DataType&)const;
//		  void SortLink<DataType>::insert(const DataType&);
//		  void SortLink<DataType>::erase(const const_iterator& it);
//		  SortLinkIterator<DataType>::SortLinkIterator();
//		  // Declared and defined in "../SortLink/sortlink.h".
//
// Input Parameter: const double& Coef:	New term's coefficient
//					const int& Exp: New term's exponent
//
// Output Parameter: Nothing
//
// Return: void.
void Poly::newTerm(const double& Coef, const int& Exp)
{
	if(Coef != 0)
	{
		Term new_term;
		new_term.coef = Coef;
		new_term.exp  = Exp;
		SortLink<Term>::const_iterator it = term_array.find(new_term);

		if(it.empty())
		{
			term_array.insert(new_term);
		}
		else
		{
			LinkNode<Term>* p = it._ptr;
			(p->data).coef += Coef;
			if( (p->data).coef == 0 )
			{
				term_array.erase(it);
			}
		}
	}
}

// Function: int Poly::deg()const;
//
// Description: Return the degree of current polynomial.
//
// Input Parameter: Nothing
//
// Output Parameter: Nothing
//
// Return: The degree of current polynomial in type "int".
int Poly::deg()const
{
	SortLink<Term>::const_iterator it = term_array.begin();
	return (*it).exp;
}

// Function: double Poly::main_coef()const;
//
// Description: Return the main coefficient(the coefficient of highest-dgree term) of current polynomial.
//
// Input Parameter: Nothing
//
// Output Parameter: Nothing
//
// Return: The main coefficient of current polynomial in type double. 
double Poly::main_coef()const
{
	SortLink<Term>::const_iterator it = term_array.begin();
	return (*it).coef;
}

// Function: double Poly::coef(const int&)const;
//
// Description: Return the coefficient of k times exponent term of current polynomial.
//
// Input Parameter: Nothing
//
// Output Parameter: Nothing
//
// Return: The coefficient of k times exponent term of current polynomial in type "double".
double Poly::coef(const int& k)const
{
	Term U(1, k);

	SortLink<Term>::const_iterator it = term_array.find(U);
	if( it.empty() )
	{
		return 0;
	}
	else
	{
		return (*it).coef;
	}
}

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
Complex Poly::eval(const Complex& x)const
{
	int n = deg();
	if(n == 0)
	{
		return coef(0);
	}

	Complex Result = coef(n)*x + coef(n-1);
	
	for(int k = n-2; k >= 0; k--)
	{
		Result = Result * x + coef(k);
	}

	return Result;
}

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
double Poly::eval(const double& x)const
{
	int n = deg();
	if(n == 0)
	{
		return coef(0);
	}

	double Result = coef(n)*x + coef(n-1);
	
	for(int k = n-2; k >= 0; k--)
	{
		Result = Result * x + coef(k);
	}

	return Result;
}

// Function: Poly Poly::com(const Poly&)const;
//
// Description: Calculate the composite Poly from 2 Poly.( P1(P2(X)) ).
//
// Input Parameter: const Poly& P: Polynomial which is wated to be composited.
//
// Output Parameter: Nothing
//
// Return: The composite polynomial in type "Poly".
Poly Poly::com(const Poly& P)const
{
	Poly Q;

	for(SortLink<Term>::const_iterator it = term_array.begin(); it != term_array.end(); it++)
	{
		Q += (*it).coef * pow(P, (*it).exp);
	}

	return Q;
}

// Construct most operations between Poly and Poly, Poly and double.
Poly& Poly::operator =(const Poly& P)
{
	term_array = P.term_array;
	return *this;
}

Poly& Poly::operator =(const double& x)
{
	*this = Poly(x);
	return *this;
}

Poly& Poly::operator =(const string& P_str)
{
	*this = Poly(P_str);
	return *this;
}

Poly Poly::operator -()const
{
	Poly Result = *this;

	for(SortLink<Term>::const_iterator it = (Result.term_array).begin(); it != (Result.term_array).end(); it++)
	{
		LinkNode<Term>* p = it._ptr;
		(p->data).coef = -(p->data).coef;
	}

	return Result;
}

Poly Poly::operator +=(const Poly& P)
{
	*this = *this + P;
	return *this;
}

Poly Poly::operator +=(const double& x)
{
	*this = *this + x;
	return *this;
}

Poly Poly::operator -=(const Poly& P)
{
	*this = *this - P;
	return *this;
}

Poly Poly::operator -=(const double& x)
{
	*this = *this - x;
	return *this;
}

Poly Poly::operator *=(const Poly& P)
{
	*this = *this * P;
	return *this;
}

Poly Poly::operator *=(const double& x)
{
	*this = *this * x;
	return *this;
}

Poly Poly::operator /=(const Poly& P)
{
	*this = *this / P;
	return *this;
}

Poly Poly::operator /=(const double& x)
{
	*this = *this / x;
	return *this;
}

Poly Poly::operator %=(const Poly& P)
{
	*this = *this % P;
	return *this;
}

Poly Poly::operator %=(const double& x)
{
	*this = *this % x;
	return *this;
}

bool operator ==(const Poly& P1, const Poly& P2)
{
	if( (P1.term_array).length() != (P2.term_array).length() )
	{
		return false;
	}

	SortLink<Term>::const_iterator it1 = (P1.term_array).begin();
	SortLink<Term>::const_iterator it2 = (P2.term_array).begin();
	for(; it1 != (P1.term_array).end(); it1++)
	{
		if( (*it1).exp != (*it2).exp || (*it1).coef != (*it2).coef )
		{
			return false;
		}
		it2++;
	}
	return true;
}

bool operator !=(const Poly& P1, const Poly& P2)
{
	return !(P1 == P2);
}

Poly operator +(const Poly& P1, const Poly& P2)
{
	Poly P_result;
	SortLink<Term>::const_iterator it1 = (P1.term_array).begin();
	SortLink<Term>::const_iterator it2 = (P2.term_array).begin();
	double Coef;
	int Exp;
	while( it1 != (P1.term_array).end() && it2 != (P2.term_array).end() )
	{
		if( (*it1).exp > (*it2).exp )
		{
			Coef = (*it1).coef;
			Exp  = (*it1).exp;
			P_result.newTerm(Coef, Exp);
			it1++;
		}
		else if( (*it1).exp < (*it2).exp )
		{
			(P_result.term_array).insert(*it2);
			it2++;
		}
		else
		{
			Coef = (*it1).coef + (*it2).coef;
			Exp  = (*it1).exp;
			P_result.newTerm(Coef, Exp);
			it1++;
			it2++;
		}
	}

	if( it1 == (P1.term_array).end() && it2 != (P2.term_array).end() )
	{
		while( it2 != (P2.term_array).end() )
		{
			Coef = (*it2).coef;
			Exp  = (*it2).exp;
			P_result.newTerm(Coef, Exp);
			it2++;
		}
	}
	else if( it1 != (P1.term_array).end() && it2 == (P2.term_array).end() )
	{
		while( it1 != (P1.term_array).end() )
		{
			Coef = (*it1).coef;
			Exp  = (*it1).exp;
			P_result.newTerm(Coef, Exp);
			it1++;
		}
	}

	return P_result;
}

Poly operator +(const Poly& P1, const double& x)
{
	Poly P_result = P1;
	P_result.newTerm(x, 0);
	return P_result;
}

Poly operator +(const double& x, const Poly& P2)
{
	return P2 + x;
}

Poly operator -(const Poly& P1, const Poly& P2)
{
	return P1 + (-P2);
}

Poly operator -(const Poly& P1, const double& x)
{
	return P1 + (-x);
}

Poly operator -(const double& x, const Poly& P2)
{
	return -P2 + x;
}

Poly operator *(const Poly& P1, const Poly& P2)
{
	Poly P_result;

	double Coef;
	int Exp;

	for(SortLink<Term>::const_iterator it1 = (P1.term_array).begin(); it1 != (P1.term_array).end(); it1++)
	{
		for(SortLink<Term>::const_iterator it2 = (P2.term_array).begin(); it2 != (P2.term_array).end(); it2++)
		{
			Coef = (*it1).coef * (*it2).coef;
			Exp  = (*it1).exp  + (*it2).exp;
			P_result.newTerm(Coef, Exp);
		}
	}
	return P_result;
}

Poly operator *(const double& k, const Poly& P2)
{
	return Poly(k) * P2;
}

Poly operator *(const Poly& P1, const double& k)
{
	return k * P1;
}

Poly operator /(const Poly& P1, const Poly& P2)
{
	if( P2.main_coef() == 0 )
	{
		cout << "[ Error in P1 / P2 : " << endl
			 << "  P2 = 0 is not permitted! ]" << endl;
		exit(-1);
	}
	else if( P1.deg() < P2.deg() )
	{
		return Poly(0.);
	}

	Poly Q, R;
	R = P1;
	while(R.deg() >= P2.deg() && R.main_coef() != 0)
	{
		Poly new_term = R.main_coef() / P2.main_coef() * unite( R.deg() - P2.deg() );
		Q += new_term;
		R -= new_term * P2;
	}
	return Q;
}

Poly operator /(const Poly& P1, const double& k)
{
	if( k == 0 )
	{
		cout << "[ Error in P1 / k :"<< endl
			 << "  k = 0 is not permitted! ]" << endl;
		exit(-1);
	}

	return 1/k * P1;
}

Poly operator /(const double& k, const Poly& P2)
{
	return Poly(0.);
}

Poly operator %(const Poly& P1, const Poly& P2)
{
	if( P2.main_coef() == 0 )
	{
		cout << "[ Error in P1 % P2 : " << endl
			 << "  P2 = 0 is not permitted! ]" << endl;
		exit(-1);
	}
	else if( P1.deg() < P2.deg() )
	{
		return P1;
	}

	Poly Q, R;
	R = P1;
	while(R.deg() >= P2.deg() && R.main_coef() != 0)
	{
		Poly new_term = R.main_coef() / P2.main_coef() * unite( R.deg() - P2.deg() );
		Q = Q + new_term;
		R = R - new_term * P2;
	}
	return R;
}

Poly operator %(const Poly& P1, const double& k)
{
	return Poly(0.);
}

Poly operator %(const double& k, const Poly& P2)
{
	return Poly(k);
}

// Function: vector<Complex> Poly::roots()const;
//
// Description: Used to find out all roots of current polynomial.
//
// Calls: double Poly::main_coef()const;
//		  int Poly::deg()const;
//		  double Poly::coef(const int&);
//		  // Declared in "./poly.h".
//		  // Defined  in current file.
//
//		  Complex::Complex(const double&);
//		  pow(const Complex&, const int&);
//		  // Declared in "../Complex/complex.h".
//		  // Defined  in "../Complex/complex.cpp".
//
//		  Matrix::Matrix(const int&, const int&);
//	      vector<Complex> Matrix::eigenvalue()const;
//		  // Declared in "../Matrix/matrix.h".
//		  // Defined  in "../Matrix/matrix.cpp".
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
vector<Complex> Poly::roots()const
{
	vector<Complex> Roots;
	if( main_coef() == 0 )
	{
		cout << "There are infinite roots because P == 0." << endl;
	}
	else if( deg() == 0 )
	{
		cout << "There are no root because P(X) == cte != 0." << endl;
	}
	else if( deg() == 1 )
	{
		double a = coef(1);
		double b = coef(0);

		Complex x1 = - b / a;

		Roots.push_back(x1);
	}
	else if( deg() == 2 )
	{
		double a = coef(2);
		double b = coef(1);
		double c = coef(0);

		double delta = b * b - 4 * a * c ;

		
        Complex x1 = ( -b + pow(Complex(delta), 0.5) ) / (2 * a);
        Complex x2 = ( -b - pow(Complex(delta), 0.5) ) / (2 * a);

		Roots.push_back(x1);
		Roots.push_back(x2);
	}
	else if( deg() == 3 )
	{
		double a = coef(3);
		double b = coef(2);
		double c = coef(1);
		double d = coef(0);

		double p = (  c - pow(b, 2)  / (3 * a) ) / a;
		double q = ( b / (3 * a) * ( (2 * pow(b, 2)) / (9 * a) - c ) + d )/a;

		double delta = pow( (q/2), 2 ) + pow( (p/3), 3 );

		Complex j(-0.5, sqrt(3) / 2);
		Complex j2(-0.5, -sqrt(3) / 2);
		
        Complex Y1 = - q / 2 + pow(Complex(delta), 0.5);
        Complex Y2 = - q / 2 - pow(Complex(delta), 0.5);
		Complex E1 = pow(Y1, 1./3);
		Complex E2 = pow(Y2, 1./3);

		Complex X1 = E1 + E2;
		Complex X2 = j * E1 + j2 * E2;
		Complex X3 = j2 * E1 + j * E2;

		double D = b / (3 * a);
		Complex x1 = X1 - D;
		Complex x2 = X2 - D;
		Complex x3 = X3 - D;

		Roots.push_back(x1);
		Roots.push_back(x2);
		Roots.push_back(x3);
	}
	else
	{
		int n = deg();
		double an = main_coef();
		Matrix C(n, n);
		for(int i = 0; i < n-1; i++)
		{
			C.data[i][i+1] = 1;
		}
		for(int j = 0; j < n; j++)
		{
			C.data[n-1][j] = - coef(j) / an;
		}
		Roots = C.eigenvalue();
	}

	return Roots;
}

// Delete all space in a string.
// It changes the original string.
string delete_space(string& P_str)
{
	for(string::iterator it = P_str.begin(); it != P_str.end();)
	{
		if(*it == ' ')
		{
			P_str.erase(it);
		}
		else
		{
			it++;
		}
	}
	return P_str;
}

// To judge if a char is a number.
bool isnumber(const char& ch)
{
	return (ch >= '0' && ch <= '9');
}

// Print a error message on the screen and exit the program
// when the format of input polynomial string is wrong.
void read_error()
{
	cout << "Error for the input of your polinormial!" << endl;
	exit(-1);
}

// Function: string::iterator it_num_begin(string::iterator);
//
// Description: if the passed in iterator is point to a number,
//				move the iterator back and back until it reach to
//				the begin position of current whole number.
//
// Calls: bool isnumber(const char& ch);
//		  void read_error();
//		  // Defined in curent file.
//
// Input Parameter: string::iterator it:	a string iterator that you want to
//											move it to the begin of current number.
//
// Output Parameter: Nothing
//
// Return: The iterator after moving.
string::iterator it_num_begin(string::iterator it)
{
    if( !isnumber(*it) )
	{
		cout << "[ Error in \"string::iterator it_number_begin(string P_str, string::iterator it)\":" << endl
			 << "  *it must be a number! ]" << endl;
		exit(-1);
	}

    while( isnumber(*it) )
	{
		it--;
	}
	if(*it == '.')
	{
		it--;
        if( isnumber(*it) )
		{
            while( isnumber(*it) )
			{
				it--;
			}
		}
		else
		{
			read_error();
		}
	}
	it++;
	return it;
}

// Function: double num_from_end(const string&, string::iterator);
//
// Description: Passed in string iterator, the function will find out the whole number
//				before the iterator.
//
// Calls: string::iterator it_num_begin(string::iterator);
//		  // Defined in current file.
//
// Input Parameter: const string& P_str:	A string that may represents a polynomial.
//					string::iterator it:	string iterator points to a number in P_str.
//
// Output Parameter: Nothing
//
// Return: The whole number before the iterator in type "double".
double num_from_end(const string& P_str, string::iterator it)
{
	double number;
	string::iterator it_begin = it_num_begin(it);
	string number_str = P_str.substr( it_begin - P_str.begin(), it - P_str.begin() + 1 );
	stringstream ss;
	ss << number_str;
	ss >> number;
	return number;
}

// Function: double coef_befor_X(const string&, string::iterator)
//
// Description: Get the coefficient before char 'X' of a string.
//
// Calls: bool isnumber(const char&);
//		  double number_from_end(const string&, string::iterator);
//		  void read_error();
//		  // Defined in current file.
//
// Input Parameter: const string& P_str:	A string that may represents a polynomial.
//					string::iterator it:	string iterator points to char 'X'
//
// Output Parameter: Nothing
//
// Return: The coefficient before char 'X' of a string in type "double".
double coef_befor_X(const string& P_str, string::iterator it_X)
{
	double Coef;

	string::iterator it = it_X;
	if(*it != 'X')
	{
		cout << "[ Error in \"double deal_befor_X(string P_str, string::iterator it_X)\":" << endl
			 << "  *it_X must be 'X'! ]" << endl;
		exit(-1);
	}

	it--;
	if(*it == '*')
	{
		it--;
        if(isnumber(*it))
		{
			Coef = num_from_end(P_str, it);
		}
		else
		{
			read_error();
		}
	}
	else if(*it == '+')
	{
		Coef = 1;
	}
	else if(*it == '-')
	{
		Coef = -1;
	}
	else if(*it == '\0')
	{
		Coef = 1;
	}
	else
	{
		read_error();
	}

	return Coef;
}

// Function: Term term_before_plus(const string&, string::iterator)
//
// Description: Get the whole polynomial term before '+' or '-'.
//
// Calls: bool isnumber(const char&);
//		  double number_from_end(const string&, string::iterator);
//		  string::iterator it_num_begin(string::iterator);
//		  double coef_befor_X(const string&, string::iterator);
//		  void read_error();
//		  // Defined in current file.
//
//		  Term::Term(const double&, const int&);
//		  // Declared in "./ploy.h";
//		  // Defined in current file.
//
// Input Parameter: const string& P_str:	A string that may represents a polynomial.
//					string::iterator it:	string iterator points to char '+' or '-'
//
// Output Parameter: Nothing
//
// Return: The whole polynomial term before '+' or '-' in type "Term".
Term term_before_plus(const string& P_str, string::iterator it_plus)
{

	double Coef;
	int Exp;

	string::iterator it = it_plus;
	if(*it != '+' && *it != '-')
	{
		cout << "[ Error in \"Term term_before_plus(string::it)\":" << endl
			 << "  *it must be '+' or '-' ! ]" << endl;
		exit(-1);
	}
	it--;
    if( isnumber(*it) )
	{
		double num = num_from_end(P_str, it);
		it = it_num_begin(it);
		it--;
		if(*it == '^')
		{
			Exp = (int)num;
			it--;
			if(*it == 'X')
			{
				Coef = coef_befor_X(P_str, it);
			}
			else
			{
				read_error();
			}
		}
		else if(*it == '+')
		{
			Exp = 0;
			Coef = num;
		}
		else if(*it == '-')
		{
			Exp = 0;
			Coef = -num;
		}
		else if(*it == '\0')
		{
			Exp = 0;
			Coef = num;
		}
		else
		{
			read_error();
		}
	}
	else if(*it == 'X')
	{
		Exp = 1;
		Coef = coef_befor_X(P_str, it);
	}
	else if(*it == '\0')
	{
		Coef = 0;
		Exp = 0;
	}

	return Term(Coef, Exp);
}

// Function: string::iterator it_num_end(string::iterator);
//
// Description: if the passed in iterator is point to a number,
//				move the iterator forward and forward until it reach to
//				the end position of current whole number.
//
// Calls: bool isnumber(const char& ch);
//		  void read_error();
//		  // Defined in curent file.
//
// Input Parameter: string::iterator it:	a string iterator that you want to
//											move it to the end of current number.
//
// Output Parameter: Nothing
//
// Return: The iterator after moving.
string::iterator it_num_end(string::iterator it)
{
	string::iterator it_end = it;
    if( !isnumber(*it_end) )
	{
        cout << "[ Error in \"string::iterator it_num_end(string::iterator it)\":" << endl
			 << "  *it must be a number! ]" << endl;
		exit(-1);
	}

    while( isnumber(*it_end) )
	{
		it_end++;
	}
	if(*it_end == '.')
	{
		it_end++;
        if( isnumber(*it_end) )
		{
            while( isnumber(*it_end) )
			{
				it_end++;
			}
		}
		else
		{
			read_error();
		}
	}
	it_end--;

	return it_end;
}

// Function: double num_from_begin(const string&, string::iterator)
//
// Description: Pass in string iterator, the function will find out the whole number
//				after the iterator.
//
// Calls: string::iterator it_num_end(string::iterator);
//		  // Defined in current file.
//
// Input Parameter: const string& P_str:	A string that may represents a polynomial.
//					string::iterator it:	string iterator points to a number in P_str.
//
// Output Parameter: Nothing
//
// Return: The whole number after the iterator in type "double".
double num_from_begin(const string& P_str, string::iterator it_begin)
{
	double number;

    string::iterator it_end = it_num_end(it_begin);
	string number_str = P_str.substr( it_begin - P_str.begin(), it_end - P_str.begin() );
	
	stringstream ss;
	ss << number_str;
	ss >> number;
	return number;
}

// Function: int exp_after_X(const string&, string::iterator)
//
// Description: Get the exponent after char 'X' of a string.
//
// Calls: bool isnumber(const char&);
//		  double number_from_begin(const string&, string::iterator);
//		  void read_error();
//		  // Defined in current file.
//
// Input Parameter: const string& P_str:	A string that may represents a polynomial.
//					string::iterator it:	string iterator points to char 'X'
//
// Output Parameter: Nothing
//
// Return: The exponent after char 'X' of a string in type "int".
int exp_after_X(const string& P_str, string::iterator it_X)
{
	int Exp;

	string::iterator it = it_X;
	if(*it != 'X')
	{
		cout << "[ Error in \"int exp_after_X(string P_str, string::iterator it_X)\":" << endl
			 << "  *it_X must be 'X' ! ]" << endl;
		exit(-1);
	}
	it++;
	if(*it == '^')
	{
		it++;
        if( isnumber(*it) )
		{
			Exp = (int)num_from_begin(P_str, it);
		}
		else
		{
			read_error();
		}
	}
	else if(*it == '+' || *it == '-' || *it == '\0')
	{
		Exp = 1;
	}
	else
	{
		read_error();
	}

	return Exp;
}

// Function: Term term_after_plus(const string&, string::iterator)
//
// Description: Get the whole polynomial term after '+' or '-'.
//
// Calls: bool isnumber(const char&);
//		  double number_from_begin(const string&, string::iterator);
//		  string::iterator it_num_end(string::iterator);
//		  double exp_after_X(const string&, string::iterator);
//		  void read_error();
//		  // Defined in current file.
//
//		  Term::Term(const double&, const int&);
//		  // Declared in "./ploy.h";
//		  // Defined in current file.
//
// Input Parameter: const string& P_str:	A string that may represents a polynomial.
//					string::iterator it:	string iterator points to char '+' or '-'
//
// Output Parameter: Nothing
//
// Return: The whole polynomial term after '+' or '-' in type "Term".
Term term_after_plus(const string& P_str, string::iterator it_plus)
{
	double Coef;
	int Exp;

	string::iterator it = it_plus;
	if(*it == '+')
	{
		it++;
        if( isnumber(*it) )
		{
			Coef = num_from_begin(P_str, it);
            it = it_num_end(it);
			it++;
			if(*it == '*')
			{
				it++;
				if(*it == 'X')
				{
					Exp = exp_after_X(P_str, it);
				}
				else
				{
					read_error();
				}
			}
			else if(*it == '+' || *it == '-')
			{
				Exp = 0;
			}
			else if(*it == '\0')
			{
				Exp = 0;
			}
			else
			{
				read_error();
			}
		}
		else if(*it == 'X')
		{
			Coef = 1;
			Exp = exp_after_X(P_str, it);
		}
		else
		{
			read_error();
		}
	}
	else if(*it == '-')
	{
		it++;
        if( isnumber(*it) )
		{
			Coef = -num_from_begin(P_str, it);
			
            it = it_num_end(it);
			it++;
			if(*it == '*')
			{
				it++;
				if(*it == 'X')
				{

					Exp = exp_after_X(P_str, it);

				}
				else
				{
					read_error();
				}
			}
			else if(*it == '+' || *it == '-')
			{
				Exp = 0;
			}
			else if(*it == '\0')
			{
				Exp = 0;
			}
			else
			{
				read_error();
			}
		}
		else if(*it == 'X')
		{
			Coef = -1;
			Exp = exp_after_X(P_str, it);
		}
		else
		{
			read_error();
		}
	}
	else
	{
		cout << "[ Error in \"Term term_after_plus(string P_str, string::iterator it_plus)\":" << endl
			 << "  *it_plus must be '+' or '-' ! ]" << endl;
		exit(-1);
	}

	return Term(Coef, Exp);
}

// Function: Poly Poly::read(const string&);
//
// Description: Creat a polynomial from the string.
//
// Calls: Poly::clear();
//		  string delete_space(string&);
//		  Term term_after_plus(const string&, string::iterator);
//		  Term term_before_plut(const string&, string::iterator);
//		  // Defined in current file.
//
//		  Poly::newTerm(const double&, const int&);
//		  // Decllared in "./poly.h"
//		  // Defined in current file.
//
// Input Parameter: const string& P_str: The string wating to be converted into polynomial.
//
// Output Parameter: Nothing
//
// Return: A polynomial converted from string in type "Poly".
Poly Poly::read(const string& P_str_init)
{
	clear();
	string P_str = P_str_init;
	delete_space(P_str);
	
	int n_plus = 0;
	for(string::iterator it = P_str.begin(); it != P_str.end(); it++)
	{
		if(*it == '+' || *it == '-')
		{
			n_plus++;
			if(n_plus == 1)
			{
				Term term1 = term_before_plus(P_str, it);
				Term term2 = term_after_plus(P_str, it);
				newTerm(term1.coef, term1.exp);
				newTerm(term2.coef, term2.exp);
			}
			else
			{
				Term term = term_after_plus(P_str, it);
				newTerm(term.coef, term.exp);
			}
		}
	}
	
	if(n_plus == 0)
	{
		P_str = "+" + P_str;
		read(P_str);
	}

    return *this;
}

// Function: Poly Poly::diff()const;
//
// Description: Calculate the differential polynomial of current polynomial.
//
// Calls: SortLink<DataType>::const_iterator SotLink<DataType>::begin()const;
//		  SortLink<DataType>::const_iterator SotLink<DataType>::end()const;
//		  void SortLink<DataType>::erase(SortLink<DataType>::const_iterator);
//		  // Declared in "./poly.h"
//		  // Defined in current file.
//
// Input Parameter: Nothing.
//
// Output Parameter: Nothing
//
// Return: The differential polynomial in type "Poly";
Poly Poly::diff()const
{
	Poly Result = *this;
	
	SortLink<Term>::const_iterator it = (Result.term_array).begin();
	for(; it != (Result.term_array).end(); it++)
	{
		LinkNode<Term>* p = it._ptr;
		(p->data).coef = (*it).coef * (*it).exp;
		(p->data).exp  = (*it).exp - 1;
		if( (p->data).coef == 0 )
		{
			(Result.term_array).erase(it);
		}
	}
	
	return Result;
}

// Function: Poly Poly::integral()const;
//
// Description: Calculate the primitive polynomial of current polynomial.
//
// Calls: SortLink<DataType>::const_iterator SotLink<DataType>::begin()const;
//		  SortLink<DataType>::const_iterator SotLink<DataType>::end()const;
//		  // Declared in "./poly.h"
//		  // Defined in current file.
//
// Input Parameter: Nothing.
//
// Output Parameter: Nothing
//
// Return: The primitive polynomial in type "Poly";
Poly Poly::integral()const
{
	Poly Result = *this;
	
	for(SortLink<Term>::const_iterator it = (Result.term_array).begin(); it != (Result.term_array).end(); it++)
	{
		LinkNode<Term>* p = it._ptr;
		(p->data).coef = (*it).coef / ( (*it).exp + 1 );
		(p->data).exp  = (*it).exp + 1;
	}
	return Result;
}

// Function: Poly Poly::integral(const double&, const double&)const;
//
// Description: Calculate the integral of current polynomial in interval [a, b].
//
// Calls: Poly Poly::integral()const;
//		  double Poly::eval()const;
//		  // Declared in "./poly.h"
//		  // Defined in current file.
//
// Input Parameter: 1. const double& a: The lower limit of integral.
//					2. const double& b: The upper limit of integral.
//
// Output Parameter: Nothing
//
// Return: The result of integral in type "double".
double Poly::integral(const double& a, const double& b)const
{
	Poly Q = integral();
	return Q.eval(b) - Q.eval(a);
}

// Function: Poly gcd(const Poly& P1, const Poly& P2);
//
// Description: Calculate the greatest common divisor polynomial(gcd) of Poly P1 and Poly P2.
//
// Calls: double Poly::main_coef()const;
//		  int Poly::deg()const;
//		  friend Poly operator  /(const Poly&, const Poly&);
//		  friend Poly operator  /(const Poly&, const double&);
//		  friend Poly operator  %(const Poly&, const Poly&);
//		  // Declared in "./poly.h";
//		  // Defined in current file.
//
// Input Parameter: const Poly& P1:	The first polynomial waited to find gcd.
//					const Poly& P2: The second polynomial waited to find gcd.
//
// Output Parameter: Nothing
//
// Return: The greatest common divisor polynomial of Poly P1 and Poly P2 in type "Poly".
Poly gcd(const Poly& P1, const Poly& P2)
{
	if(P1.main_coef() == 0 && P2.main_coef() != 0)
	{
		return P2;
	}
	if(P2.main_coef() == 0 && P1.main_coef() != 0)
	{
		return P1;
	}
	if(P2.main_coef() == 0 && P1.main_coef() == 0)
	{
		cout << "[ Error in gcd(Poly P1, Poly P2):" << endl
			 << "  P1 = P2 = 0 is not permitted! ]" << endl;
		exit(-1);
	}
	Poly A, B;
	if( P1.deg() < P2.deg() )
	{
		A = P1;
		B = P2;
	}
	else
	{
		A = P2;
		B = P1;
	}

	Poly A_last, B_last;

	while( B % A != Poly(0.) )
	{
		A_last = A;
		B_last = B;
		
		A = B_last % A_last;
		B = A_last;
	}
	return A/A.main_coef();
}

// Function: Poly gcd(const Poly& P1, const Poly& P2);
//
// Description: Calculate the least common multiple polynomial(lcm) of Poly P1 and Poly P2.
//
// Calls: double Poly::main_coef()const;
//		  Poly gcd(const Poly&, const Poly&);
//		  // Declared in "./poly.h";
//		  // Defined in current file.
//
// Input Parameter: const Poly& P1:	The first polynomial waited to find lcm.
//					const Poly& P2: The second polynomial waited to find lcm.
//
// Output Parameter: Nothing
//
// Return: The least common multiple polynomial of Poly P1 and Poly P2 in type "Poly".
Poly lcm(const Poly& P1, const Poly& P2)
{
	if(P1.main_coef() == 0 || P2.main_coef() == 0)
	{
		cout << "[ Error in lcm(Poly P1, Poly P2):" << endl
			 << "  P1 == 0 || P2 == 0 is not permitted! ]" << endl;
		exit(-1);
	}
	
	Poly P_result = P1 * P2 / gcd(P1, P2);
	return P_result/P_result.main_coef();
}

// To calculate n times Square of Poly P.
Poly pow(const Poly& P, const int& n)
{
	Poly Q = Poly(1);
	for(int i = 0; i < n; i++)
	{
		Q = Q * P;
	}
	return Q;
}

// Function: Poly unite(const int& k);
//
// Description: Generate a single term polynomial. For example unite(3) returns a polynomial of "X^3".
//
// Calls: void Poly::newTerm(const double&, const int&);
//		  // Declared in "./poly.h"
//		  // Defined in current file.
//
// Input Parameter: const int& k: The exponent of target single term.
//
// Output Parameter: Nothing
//
// Return: A single term polynomial with coefficient = 1 and exponent = k in type "Poly".
Poly unite(const int& k)
{
	Poly U;
	U.newTerm(1, k);
	return U;
}

// generate Legendre polynomial.
Poly Legendre(const int& N)
{
	int n = abs(N);
	Poly X = unite(1);

	Poly P0 = 1;
	Poly P1 = X;
	switch(n)
	{
		case 0: return P0;
		case 1: return P1;
		default: // return (2 - 1./i) * X * Legendre(n-1) - (1 - 1./i) * Legendre(n-2);
		{
			Poly P;
			for(int i = 2; i <= n; i++)
			{
				P = (2 - 1./i) * X * P1 - (1 - 1./i) * P0;
				P0 = P1;
				P1 = P;
			}
			return P;
		}
	}
}

// generate Hermite polynomial.
Poly Hermite(const int& N)
{
	int n = abs(N);
	Poly X = unite(1);

    Poly H = 1;
    for(int i = 0; i < n; i++)
    {
        H = 2 * X * H - H.diff();
    }

    return H;
}

// generate Laguerre polynomial.
Poly Laguerre(const int& N)
{
	int n = abs(N);

    Poly L = 1.;
    for(int i = 0; i < n; i++)
    {
    	L = L - L.integral();
    }

    return L;
}

// generate scaled Laguerre polynomial.
Poly Laguerre_scaled(const int& N)
{
	int n = abs(N);
	Poly X = unite(1);

	Poly L0 = 1;
	Poly L1 = -X + 1;

	switch(n)
	{
		case 0: return L0;
		case 1: return L1;
		default: // return (2*n - 1 - X) * Laguerre_scaled(n-1) - pow(n-1, 2) * Laguerre_scaled(n-2);
		{
			Poly L;
			for(int i = 2; i <= n; i++)
			{
				L = (2*i - 1 - X) * L1 - pow(i-1, 2) * L0;
				L0 = L1;
				L1 = L;
			}
			return L;
		}
	}
}

// generate Chebyshev polynomial.
Poly Chebyshev(const int& N)
{
	int n = abs(N);
	Poly X = unite(1);

	Poly T0 = 1;
	Poly T1 = X;
	switch(n)
	{
		case 0: return T0;
		case 1: return T1;
		default: // return 2 * X * Chebyshev(n-1) - Chebyshev(n-2);
		{
			Poly T;
			for(int i = 2; i <= n; i++)
			{
				T = 2 * X * T1 - T0;
				T0 = T1;
				T1 = T;
			}
			return T;
		}
	}
}