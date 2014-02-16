// Benjamin Chu - CMPS371 - Assembly Language
// 1/27/2013 - Final Exam - Program 1
#include <iostream>
using namespace std;

short unsigned number, output;

// Finding Printer
void findPrinter() {
	_asm {
		mov		ax, number;
		shl		ax, 12;
		shr		ax, 14;
		mov		output, ax;
	}
	cout << "Number of Printers Connected: " << output << endl;
}

// Finding Port
void findPorts() {
	_asm {
		mov		ax, number;
		shl		ax, 4;
		shr		ax, 13;
		mov		output, ax;
	}
	cout << "Number of Ports Connected: " << output << endl;
}

// Finding RAM
void findRAM() {
	_asm {
		mov		ax, number;
		shr		ax, 14;
		cmp		ax, 0;
		jne		onetwothree;
		mov		output, 16;
		jmp		End;
	onetwothree:
		cmp		ax, 1;
		jne		twothree;
		mov		output, 32;
		jmp		End;
	twothree:
		cmp		ax, 2;
		jne		three;
		mov		output, 48;
		jmp		End;
	three:
		mov		output, 64;
		jmp		End;
	End:
	}
	cout << "Size of RAM: " << output << "K" << endl;
}

int main() {
	_asm {
		mov		ax, 1100111010011100b;
		mov		number, ax;
		call	findPrinter;
		call	findPorts;
		call	findRAM;
	}
	system("pause");
	return 0;
}
/* Output
Number of Printers Connected: 3
Number of Ports Connected: 7
Size of RAM: 64K
*/