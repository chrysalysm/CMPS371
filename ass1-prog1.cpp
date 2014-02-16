//============================================================================
// Name        : ass1.cpp
// Author      : Benjamin Chu
// Version     :
// Copyright   : Creative Commons - Attribution 3.0
// Description : Adding and Moving in Assembly
//============================================================================

#include <iostream>
using namespace std;
int main() {
	int width, length, a, b, c, perimeter;
	cout << endl;
	cout << " ================              /\\ \n";
	cout << " |              |             /  \\ \n";
	cout << " |              | Width    a /    \\ c \n";
	cout << " |              |           /      \\ \n";
	cout << " ================           --------  \n";
	cout << "      Length                    b\n";
	cout << "\nEnter the values of width and length: ";
	cin >> width; cin >> length;
	cout << "Enter the values of sides a, b, and c: ";
	cin >> a; cin >> b; cin >> c;

	asm ("movl %%ax, %%cx;\n"
		 "addl %%cx, %%ax;\n"
		 "addl %%bx, %%ax;\n"
		 "addl %%bx, %%ax;\n"
		: "=a"(perimeter) : "a"(width), "b"(length));
	cout << "The perimeter of rectangle is: " << dec << perimeter;

	asm ("addl %%cx, %%ax;\n"
		 "addl %%bx, %%ax;\n"
		: "=a"(perimeter) : "a"(a), "b"(b), "c"(c));
	cout << "\nThe perimeter of triangle is: " << dec << perimeter;
	cout << "\n\n";

	return 0;
}

/* OUTPUT

performa:~ milkmandan$ /Volumes/Quartet/CMPS371/Assignment1/ass1 

 ================              /\ 
 |              |             /  \ 
 |              | Width    a /    \ c 
 |              |           /      \ 
 ================           --------  
      Length                    b

Enter the values of width and length: 5 10
Enter the values of sides a, b, and c: 7 6 10
The perimeter of rectangle is: 30
The perimeter of triangle is: 23

performa:~ milkmandan$ 

*/