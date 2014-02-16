/* Benjamin Chu - CMPS371 - Jan 2014
Assignment No. 7 - Program #3 */
#include <iostream>
using namespace std;

short sprinklers = 0x6a2f, countON = 0, countOFF = 0, loopnum = 16, i = 0;
// 0x6a2f = 0110 1010 0010 1111
// 9 sprinklers ON, 7 sprinklers OFF

void sprinklerOff() {
	cout << "Sprinkler Number: " << dec << i << " is currently off!" << endl;
}

int main() {
	cout << "The 16 sprinklers in Masson Park are running!" << endl << endl;
	_asm {
		mov		bx, sprinklers;
		mov		cx, loopnum;
	// loop through ax and bitshift by 1
	// 'AND' the shifted number to 0x0001 and compare to 1
	// if ax = 1 then countON + 1
	// if ax != then countOFF + 1
	forloop:
		cmp		i, cx;
		jge		Exit;
		mov		ax, bx;
		and		ax, 0x0001;
		cmp		ax, 1;
		jne		BitShift;
		inc		countON;
		inc		i;
		shr		bx, 1;
		jmp		forloop;
	BitShift:
		shr		bx, 1;
		inc		countOFF;
		inc		i;
		call	sprinklerOff;
		mov		cx, loopnum;
		jmp		forloop;
	Exit:
	}
	cout << countOFF << " sprinklers are off." << endl << endl;
	cout << countON << " sprinklers are currently running." << endl;
	system("pause");
	return 0;
}

/* Output
The 16 sprinklers in Masson Park are running!

Sprinkler Number: 5 is currently off!
Sprinkler Number: 7 is currently off!
Sprinkler Number: 8 is currently off!
Sprinkler Number: 9 is currently off!
Sprinkler Number: 11 is currently off!
Sprinkler Number: 13 is currently off!
Sprinkler Number: 16 is currently off!
7 sprinklers are off.

9 sprinklers are currently running.
*/