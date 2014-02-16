/* Benjamin Chu - CMPS371 - Jan 2014
Assignment No. 8 - Program #2 */

#include <iostream>
using namespace std;

// Information from t-shirt company
int shirt[4][4] = { {10, 20, 30, 40}, {20, 10, 40, 30}, {5, 15, 20, 25}, {30, 25, 20, 15} };
int total, totalLarge, totalBlack, i;

int main() {
	// (a) Compute and display the total number of shirts
	_asm {
		mov		total, 0
		mov		ebx, 0
		mov		i, 1				// init values
	forloop1:
		cmp		i, 16				// i < 16 cont
		jg		Done1				// if not jmp to Done1
		mov		eax, [shirt + ebx]	// eax = [shirt + ebx]
		add		total, eax			// total = total + eax
		add		ebx, 4				// ebx = ebx + 4
		inc		i					// ++i
		jmp		forloop1
	Done1:
	}
	cout << "Total number of shirts: " << total << endl;
	
	// (b) Compute and display the total number of Large shirts
	_asm {
		mov		totalLarge, 0
		mov		ebx, 8
		mov		i, 1				// init values
	forloop2:
		cmp		i, 4				// i < 4
		jg		Done2				// if not jmp to Done2
		mov		eax, [shirt + ebx]	// eax = [shirt + ebx]
		add		totalLarge, eax		// total = total + eax
		add		ebx, 16				// ebx = ebx + 16
		inc		i					// ++i
		jmp		forloop2
	Done2:
	}
	cout << "Total number of Large shirts: " << totalLarge << endl;

	// (c) Compute and print the total number of Black shirts
	_asm {
		mov		totalBlack, 0
		mov		ebx, 48
		mov		i, 1				// init values
	forloop3:
		cmp		i, 4				// i < 4
		jg		Done3				// if not jmp to Done2
		mov		eax, [shirt + ebx]	// eax = [shirt + ebx]
		add		totalBlack, eax		// total = total + eax
		add		ebx, 4				// ebx = ebx + 16
		inc		i					// ++i
		jmp		forloop3
	Done3:
	}
	cout << "Total number of Black shirts: " << totalBlack << endl;

	system("pause");
	return 0;
}
/*
Output
Total number of shirts: 355
Total number of Large shirts: 110
Total number of Black shirts: 90
*/