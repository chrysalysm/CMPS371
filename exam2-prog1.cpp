// Benjamin Chu - CMPS371 - Exam 2 - Jan 2014
// Program #1 - PIN Number
#include <iostream>
using namespace std;

short number, num1, num2, num3, num4, THOUSAND = 1000, HUNDRED = 100, TEN = 10;
char cont;

// Check if the user wants to try again
void ReadCont() {
	cout << "\nDo you want to try again (y/n)? ";
	cin >> cont;
	cin.ignore();
	cout << endl;
}

// Output for Even valid PIN
void EvenPrint() {
	cout << number << "is a valid PIN number." << endl;
}
// Output for Odd invalid PIN
void OddPrint() {
	cout << number << "is not a valid PIN number." << endl;
}
// Getting user input and doing calulations for valid PIN
void InputGet() {
	cout << "Enter a four digit int PIN number: "; cin >> number;
	_asm {
		mov		ax, number;		// ax = number
		cwd
		idiv	THOUSAND;		// ax = number / 1000, ax = quotient, dx = remainder
		mov		num1, ax;		// num1 = number / 1000
		mov		ax, dx;			// ax = dx = remainder
		cwd
		idiv	HUNDRED;		// ax = remainder / 100
		mov		num2, ax;		// num2 = remainder / 100
		mov		ax, dx;			// ax = dx = remainder
		cwd
		idiv	TEN;			// ax = remainder / 10
		mov		num3, ax;		// num3 = remainder / 10
		mov		num4, dx;		// num4 = dx
		mov		ax, num1;		// ax = num1
		add		ax, num2;		// ax = num1 + num2
		add		ax, num3;		// ax = num1 + num2 + num3
		add		ax, num4;		// ax = num1 + num2 + num3 + num4
		and		ax, 0x0001;		// AND 0x0001
		cmp		ax, 1;			// if least significant bit is 1, then ODD, if 0, then EVEN
		jne		EvenC;
		call	OddPrint;
		jmp		Exit;
	EvenC:
		call	EvenPrint;
		jmp		Exit;
	Exit:
	}
}

int main() {
	_asm {
	wloop:					// whileloop
		call	InputGet;	// get input and do calculations
		call	ReadCont;	// check if user wants to try again
		cmp		cont, 'y';	// if cont != 'y' then End
		jne		End;
		jmp		wloop;		// if not, loop
	End:
	}
	system("pause");
	return 0;
}