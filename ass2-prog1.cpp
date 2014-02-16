// Benjamin Chu - Assignment No. 2 - Program 1
#include <iostream>
using namespace std;

int main() {
	short width, height, perim, area;
//	int area;
	cout << "Enter the measure of width: ";
	cin >> width;
	cout << "Enter the measure of height: ";
	cin >> height;
	_asm {
		mov ax, width;
		mov bx, height;
		imul bx;
		mov area, ax;
	}
	cout << "Area = " << dec << area;
	_asm {
		mov ax, width;
		mov bx, height;
		add ax, width;
		add bx, height;
		add ax, bx;
		mov perim, ax;
	}
	cout << endl << "Perimeter = " << dec << perim << endl;
	system("pause");
	return 0;
}
/* Output
Enter the measure of width: 23
Enter the measure of height: 44
Area = 1012
Perimeter = 134
*/