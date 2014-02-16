#include <iostream>
#include <iomanip>
using namespace std;

float a, b, c, d, x1, x2;
float b2, FOUR = 4.0, fourac;
float dsquareroot = 0.0, bneg = 0.0, twoa = 0.0, temp1 = 0.0, temp2 = 0.0, TWO = 2;
char cont;

void ReadCont() {
	cin.ignore();
	cout << "\nContinue (y/n)? ";
	cin >> cont;
	cout << endl;
}

void twoComplex() {
	cout << "\tThere are two complex solutions." << endl;
}

void solution() {
	cout << "\t\tX1 = " << setprecision(3) << x1 << endl;
	cout << "\t\tX2 = " << x2 << endl;

}

void InputCalc() {
	// Part (i), reading the values of a, b, c
	cout << "\tPlease enter the values for a, b, and c: ";
	cin >> a >> b >> c;
	// Part (ii), finding d = (b*b) - (4ac)
	float thousand = 1000;
	_asm {
		fld		b;
		fld		b;
		fmul
		fstp	b2;
		fld		a;
		fld		c;
		fmul
		fld		FOUR;
		fmul
		fstp	fourac;
		fninit
		fld		b2;
		fld		fourac;
		fsub			// fsub st(1) - st(0) = b2 - fourac
		fld		thousand
		fmul
		frndint
		fld		thousand
		fdiv
		fstp	d;
	}
	// removing negative from zero
	if (d == 0) {
		_asm {
			fld		d;
			fabs
			fstp	d;
		}
	}
	// Part (iii)
	// if d >= 0, then x1 and x2
	// if d < 0, then there are two complex solutions
	_asm {
		fninit
		fld		d;
		cmp		d, 0
		jl		COMPLEX;
		fsqrt
		fstp	dsquareroot;
		fld		b;
		fchs
		fstp	bneg;
		fld		a;
		fld		TWO;
		fmul
		fstp	twoa;
		// calculating x1
		fld		dsquareroot;
		fld		bneg;
		fadd
		fstp	temp1;
		fld		twoa;
		fld		temp1;
		fdivr
		fstp	x1;
		// calculating x2 
		fld		bneg;
		fld		dsquareroot;
		fsub
		fstp	temp2;
		fld		twoa;
		fld		temp2;
		fdivr
		fstp	x2;
		call	solution;
		jmp		Exit
	COMPLEX :
		call	twoComplex;
		jmp		Exit
		Exit :
	}
}

int main() {
	cout << "To find the roots of [ aX^2 + bX + c = 0 ]" << endl;
	_asm {
	wloop:
		call	InputCalc;
		call	ReadCont;
		cmp		cont, 'y';
		jne		End;
		jmp		wloop;
	End:
	}
	system("pause");
	return 0;
}

/* Output

To find the roots of [ aX^2 + bX + c = 0 ]
Please enter the values for a, b, and c: 1 -0.95 -6.67
X1 = 3.1
X2 = -2.15

Continue (y/n)? y

Please enter the values for a, b, and c: 1 -4.62 5.3361
X1 = 2.31
X2 = 2.31

Continue (y/n)? y

Please enter the values for a, b, and c: 1 2 4
There are two complex solutions.

Continue (y/n)? n

*/