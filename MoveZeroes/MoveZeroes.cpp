#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

void moveZeroes(vector<int>& nums)
{
	std::stable_partition(nums.begin(), nums.end(), [](int num)
		{
			return num != 0;
		}
	);
}

int main()
{
	vector<int> nums = { 0,1,0,3,12 };
	moveZeroes(nums);
	for (auto num : nums)
	{
		cout << num << endl;
	}
}