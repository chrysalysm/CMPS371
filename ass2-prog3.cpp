// Benjamin Chu - Assignment No. 2 - Program 3
#include <iostream>
using namespace std;

int main() {
	int number, sum;
	cout << "Enter a three digit int number: ";
	cin >> number;
	int HUNDRED = 100, TEN = 10;
	_asm {
		mov eax, number;
		cdq
		idiv HUNDRED; // ax = q  dx = r
		mov ebx, eax;
		mov eax, edx;
		cdq
		idiv TEN;
		add ebx, eax;
		add ebx, edx;
		mov sum, ebx;
	}
	cout << "Sum of digits in " << number << " is " << dec << sum << endl;
	system("pause");
	return 0;
}
/* Output
Enter a three digit int number: 362
Sum of digits in 362 is 11
*/