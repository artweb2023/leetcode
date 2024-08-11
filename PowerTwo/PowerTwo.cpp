#include <iostream>


/*
Given an integer n, return true if it is a power of two. Otherwise, return false.
An integer n is a power of two, if there exists an integer x such that n == 2x.
*/
using namespace std;

bool isPowerOfTwo(int n)
{
	if (n < 1)
	{
		return false;
	}
	while (n != 1)
	{
		if (n % 2 == 1)
		{
			return false;
		}
		n = n / 2;
	}
	return true;
}

int main()
{
	int num;
	cin >> num;
	cout << isPowerOfTwo(num) << endl;
}
