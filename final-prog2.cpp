// Benjamin Chu - CMPS371 - Assembly Language
// 1/27/2013 - Final Exam - Program 2
#include <iostream>
using namespace std;
// Not sure why 2-dimensional array is not working :(
// int students[4][2] = { {33, 31}, {23, 22}, {20, 23}, {18, 31} };
int students[8] = { 33, 31, 23, 22, 20, 23, 18, 31 };
int maleNum, femaleNum, i, freshTotal, sophTotal, juniorTotal, seniorTotal, maximum = 0, minimum = 100;

// Finding the total number of Male students
void findMale() {
	_asm {
		mov		maleNum, 0
		mov		ebx, 0
		mov		i, 1				// init values
	forloop1:
		cmp		i, 4				// i < 4 cont
		jg		Done1				// if not jmp to Done1
		mov		eax, [students + ebx]	// eax = [shirt + ebx]
		add		maleNum, eax			// total = total + eax
		add		ebx, 8				// ebx = ebx + 8
		inc		i					// ++i
		jmp		forloop1
	Done1:
	}
}

// Finding the total number of Female students
void findFemale() {
	_asm {
		mov		femaleNum, 0
		mov		ebx, 4
		mov		i, 1				// init values
	forloop1:
		cmp		i, 4				// i < 4 cont
		jg		Done1				// if not jmp to Done1
		mov		eax, [students + ebx]	// eax = [shirt + ebx]
		add		femaleNum, eax			// total = total + eax
		add		ebx, 8				// ebx = ebx + 8
		inc		i					// ++i
		jmp		forloop1
	Done1:
	}
}

// Output for more FEMALE students in the program
void printFemale() {
	cout << "There are more FEMALE students in the CMPS program." << endl;
}


// Output for more MALE students in the program
void printMale() {
	cout << "There are more MALE students in the CMPS program." << endl;
}

// Output if MALE and FEMALE students are equal
void printEqual() {
	cout << "There are an equal number of MALE and FEMALE students in the CMPS program." << endl;
}

// Calculating the total number of Freshman students
void freshCalc() {
	_asm {
		mov		freshTotal, 0
		mov		ebx, 0
		mov		i, 1				// init values
	forloop1:
		cmp		i, 2				// i < 4 cont
		jg		Done1				// if not jmp to Done1
		mov		eax, [students + ebx]	// eax = [shirt + ebx]
		add		freshTotal, eax			// total = total + eax
		add		ebx, 4				// ebx = ebx + 8
		inc		i					// ++i
		jmp		forloop1
	Done1:
	}
}

// Calculating the total number of Sophomore students
void sophCalc() {
	_asm {
		mov		sophTotal, 0
		mov		ebx, 8
		mov		i, 1				// init values
	forloop1:
		cmp		i, 2				// i < 4 cont
		jg		Done1				// if not jmp to Done1
		mov		eax, [students + ebx]	// eax = [shirt + ebx]
		add		sophTotal, eax			// total = total + eax
		add		ebx, 4				// ebx = ebx + 8
		inc		i					// ++i
		jmp		forloop1
	Done1:
	}
}

// Calculating the total number of Junior Students
void juniorCalc() {
	_asm {
		mov		juniorTotal, 0
		mov		ebx, 16
		mov		i, 1				// init values
	forloop1:
		cmp		i, 2				// i < 4 cont
		jg		Done1				// if not jmp to Done1
		mov		eax, [students + ebx]	// eax = [shirt + ebx]
		add		juniorTotal, eax			// total = total + eax
		add		ebx, 4				// ebx = ebx + 8
		inc		i					// ++i
		jmp		forloop1
	Done1:
	}
}

// Calculating the total number of senior students
void seniorCalc() {
	_asm {
		mov		seniorTotal, 0
		mov		ebx, 24
		mov		i, 1				// init values
	forloop1:
		cmp		i, 2				// i < 4 cont
		jg		Done1				// if not jmp to Done1
		mov		eax, [students + ebx]	// eax = [shirt + ebx]
		add		seniorTotal, eax			// total = total + eax
		add		ebx, 4				// ebx = ebx + 8
		inc		i					// ++i
		jmp		forloop1
	Done1:
	}
}

// Compaing freshman totals with min max
void freshMinMax() {
	_asm {
		mov		eax, freshTotal
		cmp		eax, maximum;	// if (number > maximum)
		jng		NotMax;
		mov		maximum, eax;	// setting maximum
	NotMax:
		cmp		eax, minimum;	// if (number < minimum)
		jnl		NotMin;
		mov		minimum, eax;	// setting minimum
	NotMin:
	}
}

// Compaing sophomore totals with min max
void sophMinMax() {
	_asm {
		mov		eax, sophTotal
		cmp		eax, maximum;	// if (number > maximum)
		jng		NotMax;
		mov		maximum, eax;	// setting maximum
	NotMax:
		cmp		eax, minimum;	// if (number < minimum)
		jnl		NotMin;
		mov		minimum, eax;	// setting minimum
	NotMin:
	}
}

// Compaing junior totals with min max
void juniorMinMax() {
	_asm {
		mov		eax, juniorTotal
		cmp		eax, maximum;	// if (number > maximum)
		jng		NotMax;
		mov		maximum, eax;	// setting maximum
	NotMax:
		cmp		eax, minimum;	// if (number < minimum)
		jnl		NotMin;
		mov		minimum, eax;	// setting minimum
	NotMin:
	}
}

// Compaing senior totals with min max
void seniorMinMax() {
	_asm {
		mov		eax, seniorTotal
		cmp		eax, maximum;	// if (number > maximum)
		jng		NotMax;
		mov		maximum, eax;	// setting maximum
	NotMax:
		cmp		eax, minimum;	// if (number < minimum)
		jnl		NotMin;
		mov		minimum, eax;	// setting minimum
	NotMin:
	}
}

// Output functions for Majority of the students
void printFresh() {
	cout << "Majority of the students are FRESHMAN." << endl;
}
void printSoph() {
	cout << "Majority of the students are SOPHOMORE." << endl;
}
void printJunior() {
	cout << "Majority of the students are JUNIOR." << endl;
}
void printSenior() {
	cout << "Majority of the students are SENIOR." << endl;
}

int main() {
	// Part (i), figuring out if there are more males than females
	// in the department.
	_asm {
		call	findMale
		call	findFemale
		mov		ebx, maleNum
		mov		ecx, femaleNum
		cmp		ebx, ecx
		jne		CHECK
		call	printEqual
		jmp		Exit
	CHECK:
		cmp		ebx, ecx
		jg		MOREMALE
		call	printFemale
		jmp		Exit
	MOREMALE:
		call	printMale
		jmp		Exit
	Exit:
	}

	// Part (ii), figuring out which classification has the most students
	_asm {
		call	freshCalc
		call	sophCalc
		call	juniorCalc
		call	seniorCalc
		call	freshMinMax
		call	sophMinMax
		call	juniorMinMax
		call	seniorMinMax
		mov		eax, freshTotal
		cmp		maximum, eax
		jne		SOPHCHECK
		call	printFresh
		jmp		End
	SOPHCHECK:
		mov		eax, sophTotal
		cmp		maximum, eax
		jne		JUNIORCHECK
		call	printSoph
		jmp		End
	JUNIORCHECK:
		mov		eax, juniorTotal
		cmp		maximum, eax
		jne		SENIORCHECK
		call	printJunior
		jmp		End
	SENIORCHECK:
		call	printSenior
		jmp		End	

		End:
	}
	system("pause");
	return 0;
}
/* Output
There are more FEMALE students in the CMPS program.
Majority of the students are FRESHMAN.
*/