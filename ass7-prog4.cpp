/* Benjamin Chu - CMPS371 - Jan 2014
Assignment No. 7 - Program #4 */

#include <iostream>
#include <time.h>
using namespace std;
// variable declaration
short a, i = 0, b = 0, output, finalax;

// random number generator and adding to finalax
void randNum() {
	a = rand() % 15 + 1;
	_asm {
		mov		ax, 0x01		// ax = 0x01 
		mov		cx, a			// cx = a = rand() % 15 + 1
		shl		ax, cl			// ax << cl = a
		or		finalax, ax		// finalax = ax << cl = a
	}
}
// print the floor pressed
// +1 for output is to compensate for least significant bit starting at 0 and not 1
void pressprint() {
	cout << dec << " [ " << output + 1 << " ]\tfloor was pressed." << endl;
}
// print the floor the elevator will stop at
void floorprint() {
	cout << "Elevator will stop at floor " << b + 1 << endl;
}

int main() {
	srand(time(NULL));
	cout << "Welcome to the Sheraton Hotel in Irvine." << endl;
	cout << "This hotel is a 16 floor building." << endl;
	cout << "10 people have entered the elevator.\n" << endl;

	_asm {
		mov		bx, 0x00	// bx = 0x00
	forloop1:				// first forloop
		mov		dx, i		// dx = i
		cmp		dx, 10		// dx = i < 10
		jge		Done		// if i >= 10 jump Done
		call	randNum
		mov		cx, a		// cx = a = rand() % 15 + 1;
		mov		output, cx	// output = cx
		call	pressprint
		inc		i			// ++i
		jmp		forloop1
	Done:
							// (ii) Using AX register to see what floors the elevator will stop
	forloop2:				// second forloop
		mov ax, finalax		// ax = finalax
		mov cx, b			// cx = b
		cmp cx, 16			// cx = b < 16
		jge Exit;			// if b >= 16 jump Exit
		shr ax, cl;			// ax >> cl
		and ax, 0x0001;		// and ax by 1
		cmp ax, 0x0001;		// compare ax to 1
		jne increment		// if not equal to 1, jmp increment
		call floorprint		// if equal to 1, floorprint()
		inc b				// increment b
		jmp forloop2		// jump back to loop
	increment:
		inc b				// increment b
		jmp forloop2		// jump back to loop

	Exit:
	}
	// (i) Displaying the content of AX at base16
	cout << "\nThe value of AX (base16): " << hex << finalax << endl << endl;
	system("pause");
	return 0;
}
/*
Welcome to the Sheraton Hotel in Irvine.
This hotel is a 16 floor building.
10 people have entered the elevator.

 [ 12 ] floor was pressed.
 [ 7 ]  floor was pressed.
 [ 6 ]  floor was pressed.
 [ 7 ]  floor was pressed.
 [ 14 ] floor was pressed.
 [ 3 ]  floor was pressed.
 [ 6 ]  floor was pressed.
 [ 10 ] floor was pressed.
 [ 6 ]  floor was pressed.
 [ 8 ]  floor was pressed.
Elevator will stop at floor 3
Elevator will stop at floor 6
Elevator will stop at floor 7
Elevator will stop at floor 8
Elevator will stop at floor 10
Elevator will stop at floor 12
Elevator will stop at floor 14

The value of AX (base16): 2ae4

Welcome to the Sheraton Hotel in Irvine.
This hotel is a 16 floor building.
10 people have entered the elevator.

 [ 2 ]  floor was pressed.
 [ 7 ]  floor was pressed.
 [ 7 ]  floor was pressed.
 [ 14 ] floor was pressed.
 [ 7 ]  floor was pressed.
 [ 3 ]  floor was pressed.
 [ 4 ]  floor was pressed.
 [ 11 ] floor was pressed.
 [ 7 ]  floor was pressed.
 [ 4 ]  floor was pressed.
Elevator will stop at floor 2
Elevator will stop at floor 3
Elevator will stop at floor 4
Elevator will stop at floor 7
Elevator will stop at floor 11
Elevator will stop at floor 14

The value of AX (base16): 244e
*/