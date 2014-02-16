/*==============================================
CMPS371 Homework - Assignment No. 6 - Program 2
===============================================*/
#include <iostream>
using namespace std;
// Global Variables
char votes;
int Yesnum, Nonum, i;

void Star() {
	cout << "* ";
}

void Read() {
	cin.get(votes);
}

void YesStarDisplay() {
	_asm {
		mov		eax, 0;
		mov		ebx, Yesnum;
		mov		i, 1;
forloop:
		cmp		i, ebx;
		jg		Finish;
		call	Star;
		inc		i;
		jmp		forloop;
Finish:
	}
}

void NoStarDisplay() {
	_asm {
		mov		eax, 0;
		mov		ebx, Nonum;
		mov		i, 1;
forloop:
		cmp		i, ebx;
		jg		Finish;
		call	Star;
		inc		i;
		jmp		forloop;
Finish:
	}
}

int main() {
	cout << "Enter a group of votes: ";
	_asm {
		mov		Yesnum, 0;
		mov		Nonum, 0;
		call	Read;
		
	wloop:
		cmp		votes, '\n';
		je		End;
		cmp		votes, 'N';
		jnge	Done;
		cmp		votes, 'y';
		jnle	Done;
		
		cmp		votes, 'Y';
		je		AddYes;
		cmp		votes, 'y';
		je		AddYes;

		cmp		votes, 'N';
		je		AddNo;
		cmp		votes, 'n';
		je		AddNo;
		jmp		Done;

	AddYes:
		inc		Yesnum;
		jmp		Done;
	AddNo:
		inc		Nonum;
		jmp		Done;

	Done:
		call	Read;
		jmp		wloop;

	End:

	}
	
	/*
	while (votes != '\n') {
		if (votes >= 'N' && votes <='y') {
			if (votes == 'Y' || votes == 'y") {
				Yesnum++;
			} else {
				Nonum++;
			}
		}
		cin.get(votes);
	}
	*/

	cout << "\tYES Votes = " << Yesnum << " = ";
	_asm {
		call YesStarDisplay;
	}
	cout << endl;
	cout << "\tNo Votes = " << Nonum << " = ";
	_asm {
		call NoStarDisplay;
	}
	cout << endl;

	system("pause");
	return 0;
}
/* Output
Enter a group of votes: yNNNYnyynN
        YES Votes = 4 = * * * *
        No Votes = 6 = * * * * * *

Enter a group of votes: YYNnnYnyYYNyny
        YES Votes = 8 = * * * * * * * *
        No Votes = 6 = * * * * * *
*/