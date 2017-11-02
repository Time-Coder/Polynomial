The structrue of this directory is:

file "README.md"
file "poly.h"
file "poly.cpp"
directory "examples"
	file "README.md"
	file "example.cpp"
	file "Makefile"

"poly.h" and "poly.cpp" has constructed a polynomial class named "Poly". It has realized following functions:

* Use "Poly P;" to define a polynomial;
* Use "Poly P(x);"(with x a double or int) to define a polynomial that just has a normal number term;
* Use "Poly P(str);"(with str a std::string or char*) to define a polynomial and convert the expression string automaticly to Poly;
* Use "cin >> P;" to get a Poly from screen input(Just use writing format, for example, just input "-7 + X^3 + 6*X");
* Use "cout << P;" to print the polynomial to the screen in writing format;
* Use "P = Q" to clone Poly Q to Poly P;
* Use "P.clear();" to clear Poly's memory;
* +, -, *, /, %, +=, -=, *=, /=, %= is available between Poly and Poly, Poly and double;
* Use "gcd(P, Q);"(with P, Q two Poly) to calculate the greatest common divisor polynomial of P and Q;
* Use "lcm(P, Q);"(with P, Q two Poly) to calculate the least common multiple polynomial of P and Q;
* Use "P.deg();" to get the degree of Poly P;
* Use "P.main_coef();" to get the main coefficient(the coefficient of highest-dgree term) of Poly P;
* Use "P.coef(k);" to get the coefficient of k times exponent term of Poly P;
* Use "P.eval(x);" to calculate the value of Poly P at point x;
* Use "P.com(Q);" to calculate the composite polynomial( P(Q(X)) );
* Use "P.diff();" to calculate the differential polynomial of Poly P;
* Use "P.integral();" to calculate the primitive polynomial of Poly P;
* Use "P.integral(a, b)"(with a and b two double) to calculate the integral of Poly P in interval [a, b];
* Use "P.search_zero_point(a, b, epsilon);"(with a, b and epsilon three double) to find out a real zero point of Poly P in interval [a, b].(only if P(a)*P(b) < 0).
* Use "P.roots();" to find out all roots of Poly P(including complex roots). It returns vector<Complex>;
* Use "Legendre(n);" to generate a Legnedre polynomial of order n;
* Use "Hermite(n);" to generate a Hermite polynomial of order n;
* Use "Laguerre(n);" to generate a Laguerre polynomial of order n;
* Use "Laguerre_scaled(n);" to generate a scaled Laguerre polynomial of order n;
* Use "Chebyshev(n);" to generate a Chebyshev polynomial of order n.

There are example program in "./examples/". You can compile the example by the guiding of "./example/README.md".

The object to build this Poly class is to calculates Hermite polynomial's roots when calculating integral using Hermite-Gauss method.