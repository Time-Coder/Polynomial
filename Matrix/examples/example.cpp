#include <matrix.h>

int main()
{
	Matrix A(3, 3);
	Matrix B(3, 3);

	cout << "Please input 3 x 3 matrix A = " << endl;
	A.input();

	cout << "Please input 3 x 3 matrix B = " << endl;
	B.input();

	cout << "A = " << A << endl;
	cout << "B = " << B << endl;

	Matrix C = A;
	C.cat(B);
	cout << "C = [A B] = " << C << endl;

	cout << "A^T = " << A.t() << endl;
	cout << "A^(-1) = " << A.inv() << endl;

	cout << "det(A) = " << A.det() << endl;
	cout << "Tr(A) = " << A.trac() << endl;
	cout << "rank(A) = " << A.rank() << endl;

	cout << "Reduce C by row change we get:" << C.reduce() << endl;

	C.clear();
	if(C.empty())
	{
		cout << "Now C is empty.";
	}

	cout << "A + B = " << A + B << endl;
	cout << "A * B = " << A * B << endl;
	cout << "2 * A = " << 2 * A << endl;
	cout << "A / 2 = " << A / 2 << endl;

	if(A == B)
	{
		cout << "A == B" << endl;
	}
	A = B;
	if(A == B)
	{
		cout << "A == B now!" << endl;
	}

	vector<Matrix> qr = A.QR();
	Matrix Q = qr[0];
	Matrix R = qr[1];
	cout << "Make QR decompose of A, we get A = QR, where" << endl
		 << "Q = " << Q << endl
		 << "R = " << R << endl;

	vector<Complex> Lambdas = A.eigenvalue();
	cout << "All eigenvalues of A are:" << endl;
	for(vector<Complex>::iterator it = Lambdas.begin(); it != Lambdas.end(); it++)
	{
		cout << (*it) << endl;
	}
	return 0;
}