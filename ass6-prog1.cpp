/*==============================================
CMPS371 Homework - Assignment No. 6 - Program 1
===============================================*/
#include <iostream>
using namespace std;

char grades;
int Anum, Bnum, Cnum, Dnum;

void Read() {
	cin.get(grades);
}

int main() {
	cout << "Enter 10 grades (A,B,C,D): ";
	_asm {
		mov		Anum, 0;
		mov		Bnum, 0;
		mov		Cnum, 0;
		mov		Dnum, 0;
		call	Read;
		
	wloop:
		cmp		grades, '\n';
		je		End;
		cmp		grades, 'A';
		jnge	Done;
		cmp		grades, 'z';
		jnle	Done;
		
		cmp		grades, 'A';
		je		AddA;
		cmp		grades, 'a';
		je		AddA;

		cmp		grades, 'B';
		je		AddB;
		cmp		grades, 'b';
		je		AddB;

		cmp		grades, 'C';
		je		AddC;
		cmp		grades, 'c';
		je		AddC;

		cmp		grades, 'D';
		je		AddD;
		cmp		grades, 'd';
		je		AddD;
		jmp		Done;

	AddA:
		inc		Anum;
		jmp		Done;
	AddB:
		inc		Bnum;
		jmp		Done;
	AddC:
		inc		Cnum;
		jmp		Done;
	AddD:
		inc		Dnum;
		jmp		Done;

	Done:
		call	Read;
		jmp		wloop;

	End:

	}
	
	/*
	while (grades != '\n') {
		if (grades >= 'A' && grades <='z') {
			if (grades == 'A' || grades == 'a') {
				cout << "A found\n";
			}
			else if (grades == 'B' || grades == 'b') {
				cout << "B found\n";
			}
			else if (grades == 'C' || grades == 'c') {
				cout << "C found\n";
			} else {
				cout << "D found\n";
			}

		}
		cin.get(grades);
	}
	*/

	cout << "No. of A scores = " << Anum << endl;
	cout << "No. of B scores = " << Bnum << endl;
	cout << "No. of C scores = " << Cnum << endl;
	cout << "No. of D scores = " << Dnum << endl;

	system("pause");
	return 0;
}
/* Output
Enter 10 grades (A,B,C,D): AbbBCCAAdD
No. of A scores = 3
No. of B scores = 3
No. of C scores = 2
No. of D scores = 2
*/