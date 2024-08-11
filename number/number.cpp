#include <array>
#include <iostream>


int main()
{
	int num;
	std::cin >> num;
	int x = num / 4;
	std::array<int, 10> digits;
	while (num > 0)
	{
		digits[num % 10];
		num /= 10;
	}
	bool isPol = false;
	for (int i = 0, j = digits.size() - 1; i < j; i++, j--)
	{
		if (digits[i] == digits[j])
		{
			isPol = true;
		}
	}
	std::cout << isPol << std::endl;
}
