#include <iostream>
#include <vector>


class Solution {
public:
	void reverseString(std::vector<char>& s) {
		for (int i = 0, j = s.size() - 1; i < j; ++i, --j)
		{
			s[i] ^= s[j] ^= s[i] ^= s[j];
		}
		for (auto ch : s)
		{
			std::cout << ch;
		}
		std::cout << std::endl;
	}
};

int main()
{
	Solution solution;
	std::vector<char> s{ 'h', 'e', 'l', 'l', 'o' };
	solution.reverseString(s);
}

