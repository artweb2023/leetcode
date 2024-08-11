#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	bool containsDuplicate(vector<int>& nums) {
		sort(nums.begin(), nums.end());
		for (int i = 0; i < nums.size() - 1; i++)
		{
			if (nums[i] == nums[i + 1])
			{
				return true;
			}
		}
		return false;
	}
};

int main() {
	Solution solution;
	vector<int> nums{ 1,2,4 };
	std::cout << solution.containsDuplicate(nums);
	return 0;
}