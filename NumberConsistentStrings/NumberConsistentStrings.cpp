#include <iostream>
#include <string>
#include <vector>


using namespace std;

int countConsistentStrings(string allowed, vector<string>& words)
{
	int count = 0;
	int chCount = 0;
	for (int i = 0; i < words.size(); ++i)
	{
		for (int j = 0; j < words[i].length(); ++j)
		{
			if (allowed.find(words[i][j]) != string::npos)
			{
				chCount++;
			}
		}
		if (chCount == words[i].length())
		{
			count++;
		}
	}
	return count;
}

int main()
{
	vector<string> words = { "ad","bd","aaab","baa","badab" };
	string alloewd = "ab";
	cout << countConsistentStrings(alloewd, words) << endl;
}

