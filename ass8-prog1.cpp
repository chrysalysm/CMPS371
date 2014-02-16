/* Benjamin Chu - CMPS371 - Jan 2014
Assignment No. 8 - Program #1 */

#include <iostream>
#include <time.h>
using namespace std;
// declaring variables
int i = 0, random, output, total, maximum = 0, minimum = 100;
int a[7];
// generate random number < 50
void randNum() {
	random = rand() % 50;
}

void Display() {
	cout << "a[" << i << "] = " << output << endl;
}
// (ii) Defining the function to display array a
void DisplayArray() {
	_asm {
		mov		i, 0
		mov		ebx, 0			// init values
	forloop2:
		mov		edx, i
		cmp		edx, 7			// i < 7
		jge		Done1			// if not jmp to Done1
		mov		ecx, [a + ebx]	// ecx = [a + ebx]
		mov		output, ecx		// output = ecx
		call	Display
		add		ebx, 4			// ebx = ebx + 4
		inc		i				// ++i
		jmp		forloop2
	Done1:
	}
}

// (iii) Defining the function to find the average of all numbers
void AverageArray() {
	_asm {
		mov		i, 0
		mov		ebx, 0			// init values
	forloop2:
		mov		edx, i			
		cmp		edx, 7			// i < 7
		jge		Done2			// if not jmp to Done2
		mov		ecx, [a + ebx]	// ecx = [a + ebx]
		add		total, ecx		// total = total + ecx
		add		ebx, 4			// ebx = ebx + 4
		inc		i				// ++i
		jmp		forloop2
	Done2:
		mov		eax, total
		cdq
		idiv	i
		mov		total, eax
	}
}

// (iv) Defining the function to find the maximum and minimum numbers
void MaxMinArray() {
	_asm {
		mov		i, 0
		mov		ebx, 0			// init values
	forloop3:
		mov		edx, i
		cmp		edx, 7
		jge		Done3
		mov		ecx, [a + ebx]	// ecx = [a + ebx]
		cmp		maximum, ecx	// if max < ecx
		jnl		Min				// if not jmp Min
		mov		maximum, ecx	// max = ecx
	Min:
		mov		ecx, [a + ebx]	// ecx = [a + ebx]
		cmp		minimum, ecx	// if min > ecx
		jng		Exit			// if not jmp Exit
		mov		minimum, ecx	// min = ecx
	Exit:
		add		ebx, 4			// ebx = ebx + 4
		inc		i				// ++i
		jmp		forloop3
	Done3:
	}
}

int main() {
	srand(time(NULL));
	
	_asm {
		mov		ebx, 0
	forloop1:				// (i) Reading 7 random integers into array a
		mov		edx, i
		cmp		edx, 7
		jge		Done
		call	randNum		// Calling random number generator function
		mov		ecx, random	// ecx = random number
		mov		[a + ebx], ecx	// [a + ebx] = ecx = random number
		add		ebx, 4		// ebx = ebx + 4
		inc		i			// ++i
		jmp		forloop1	// jmp back to forloop1
	Done:
		call DisplayArray	// (ii) Calling function to display array a
		call AverageArray	// (iii) Calling function to find average of all numbers
		call MaxMinArray	// (iv) Call function to find max and min
	}
	cout << "Average: " << total << endl;
	cout << "Max: " << maximum << endl;
	cout << "Min: " << minimum << endl;
	system("pause");
	return 0;
}
/*
a[0] = 44
a[1] = 39
a[2] = 16
a[3] = 31
a[4] = 43
a[5] = 20
a[6] = 41
Average: 33
Max: 44
Min: 16
*/