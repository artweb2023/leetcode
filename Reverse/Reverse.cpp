#include <iostream>

using namespace std;


int ReverceNumber(int num)
{
	int result = 0;
	while (num > 0)
	{
		int digit = num % 10;
		result = result * 10 + digit;
		num /= 10;
	}

	return result;
}

int main()
{
	int num;
	cin >> num;
	cout << ReverceNumber(num);
}


