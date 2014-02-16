/* Benjamin Chu - CMPS371 - Jan 2014
Assignment No. 7 - Program #1 */
#include <iostream>
#include <string>
using namespace std;

char input, cont, charout;
int output, num;

void ReadCont() {
	cout << "\nContinue (y/n)? ";
	cin >> cont;
	cin.ignore();
	cout << endl;
}

void invalidInput() {
	cout << "Invalid input detected. Input must be between 'A' and 'Z'." << endl;
}

void Read() {
	cin.get(input);
}

void Display() {
	// displaying 2nd letter through bitshift
	_asm {
		mov		num, ebx;
		shl		ebx, 16;
		shr		ebx, 24;
		mov		output, ebx;
	}
	charout = (char)output;
	cout << "The 2nd letter is: " << charout << endl;
	// displaying 4th letter through bitshift
	_asm {
		mov		ecx, num;
		shr		ecx, 24;
		mov		output, ecx;
	}
	charout = (char)output;
	cout << "The 4th letter is: " << charout << endl;
}

void InputGet() {
	cout << "Enter a four letter word: ";
	_asm {
		// User input for 1st letter
		call	Read;
		cmp		input, '\n';	// Detecting end of input
		je		Exit;
		cmp		input, 'A';		// Validating user input above 'A'
		jnge	Done;
		cmp		input, 'Z';		// Validating user input below 'Z'
		jnle	Done;

		movzx   ebx, input;		// ebx = input
		shl		ebx, 8;			// ebx << 8

		// User input for 2nd letter
		call	Read;
		cmp		input, '\n';
		je		Exit;
		cmp		input, 'A';
		jnge	Done;
		cmp		input, 'Z';
		jnle	Done;

		movzx	ecx, input;
		or		ebx, ecx;		// 'OR' result with previous
		shl		ebx, 8;			// ebx << 8

		// User input for 3rd letter
		call	Read;
		cmp		input, '\n';
		je		Exit;
		cmp		input, 'A';
		jnge	Done;
		cmp		input, 'Z';
		jnle	Done;

		movzx	ecx, input;
		or		ebx, ecx;		// 'OR' result with previous
		shl		ebx, 8;			// ebx << 8

		// User input for 4th letter
		call	Read;
		cmp		input, '\n';
		je		Exit;
		cmp		input, 'A';
		jnge	Done;
		cmp		input, 'Z';
		jnle	Done;

		movzx	ecx, input;
		or		ebx, ecx;		// 'OR' result with previous
		mov		ecx, ebx;		// ebx << 8

		call	Display;
		jmp		Exit;

	Done:
		call	invalidInput;
		jmp		Exit;
	Exit:
	}
}

int main() {

	_asm {
	wloop:
		call	InputGet;
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
Enter a four letter word: LOVE
The 2nd letter is: V
The 4th letter is: L

Continue (y/n)? y

Enter a four letter word: HELP
The 2nd letter is: L
The 4th letter is: H

Continue (y/n)? n

Enter a four letter word: DISK
The 2nd letter is: S
The 4th letter is: D

Continue (y/n)? y

Enter a four letter word: HATE
The 2nd letter is: T
The 4th letter is: H

Continue (y/n)? n
*/