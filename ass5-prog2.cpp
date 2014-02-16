/*===============================================
CMPS371 - Project/Assignment No. 5 - Homework
Program 2
===============================================*/
#include <iostream>
#include <string>
using namespace std;
int age, membership;
string name;
char gender;

void GreetingMale() {
	cout << "Mr. " << name;
	cout << ", how old are you: ";
	cin >> age;
	_asm {
		cmp		age, 19;
		jng		Teen;
		mov		membership, 150;
		jmp		End;
	Teen:
		cmp		age, 13;
		jnge	Child;
		mov		membership, 100;
		jmp		End;
	Child:
		mov	membership, 0;
	End:
	}
	cout << "Mr. Your membership is $" << dec << membership << endl;
}

void GreetingFemale() {
	cout << "Ms. " << name;
	cout << ", how old are you: ";
	cin >> age;
	_asm {
		cmp		age, 19;
		jng		Teen;
		mov		membership, 170;
		jmp		End;
	Teen:
		cmp		age, 13;
		jnge	Child;
		mov		membership, 120;
		jmp		End;
	Child:
		mov	membership, 0;
	End:
	}
	cout << "Ms. Your membership is $" << dec << membership << endl;
}

int main() {
	cout << "/=============ULV Fitness=============/\n";
	cout << " Male\n";
	cout << "\tAdults ............... $150.00\n";
	cout << "\tTeenagers ............ $100.00\n";
	cout << "\tChildren ............. FREE\n";
	cout << " Female\n";
	cout << "\tAdults ............... $170.00\n";
	cout << "\tTeenagers ............ $120.00\n";
	cout << "\tChildren ............. FREE\n";
	
	cout << "\nEnter your Name and Gender: ";
	cin >> name; cin >> gender;
	
	_asm {
		cmp		gender, 'M';
		je		Male;
		cmp		gender, 'm';
		je		Male;
		cmp		gender, 'F';
		je		Female;
		cmp		gender, 'f';
		je		Female;
		jmp		Done;
	Male:
		call	GreetingMale;
		jmp		Done;
	Female:
		call	GreetingFemale;
		jmp		Done;
	Done:
	}

	system("pause");
	return 0;
}
/* Output


*/