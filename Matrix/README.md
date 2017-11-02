The structrue of this directory is:

file "README.md"
file "matrix.h"
file "matrix.cpp"
directory "examples"
	file "README.md"
	file "example.cpp"
	file "Makefile"

"matrix.h" and "matrix.cpp" has constructed a matrix class named "Matrix". It has realized following functions:
* Use "Matrix A;" to define an empty Matrix;
* Use "Matrix A(m, n)" to define a Matrix with rows "m" and colums "n" and all elements are 0;
* Use "Matrix A(B);" or "Matrix A = B;" to define a Matrix and initialize it by B;
* Use "A.input();" to get Matrix A from screen;
* Use "A.clear()" to clear a Matrix;
* Use "A.exchange_row(row1, row2);" to exchange row1 and row2 of A;
* Use "A.scale_row(scale, row_i);" to scale A's row_i with double number scale;
* Use "A.scale_add_row(row1, scale, row2);" to add scale*(row1 of A) to (row2 of A);
* Use "A.exchange_col(col1, col2);" to exchange col1 and col2 of A;
* Use "A.scale_col(scale, col_i);" to scale A's col_i with double number scale;
* Use "A.scale_add_col(col1, scale, col2);" to add scale*(col1 of A) to (col2 of A);
* Use "A.col(k);" to get a colum vector of colum k of A (still in type "Matrix");
* Use "A.cat(B);" to catch a Matrix B on the right of A;
* Use "A = B;" to clone B to A;
* +, -, *, ==, != are available between Matrix and Matrix;
* *, / are available between Matrix and double;
* Use "A.t();" to calculate Matrix A's transpose;
* Use "A.inv();" to calculate Matrix A's inverse;
* Use "A.reduce();" to reduce Matrix A by row changing;
* Use "A.det();" to calculate Matrix A's determinant;
* Use "A.trac();" to calculate Matrix A's trace;
* Use "A.rank();" to calculate Matrix A's rank;
* Use "A.empty();" to judge if A is empty;
* Use "A.QR();" to calculate the QR decompose of A, it returns Matrix Q and Matrix R in vector<Matrix>;
* Use "A.eigenvalue();" to calculate all eigenvalues of Matrix A;
* Use "pow(A, n);" to calculate A^n;
* Use "eye(n);" to generate a unit matrix of order n;
* Use "Gram_Schmidt(A);" to generate a orthonormal basis of A's colum space (still in type "Matrix");
* Use "correct(A);" to make all elements in A that is near to 0 to be 0;
* Use "Householder(A);" to make a Householder transform of Matrix A;
* Use "A.data[i][j]" to get and set data of A, they are public.

There are example program in "./examples/". You can compile the example by the guiding of "./example/README.md".

The object to build this Matrix class is to calculates polynomial roots.
So it is used by class "Poly"(defined in "../Poly")