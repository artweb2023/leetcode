#include <iostream>
#include <sstream>
#include <string>
#include <vector>

int lengthOfLastWord(std::string s)
{
	std::vector<std::string> words;
	std::string word;
	std::istringstream str(s);
	while (str >> word)
	{
		words.push_back(word);
	}
	return words[words.size() - 1].length();
}

int main()
{
	std::string s = "Hello World";
	lengthOfLastWord(s);
}
