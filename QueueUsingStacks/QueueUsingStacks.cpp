#include <iostream>
#include <stack>

using namespace std;

class MyQueue
{
public:
	MyQueue()
		: m_stack1(), m_stack2() {}

	void push(int x)
	{
		m_stack1.push(x);
	}
	int pop()
	{
		if (m_stack1.empty())
		{
			return NULL;
		}
		int head = m_stack1.top();
		m_stack1.pop();
		return head;
	}
	int peek() {
		if (m_stack1.empty() && m_stack2.empty())
		{
			return -1;
		}

		if (m_stack2.empty())
		{
			while (!m_stack1.empty())
			{
				m_stack2.push(m_stack1.top());
				m_stack1.pop();
			}
		}

		int frontElement = m_stack2.top();

		return frontElement;
	}
	bool empty()
	{
		return m_stack1.empty();
	}
private:
	stack<int> m_stack1;
	stack<int> m_stack2;
};

int main()
{
	std::cout << "Hello World!\n";
}
