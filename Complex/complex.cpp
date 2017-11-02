#include <complex.h>

Complex::Complex()
{
	real = 0;
	imag = 0;
}

Complex::Complex(const double& re, const double& im)
{
	real = re;
	imag = im;
}

Complex::Complex(const double& x)
{
	real = x;
	imag = 0;
}

Complex::Complex(const Complex& x)
{
	real = x.real;
	imag = x.imag;
}

Complex& Complex::operator =(const Complex& x)
{
	real = x.real;
	imag = x.imag;

	return *this;
}

Complex& Complex::operator =(const double& k)
{
	real = k;
	imag = 0;

	return *this;
}

Complex Complex::operator -()const
{
	return Complex(-real, -imag);
}

double Complex::Re()const
{
	return real;
}

double Complex::Im()const
{
	return imag;
}

//-------------------------------------------------------------------------------

double Complex::module()const
{
	return sqrt( pow(real, 2) + pow(imag, 2) );
}

double Complex::arg()const
{
	double PI = 3.141592654;
	if( imag != 0 || real > 0 )
	{
		return 2 * atan( imag / (real + module()) );
	}
	else if( real != 0 )
	{
		return PI;
	}
	else
	{
		return 0;
	}
}

Complex Complex::conj()const
{
	return Complex(real, -imag);
}

bool Complex::isZero()const
{
	return ( fabs(real) < 1E-6 && fabs(imag) < 1E-6 );
}

//------------------------------------------------------------------------------

bool isZero(const double& x)
{
	return (fabs(x) < 1E-6);
}

ostream & operator <<(ostream & o, const Complex& x)  
{
	double Real = x.real;
	double Imag = x.imag;

	if( !isZero(Real) )
	{
		if(Real > 1E-6)
		{
			cout << " ";
		}
		if( Imag > 1E-6 && !isZero(Imag - 1) )
		{
			o << Real << " + i * " << Imag;
		}
		else if( Imag < -1E-6 && !isZero(Imag + 1) )
		{
			o << Real << " - i * " << -Imag;
		}
		else if( isZero(Imag - 1) )
		{
			o << Real << " + i";
		}
		else if( isZero(Imag + 1) )
		{
			o << Real << " - i";
		}
		else if( isZero(Imag) )
		{
			o << Real;
		}
	}
	else
	{
		if( Imag > 1E-6 && !isZero(Imag-1) )
		{
			o << " i * " << Imag;
		}
		else if( Imag < -1E-6 && !isZero(Imag+1) )
		{
			o << "-i * " << -Imag;
		}
		else if( isZero(Imag - 1) )
		{
			o << " i";
		}
		else if( isZero(Imag + 1) )
		{
			o << "-i";
		}
		else if( isZero(Imag) )
		{
			o << " 0";
		}
	}

	return o;
}

//--------------------------------------------------------------------------------

bool operator ==(const Complex& x, const Complex& y)
{
	return (x.real == y.real && x.imag == y.imag);
}

bool operator !=(const Complex& x, const Complex& y)
{
	return (x.real != y.real || x.imag != y.imag);
}

Complex operator +(const Complex& x, const Complex& y)
{
	return Complex(x.real + y.real, x.imag + y.imag);
}

Complex operator +(const double& k, const Complex& x)
{
	Complex y = Complex(k);
	return y + x;
}

Complex operator +(const Complex& x, const double& k)
{
	Complex y = Complex(k);
	return x + y;
}

Complex operator -(const Complex& x, const Complex& y)
{
	return x + (-y);
}

Complex operator -(const double& k, const Complex& x)
{
	return Complex(k) - x;
}

Complex operator -(const Complex& x, const double& k)
{
	return x - Complex(k);
}

Complex operator *(const Complex& x, const Complex& y)
{
	return Complex( x.real * y.real - x.imag * y.imag,
				    x.imag * y.real + x.real * y.imag );
}

Complex operator *(const double& k, const Complex& x)
{
	return Complex(k) * x;
}

Complex operator *(const Complex& x, const double& k)
{
	return x * Complex(k);
}

Complex operator /(const Complex& x, const Complex& y)
{
	if( y.isZero() )
	{
		cout << "Error in complex divide: the divisor is zero!" << endl;
		exit(-1);
	}
	else
	{
		double divisor = pow( y.module(), 2 );
		return Complex( (x.real*y.real+x.imag*y.imag) / divisor,
					 	(x.imag*y.real-x.real*y.imag) / divisor );
	}
}

Complex operator /(const double& k, const Complex& x)
{
	return Complex(k) / x;
}

Complex operator /(const Complex& x, const double& k)
{
	return x / Complex(k);
}

Complex operator ^(const Complex& x, const double& n)
{
	return pow(x, n);
}

Complex operator ^(const double& a, const Complex& z)
{
	return exp(z)^(log(a)/log(exp(1)));
}

//--------------------------------------------------------------------------------

Complex pow(const Complex& x, const double& n)
{
	double theta = x.arg();
	return pow(x.module(), n) * Complex( cos(n * theta), sin(n * theta) );
}

Complex exp(const Complex& x)
{
	return exp(x.Re()) * Complex( cos(x.Im()), sin(x.Im()) );
}
