/*
*Given a signed 32-bit integer x, return x with its digits reversed. If reversing x causes the value to go outside the signed
32-bit integer range [-231, 231 - 1], then return 0.
*/

#include <iostream>
#include <string>

using namespace std;

int reverse(int x)
{
	int reversed = 0;
	while (x != 0)
	{
		int digit = x % 10;
		x /= 10;
		if (reversed > INT_MAX / 10 || (reversed == INT_MAX / 10 && digit > 7) ||
			reversed < INT_MIN / 10 || (reversed == INT_MIN / 10 && digit < -8))
		{
			return 0;
		}
		reversed = reversed * 10 + digit;
	}
	return reversed;
}



int main()
{
	int x = 0;
	cin >> x;
	cout << reverse(x);
}