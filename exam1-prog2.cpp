/*
Benjamin Chu - CMPS371 Assembly Language - Jan 2014
Exam No. 1 - Part 2 - Program #2
*/
#include <iostream>
using namespace std;

int main() {

	short base, height, radius, areacircle, areatriangle, PI = 3, TWO = 2;
	cout << "This program calculates the area of a circle and triangle.\n";
	cout << "\tEnter the radius of a circle: "; cin >> radius;
	cout << "\tEnter the base and the height of a triangle: "; cin >> base; cin >> height;

	// calculating circle area = PI*(radius*radius)
	_asm {
		mov		ax, radius		// ax = radius
		imul	radius			// ax = radius * radius
		imul	PI				// ax = (radius * radius) * PI
		mov		areacircle, ax	// areacircle = ax = (radius * radius) * PI
	}
	cout << "Area of circle is " << dec << areacircle << endl;

	// calculating triangle area = (base * height)/TWO
	_asm {
		mov		ax, base			// ax = base
		imul	height				// ax = base * height
		idiv	TWO					// ax = (base * height) / 2
		mov		areatriangle, ax	// areatriangle = ax = (base * height) / 2
	}
	cout << "Area of triangle is " << dec << areatriangle << endl;
	system("pause");
	return 0;
}
/* Output
This program calculates the area of a circle and triangle.
        Enter the radius of a circle: 10
        Enter the base and the height of a triangle: 8 13
Area of circle is 300
Area of triangle is 52

This program calculates the area of a circle and triangle
        Enter the radius of a circle: 5
        Enter the base and the height of a triangle: 5 18
Area of circle is 75
Area of triangle is 45
*/
