#include <complex.h>

int main(int argc, char** argv)
{
	Complex X(-7.28, 6.73);
	Complex Y(3.72);

	cout << "X = " << X << endl
		 << "Y = " << Y << endl << endl;

	cout << "Re(X) = " << X.Re() << endl;
	cout << "Im(Y) = " << Y.Im() << endl;
	cout << "|X| = " << X.module() << endl;
	cout << "arg(Y) = " << Y.arg() << endl;
	cout << "conj(X) = " << X.conj() << endl;
	cout << "X + Y = " << X + Y << endl;
	cout << "X - Y = " << X - Y << endl;
	cout << "X * Y = " << X * Y << endl;
	cout << "X / Y = " << X / Y << endl;
	cout << "-X = " << -X << endl;
	cout << "exp(X) = " << exp(X) << endl;

	return 0;
}