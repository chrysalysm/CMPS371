/* Benjamin Chu - CMPS371 - Jan 2014
Assignment No. 7 - Program #2 */
#include <iostream>
using namespace std;

short number, loopnum, output, i;
void EvenPrint() {
	cout << "\t" << number << " is EVEN." << endl;
}

void OddPrint() {
	cout << "\t" << number << " is ODD." << endl;
}
void EvenOdd() {
	cout << endl << "\tEnter an integer number: "; cin >> number;
	// if least significant bit is 1, result is ODD
	// if least significant bit is 0, result is EVEN
	_asm {
		mov		bx, number;
		shl		bx, 15;
		shr		bx, 15;
		and		bx, 0000000000000001b;
		cmp		bx, 1;
		je		Odd;
		call	EvenPrint;
		jmp		Exit;
	Odd:
		call	OddPrint;
		jmp		Exit;
	Exit:
	}
	cin.ignore();
}

int main() {
	cout << "How many numbers would you like to try: "; cin >> loopnum;
	// loop number determined by user input
	_asm {
	forloop:
		mov		ax, loopnum;
		cmp		i, ax;
		jge		Done;
		call	EvenOdd;
		inc		i;
		jmp		forloop;
	Done:
	}
	system("pause");
	return 0;
}

/* Output
How many numbers would you like to try: 4

Enter an integer number: 124
124 is EVEN.

Enter an integer number: 37
37 is ODD.

Enter an integer number: 3456
3456 is EVEN.

Enter an integer number: 555
555 is ODD.

How many numbers would you like to try: 5

Enter an integer number: 123
123 is ODD.

Enter an integer number: 344
344 is EVEN.

Enter an integer number: 2004
2004 is EVEN.

Enter an integer number: 999
999 is ODD.

Enter an integer number: 6534
6534 is EVEN.
*/