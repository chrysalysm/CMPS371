// Benjamin Chu - Assignment No. 2 - Program 4
#include <iostream>
using namespace std;

int main() {
	short fah, cel, FIVE = 5, NINE = 9, THIRTYTWO = 32;
	cout << "Enter temperature in Fahrenheit: ";
	cin >> fah;

	_asm {
		mov ax, fah;
		sub ax, THIRTYTWO;
		imul FIVE;
		idiv NINE;
		mov cel, ax;
	}
	cout << fah << "F is " << cel << "C" << endl;
	system("pause");
	return 0;
}
/* Output
Enter temperature in Fahrenheit: 95
95F is 35C
*/