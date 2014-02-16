// Benjamin Chu - CMPS371 - Exam 2 - Jan 2014
// Program #2 - Printers/Scanners

#include <iostream>
using namespace std;

short printscan = 0x1028, printer, scanner;

int main() {
	_asm {
		mov		ax, 0x1028;		// ax = 0x1028
		mov		cx, ax;			// copy ax to cx
		shl		cx, 2;			// bitshift left to clear bits 15/16
		shr		cx, 13;			// bitshift right to clear bits 1 through 11 and move value into proper position
		mov		printer, cx;	// move contents to printer
		mov		bx, ax;			// copy ax to bx
		shl		bx, 11;			// bitshift left to clear bits 6 through 16
		shr		bx, 14;			// bitshift right to clear bits 1 through 3 and move value into proper position
		mov		scanner, bx;	// move contents to scanner
	}
	// Output
	cout << "AX Register = 0x1028 = 00 010 000001 01 000b\n";
	cout << dec << printer << " printers are connected to a server." << endl;
	cout << dec << scanner << " scanners are connected to a server." << endl;
	system("pause");
	return 0;
}
/* Output

AX Register = 0x1028 = 0001 0000 0010 1000b
4 printers are connected to a server.
1 scanners are connected to a server.
Press any key to continue . . .

*/