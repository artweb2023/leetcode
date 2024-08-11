/*
	You are given a large integer represented as an integer array digits, where each digits[i] is the ith digit of the integer.
	The digits are ordered from most significant to least significant in left-to-right order.
	The large integer does not contain any leading 0's.
	Increment the large integer by one and return the resulting array of digits.
*/

#include <algorithm>
#include <iostream>
#include <vector>


using namespace std;

vector<int> plusOne(vector<int>& digits) {
	int n = digits.size();
	digits[n - 1]++;
	for (int i = n - 1; i > 0 && digits[i] == 10; --i)
	{
		digits[i] = 0;
		digits[i - 1]++;
	}
	if (digits[0] == 10)
	{
		digits[0] = 0;
		digits.insert(digits.begin(), 1);
	}

	return digits;
}

int main()
{
	vector<int> numbers = { 7,2,8,5,0,9,1,2,9,5,3,6,6,7,3,2,8,4,3,7,9,5,7,7,4,7,4,9,4,7,0,1,1,1,7,4,0,0,6 };
	plusOne(numbers);
	for (auto num : numbers)
	{
		cout << num << " ";
	}
	cout << endl;
}

