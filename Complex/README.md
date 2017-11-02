The structrue of this directory is:

file "README.md"
file "complex.h"
file "complex.cpp"
directory "examples"
	file "README.md"
	file "example.cpp"
	file "Makefile"

"complex.h" and "complex.cpp" has constructed a complex number's class named "Complex".
It has realized following functions:

* Use "Complex A;" to defined a Complex A with real part 0 and imaginary part 0;
* Use "Complex A(re, im);" to defined a Complex A with real part "re" and imaginary part "im";
* Use "Complex A(re);" or "Complex A = re"(with re in type "double") to defined a Complex A with real part "re" and imaginary part 0;
* Use "Complex A(B);" or "Complex A = B;" to define a Complex A and initialize it by B;
* Use "A = B;" to clone B to A;
* Use "A = x;" to assign a real(double) number x to Complex A, that means A.Im() = 0;
* Use "A.isZero();" to judge if a Complex A is zero(A.Re() == 0 && A.Im() == 0);
* Use "A.Re();" to get the real part of Complex A;
* Use "A.Im();" to get the imaginary part of Complex A;
* Use "A.module();" to calculate the module of Complex A;
* Use "A.arg();" to calculate the argumet of Complex A;
* Use "A.conj();" to calculate the conjugation of Complex A;
* +, -, *, /, ==, != are available between Complex and Complex;
* +, -, *, /, ^ are avaible between Complex and double;
* Use "pow(A, n);" to calculate A^n when A is a Complex;
* Use "exp(A);" to calcuatate exp(A) when A is a Complex;

There is a example program in "./examples/". You can compile the example by the guiding of "./example/README.md".

The object to build this Complex class is to store the complex eigenvalue of matrix or complex roots of polynomial.
So it is used by class "Poly"(defined in "../Poly") and class "Matrix"(defined in "../Matrix").