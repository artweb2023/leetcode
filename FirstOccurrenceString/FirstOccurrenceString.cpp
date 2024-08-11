#include <iostream>

using namespace std;

class Solution {
public:
	int strStr(string haystack, string needle) {
		int n = haystack.find(needle);
		if (n == string::npos)
		{
			return -1;
		}
		return n;
	}
};

int main()
{
	Solution solution;
	std::string haystack = "leetcode";
	std::string needle = "leeto";
	std::cout << solution.strStr(haystack, needle);
}

