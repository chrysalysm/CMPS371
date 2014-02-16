// Benjamin Chu - Assignment No. 2 - Program 2
#include <iostream>
using namespace std;

int main() {
	short sandwiches, drinks, chips, total;
	cout << "/----K Store Menu----/\n";
	cout << "Sandwich ....... $4.00\n";
	cout << "Drink .......... $2.00\n";
	cout << "Chips .......... $1.00\n";
	cout << "How many sandwiches? ";
	cin >> sandwiches;
	cout << "How many drinks? ";
	cin >> drinks;
	cout << "How many chips? ";
	cin >> chips;
	short FOUR = 4, TWO = 2, ONE = 1;
	_asm {
		mov ax, sandwiches;
		imul FOUR;
		mov bx, ax;
		mov ax, drinks;
		imul TWO;
		mov cx, ax;
		mov ax, chips;
		imul ONE;
		add ax, bx;
		add ax, cx;
		mov total, ax;
	}
	cout << "Your total bill is: $" << dec << total << endl;
	system("pause");
	return 0;
}
/* Output
/----K Store Menu----/
Sandwich ....... $4.00
Drink .......... $2.00
Chips .......... $1.00
How many sandwiches? 3
How many drinks? 2
How many chips? 4
Your total bill is: $20
*/