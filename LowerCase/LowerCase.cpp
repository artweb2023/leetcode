#include <algorithm>
#include <iostream>

class Solution {
public:
	std::string toLowerCase(std::string s) {
		std::transform(s.begin(), s.end(), s.begin(), [](unsigned char ch) {
			return tolower(ch);
			});
		return s;
	}
};


int main()
{
	Solution s;
	s.toLowerCase("Hello");
}

