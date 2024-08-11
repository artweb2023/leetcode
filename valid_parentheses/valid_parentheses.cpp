#include <iostream>
#include <stack>

bool isValid(std::string s) {
	std::stack<char> stack;
	for (int i = 0; i < s.length(); ++i) {
		if (s[i] == '(' || s[i] == '[' || s[i] == '{') {
			stack.push(s[i]);
		}
		else if (s[i] == ')') {
			if (stack.empty() || stack.top() != '(') {
				return false;
			}
			stack.pop();
		}
		else if (s[i] == ']') {
			if (stack.empty() || stack.top() != '[') {
				return false;
			}
			stack.pop();
		}
		else if (s[i] == '}') {
			if (stack.empty() || stack.top() != '}') {
				return false;
			}
			stack.pop();
		}
	}
	return stack.empty();
}

int main()
{
	std::string str;
	std::cin >> str;
	std::cout << isValid(str) << std::endl;
}
