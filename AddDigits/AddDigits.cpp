/*  Given an integer num, repeatedly add all its digits until the result has only one digit, and return it.*/
#include <iostream>

using namespace std;

int addDigits(int num) {
	if (num == 0) return 0;
	int remainder = num % 9;
	return (remainder == 0) ? 9 : remainder;
}

int main()
{
	int num;
	cin >> num;
	cout << addDigits(num) << endl;
}

