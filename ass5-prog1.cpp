/*===============================================
CMPS371 - Project/Assignment No. 5 - Homework
Program 1
===============================================*/
#include <iostream>
using namespace std;
int drink, sandwich, sandwichsize, totaldrink, totalsandwich, total;
char drinktype;

int main() {
	
	cout << "/==========7-11 Convenience Store==========/\n";
	cout << " Drinks\n";
	cout << "\tSoda(S) ..................... $2.00\n";
	cout << "\tWater(W) .................... $1.00\n";
	cout << "\tBeer(B) ..................... $3.00\n";
	cout << " Sandwiches\n";
	cout << "\t10 inches ................... $3.00\n";
	cout << "\t12 inches ................... $5.00\n";
	cout << "\nHow many drinks: ";
	cin >> drink;
	cout << "\tWhat kind of drink? (S = Soda, W = Water, B = Beer): ";
	cin >> drinktype;
	cout << "How many sandwiches: ";
	cin >> sandwich;
	cout << "\tWhat size of sandwich? (10in or 12in): ";
	cin >> sandwichsize;

	short ONE = 1, TWO = 2, THREE = 3, FIVE = 5;
	_asm {
		cmp		drinktype, 'S';
		je		Soda;
		cmp		drinktype, 's';
		je		Soda;

		cmp		drinktype, 'W';
		je		Water;
		cmp		drinktype, 'w';
		je		Water;
		
		cmp		drinktype, 'B';
		je		Beer;
		cmp		drinktype, 'b';
		je		Beer;

		jmp		Done;
	Soda:
		mov		eax, drink;
		imul	TWO;
		mov		totaldrink, eax;
		jmp		Done;
	Water:
		mov		eax, drink;
		imul	ONE;
		mov		totaldrink, eax;
		jmp		Done;
	Beer:
		mov		eax, drink;
		imul	THREE;
		mov		totaldrink, eax;
		jmp		Done;
	Done:
	}

	_asm {
		cmp		sandwichsize, 10;
		jne		Twelve;
		mov		eax, sandwich;
		imul	THREE;
		mov		totalsandwich, eax;
		jmp		End;
	Twelve:
		mov		eax, sandwich;
		imul	FIVE;
		mov		totalsandwich, eax;
		jmp		End;
	End:
	}
	/*
	if (drinktype == S || s)
		drink * 2;
	else if (drinktype == W || w)
		drink * 1;
	else (drinktype == B || b)
		drink * 3;

	if (sandwichsize == 10)
		sandwich * 3
	else
		
	*/
	cout << "\nYour total bill: $" << dec << totaldrink + totalsandwich << endl;
	system("pause");
	return 0;
}
/* Output
/==========7-11 Convenience Store==========/
 Drinks
        Soda(S) ..................... $2.00
        Water(W) .................... $1.00
        Beer(B) ..................... $3.00
 Sandwiches
        10 inches ................... $3.00
        12 inches ................... $5.00

How many drinks: 2
        What kind of drink? (S = Soda, W = Water, B = Beer): S
How many sandwiches: 3
        What size of sandwich? (10in or 12in): 10

Your total bill: $13

/==========7-11 Convenience Store==========/
 Drinks
        Soda(S) ..................... $2.00
        Water(W) .................... $1.00
        Beer(B) ..................... $3.00
 Sandwiches
        10 inches ................... $3.00
        12 inches ................... $5.00

How many drinks: 2
        What kind of drink? (S = Soda, W = Water, B = Beer): b
How many sandwiches: 2
        What size of sandwich? (10in or 12in): 12

Your total bill: $16
*/