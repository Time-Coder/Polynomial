#include <poly.h>

int main()
{
	Poly P1, P2;

	// 可从终端直接输入多项式：
	// cin >> P1;
	//--------------------

	// 可以以添加项的方式创建多项式：
	P1.newTerm( 1, 4);
	P1.newTerm( 3, 3);
	P1.newTerm(-7, 2);
	P1.newTerm(-8, 1);
	P1.newTerm( 3, 0);

	P2.newTerm(-2, 3);
	P2.newTerm( 2, 2);
	P2.newTerm( 3, 1);
	P2.newTerm( 5, 0);
	//------------------------

	//可以直接 cout 输出多项式：
	cout << "P1 = " << P1 << endl;
	cout << "P2 = " << P2 << endl;
	//-----------------------------

	cout << endl;

	//可直接做 + - * / % 运算：
	cout << "P1 + P2 = " << P1 + P2 << endl;
	cout << "P1 - P2 = " << P1 - P2 << endl;
	cout << "P1 * P2 = " << P1 * P2 << endl;
	cout << "P1 / P2 = " << P1 / P2 << endl;
	cout << "P1 % P2 = " << P1 % P2 << endl;
	//--------------------------------------

	cout << endl;

	//可以找两个多项式的最小公倍式， 最大公因式：
	cout << "gcd(P1, P2) = " << gcd(P1, P2) << endl;
	cout << "lcm(P1, P2) = " << lcm(P1, P2) << endl;
	//----------------------------------------------

	cout << endl;

	//可以获取多项式的各种信息：
	cout << "P1 的次数为:\t\t\t" << P1.deg() << endl;
	cout << "P1 的主系数为:\t\t\t" << P1.main_coef() << endl;
	cout << "P1 的 4 次项系数为:\t\t" << P1.coef(4) << endl;
	cout << "P1 在 x = 3 + i*2 处的取值为:\t" << P1.eval( Complex(3, 2) ) << endl;
	cout << "P1 在 x = -2 处的取值为:\t" << P1.eval(-2) << endl;
	cout << "P1 与 P2 的复合多项式:" << endl << "P1(P2) = " << P1.com(P2) << endl;
	cout << "P1 的导多项式为:" << endl << "P1\'(X) = " << P1.diff() << endl;
	//--------------------------------------------------------------------------

	//可以用 clear() 清空多项式:
	P1.clear();
	//------------------------

	P1.newTerm(-3.75, 10);
	P1.newTerm( 2.73, 9);
	P1.newTerm(-6.28, 8);
	P1.newTerm( 4.57, 7);
	P1.newTerm(-7.62, 6);
	P1.newTerm( 9.62, 5);
	P1.newTerm( 9.12, 4);
	P1.newTerm( 0.28, 3);
	P1.newTerm( 3.45, 2);
	P1.newTerm( 2.54, 1);
	P1.newTerm(-7.78, 0);

	cout << endl;

	//可直接等号赋值:
	P2 = P1;
	cout << "现在，P2 变为:" << endl
		 << "P2 = " << P2 << endl;
	//-----------------------------

	cout << endl;

	//可以求多项式的根:
	vector<Complex> Roots = P2.roots();
	if(P2.deg() != 0)
	{
		cout << "多项式 P2 的所有根为:" << endl << endl;
	}
	for(int i = 0; i < Roots.size(); i++)
	{
		cout << "X[" << i+1 << "] = " << Roots[i] << endl;
	}

	return 0;
}