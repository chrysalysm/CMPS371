// Benjamin Chu - CMPS371 - Exam 2 - Jan 2014
// Program #4 - 24 Hour Fitness
#include <iostream>
#include <string>
#include <iomanip>

using namespace std;
int age, membership, number, i = 0;
string name;
char gender;

void GreetingMale() {
	cout << "Mr. " << name;
	cout << ", how old are you: ";
	cin >> age;
	_asm {
		cmp		age, 19;			// if (age > 19)
		jng		Teen;				// if not jump to Teen
		mov		membership, 150;	// membership = 150
		jmp		End;
	Teen:
		cmp		age, 13;			// if (age > 13)
		jnge	Child;				// if not jump to Child
		mov		membership, 100;	// membership = 100
		jmp		End;
	Child:
		mov		membership, 0;		// membership = 0
	End:
	}
	if (membership == 0) {
		cout << "You can not be a member." << endl;
	}
	else {
		cout << "Ms. Your membership is $" << dec << membership << ".00" << endl;
	}
}

void GreetingFemale() {
	cout << "Ms. " << name;
	cout << ", how old are you: ";
	cin >> age;
	_asm {
		cmp		age, 19;			// if (age > 19)
		jng		Teen;				// if not jump to Teen
		mov		membership, 170;	// membership = 170
		jmp		End;
	Teen:
		cmp		age, 13;			// if (age > 13)
		jnge	Child;				// if not jump to Child
		mov		membership, 120;	// membership = 120
		jmp		End;
	Child:
		mov		membership, 0;		// membership = 0
	End:
	}
	if (membership == 0) {
		cout << "You can not be a member." << endl;
	}
	else {
		cout << "Ms. Your membership is $" << dec << membership << ".00" << endl;
	}
}

void CustomerInputNameGender() {
	cout << "\nEnter your Name and Gender: ";
	cin >> name; cin >> gender;
}

void CustomerInput() {
	_asm {
		call	CustomerInputNameGender;	// Calling user input
		cmp		gender, 'M';				// If gender = M or m, jump to label Male
		je		Male;
		cmp		gender, 'm';
		je		Male;
		cmp		gender, 'F';				// If gender = F or f, jump to lable Female
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
	cin.ignore();
}

int main() {
	cout << "/=============24 Hours Fitness=============/\n";
	cout << " Male\n";
	cout << "\tAdults ............... $150.00\n";
	cout << "\tTeenagers ............ $100.00\n";
	cout << " Female\n";
	cout << "\tAdults ............... $170.00\n";
	cout << "\tTeenagers ............ $120.00\n";
	cout << " Children Age <13 Are Not Accepted\n";
	cout << "\nEnter the number of customers: ";
	cin >> number;

	_asm {
	forloop:
		mov eax, number;	// eax = number
		cmp i, eax;			// if i = 0 < number
		jnl	Exit;			// jmp to Exit
		call CustomerInput;	// get customer input
		inc i;				// ++i
		jmp forloop;		// loop
	Exit:
	}
	system("pause");
	return 0;
}
/* Output

/=============24 Hours Fitness=============/
Male
Adults ............... $150.00
Teenagers ............ $100.00
Female
Adults ............... $170.00
Teenagers ............ $120.00
Children Age <13 Are Not Accepted

Enter the number of customers: 3

Enter your Name and Gender: John m
Mr. John, how old are you: 27
Ms. Your membership is $150.00

Enter your Name and Gender: Mary F
Ms. Mary, how old are you: 15
Ms. Your membership is $120.00

Enter your Name and Gender: Bill m
Mr. Bill, how old are you: 10
You can not be a member.

/=============24 Hours Fitness=============/
Male
Adults ............... $150.00
Teenagers ............ $100.00
Female
Adults ............... $170.00
Teenagers ............ $120.00
Children Age <13 Are Not Accepted

Enter the number of customers: 4

Enter your Name and Gender: Alison f
Ms. Alison, how old are you: 12
You can not be a member.

Enter your Name and Gender: Rena F
Ms. Rena, how old are you: 22
Ms. Your membership is $170.00

Enter your Name and Gender: Ben M
Mr. Ben, how old are you: 13
Ms. Your membership is $100.00

Enter your Name and Gender: Ray M
Mr. Ray, how old are you: 25
Ms. Your membership is $150.00
*/