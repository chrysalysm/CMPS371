// Benjamin Chu - CMPS371 - Exam 2 - Jan 2014
// Program #3 - Group of Scores
#include <iostream>
using namespace std;

short number, negone = -1, sum = 0, maximum = 0, minimum = 100, counter = -1;
// Read user input
void Read() {
	cin >> number;
}

int main() {
	cout << "Enter a group of scores with -1 at the end: ";
	_asm {
	negloop:
		inc		counter;		// increment counter for average
		call	Read;			// get user input
		mov		bx, negone;		// bx = -1
		cmp		bx, number;		// check if user input is -1
		je		Exit;			// if user input = -1, then exit loop
		mov		ax, sum;		// ax = sum
		add		ax, number;		// ax = ax + number
		mov		sum, ax;		// sum = ax;
		mov		cx, number;		// cx = number;

		cmp		cx, maximum;	// if (number > maximum)
		jng		NotMax;
		mov		maximum, cx;	// setting maximum
NotMax:
		cmp		cx, minimum;	// if (number < minimum)
		jnl		NotMin;
		mov		minimum, cx;	// setting minimum
NotMin:
		jmp		negloop;		// loop

	Exit:
	}
	cout << "Max: " << maximum << endl;
	cout << "Min: " << minimum << endl;
	cout << "Average: " << sum / counter << endl;
	system("pause");
	return 0;
}
/* Output

Enter a group of scores with -1 at the end: 30 70 10 90 50 -1
Max: 90
Min: 10
Average: 50

Enter a group of scores with -1 at the end: 33 23 10 67 46 56 23 74 -1
Max: 74
Min: 10
Average: 41

*/