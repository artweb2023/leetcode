#include <iostream>
#include <stack>

using namespace std;

bool checkValidString(string s)
{
	stack<int> open, star;
	for (int i = 0; i < s.length(); i++)
	{
		if (s[i] == '(')
		{
			open.push(i);
		}
		else if (s[i] == '*')
		{
			star.push(i);
		}
		else
		{
			if (!open.empty())
			{
				open.pop();
			}
			else if (!star.empty())
			{
				star.pop();
			}
			else
			{
				return false;
			}
		}
	}
	while (!open.empty() && !star.empty())
	{
		if (open.top() > star.top())
		{
			return false;
		}
		open.pop();
		star.pop();
	}

	return open.empty();
}

int main()
{
	std::string str;
	std::cin >> str;
	cout << checkValidString(str);
}