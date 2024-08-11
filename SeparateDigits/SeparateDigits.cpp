#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	vector<int> separateDigits(vector<int>& nums) {
		vector<int> result;
		for (auto num : nums) {
			vector<int> temp;
			while (num > 0) {
				temp.push_back(num % 10);
				num /= 10;
			}
			for (int j = temp.size() - 1; j >= 0; --j) {
				result.push_back(temp[j]);
			}
		}
		return result;
	}

	void print(const vector<int>& nums) {
		for (auto digit : nums) {
			cout << digit << " ";
		}
		cout << "\n";
	}
};

int main() {
	vector<int> nums{ 7,1,3,9 };
	Solution digit;
	digit.print(digit.separateDigits(nums));
	return 0;
}