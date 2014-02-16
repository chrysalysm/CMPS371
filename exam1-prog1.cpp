/*
Benjamin Chu - CMPS371 Assembly Language - Jan 2014
Exam No. 1 - Part 2 - Program #1
*/
#include <iostream>
using namespace std;

int main() {
	short soda, water, sandwich, total;
	cout << "==============7-11 Convenient Store=============\n";
	cout << "Drinks\n";
	cout << "\tSoda(S) .......................... $2.00\n";
	cout << "\tWater(W) ......................... $1.00\n";
	cout << "Sanwiches\n";
	cout << "\tAll kinds ........................ $8.00\n\n";
	cout << "How many drinks(soda and water): "; cin >> soda; cin >> water;
	cout << "How many Sandwiches: "; cin >> sandwich;
	
	short TWO = 2, EIGHT = 8;
	// Calculating total = sandwich * 8 + soda * 2 + water
	_asm {
		mov		ax, soda		// ax = soda
		imul	TWO				// ax = soda * 2
		mov		soda, ax		// soda = soda * 2
		mov		ax, sandwich	// ax = sandwich
		imul	EIGHT			// ax = sandwich * 8
		add		ax, soda		// ax = sandwich * 8 + soda * 2
		add		ax, water		// ax = sandwich * 8 + soda * 2 + water
		mov		total, ax;		// total = ax
	}
	cout << "Your total bill: $" << dec << total << endl;
	system("pause");
	return 0;
}
/* Output
==============7-11 Convenient Store=============
Drinks
        Soda(S) .......................... $2.00
        Water(W) ......................... $1.00
Sanwiches
        All kinds ........................ $8.00

How many drinks(soda and water): 2 4
How many Sandwiches: 3
Your total bill: $32

==============7-11 Convenient Store=============
Drinks
        Soda(S) .......................... $2.00
        Water(W) ......................... $1.00
Sanwiches
        All kinds ........................ $8.00

How many drinks(soda and water): 5 4
How many Sandwiches: 20
Your total bill: $174
*/