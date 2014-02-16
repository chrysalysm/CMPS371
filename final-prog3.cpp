// Benjamin Chu - CMPS371 - Assembly Language
// 1/27/2013 - Final Exam - Program 3
#include <iostream>
#include <iomanip>
using namespace std;
// variable init
float drink, sandwich, chip, totalBill, drinkTotal, sandwichTotal, chipTotal;
char cont;

// User continue?
void ReadCont() {
	cin.ignore();
	cout << "\nMore customers(y/n)? ";
	cin >> cont;
	cout << endl;
}

// Get user input for drinks, sandwich and chips
// Calculate with floating point operations
void InputCalc() {
	cout << endl << "\tHow many drinks, sandwiches, and chips? ";
	cin >> drink >> sandwich >> chip;
	float drinkPrice = 2.75, sandwichPrice = 7.20, chipPrice = 1.10; 
	_asm {
		fld		drinkPrice;
		fld		drink;
		fmul
		fstp	drinkTotal;
		fld		sandwichPrice;
		fld		sandwich;
		fmul
		fstp	sandwichTotal;
		fld		chipPrice;
		fld		chip;
		fmul
		fstp	chipTotal;
		fld		drinkTotal;
		fld		sandwichTotal;
		fadd
		fld		chipTotal;
		fadd
		fstp	totalBill;
	}
	cout << "\tTotal Bill = $" << setprecision(4) << totalBill << endl;
}

int main() {
	// Inital output
	cout << "==========MENU==========\n";
	cout << "Drinks ........... $2.75\n";
	cout << "Sandwiches ....... $7.20\n";
	cout << "Chips ............ $1.10\n";

	_asm {
	wloop:		// while loop
		call	InputCalc;
		call	ReadCont;
		cmp		cont, 'y'
		jne		End;
		jmp		wloop;
	End:
	}
	system("pause");
	return 0;
}
/* Output
==========MENU==========
Drinks ........... $2.75
Sandwiches ....... $7.20
Chips ............ $1.10

        How many drinks, sandwiches, and chips? 3 4 3
        Total Bill = $40.35

More customers(y/n)? y


        How many drinks, sandwiches, and chips? 4 2 4
        Total Bill = $29.8

More customers(y/n)? y


        How many drinks, sandwiches, and chips? 1 2 3
        Total Bill = $20.45

More customers(y/n)? n
*/