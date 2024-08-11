#include <algorithm>
#include <algorithm>
#include <ctype.h>
#include <iostream>
#include <string>

bool isPalindrome(std::string s)
{
	std::string str;
	std::copy_if(s.begin(), s.end(), std::back_inserter(str),
		[](unsigned ch) { return !std::isspace(ch) && !std::ispunct(ch); });
	std::transform(str.begin(), str.end(), str.begin(), [](unsigned char ch) {
		return tolower(ch);
		});
	std::string str1 = str;
	std::reverse(str1.begin(), str1.end());
	if (str1 == str)
	{
		return true;
	}
	return false;
}

int main()
{
	std::string str = "A man, a plan, a canal: Panama";
	std::cout << isPalindrome(str);
	return 0;
}
