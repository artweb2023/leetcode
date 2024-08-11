/*
Implement a last-in-first-out (LIFO) stack using only two queues. The implemented stack should support
all the functions of a normal stack (push, top, pop, and empty).
Implement the MyStack class:
void push(int x) Pushes element x to the top of the stack.
int pop() Removes the element on the top of the stack and returns it.
int top() Returns the element on the top of the stack.
boolean empty() Returns true if the stack is empty, false otherwise.
Notes:

You must use only standard operations of a queue, which means that only push to back, peek/pop from front, size and is empty operations are valid.
Depending on your language, the queue may not be supported natively. You may simulate a queue using a
list or deque (double-ended queue) as long as you use only a queue's standard operations.
*/


#include <iostream>
#include <queue>

using namespace std;

class MyStack {
public:
	MyStack()
		: m_queue1(), m_queue2() {}

	void push(int x) {
		m_queue1.push(x);
	}

	int pop() {
		if (m_queue1.empty())
			return NULL;

		while (m_queue1.size() > 1) {
			m_queue2.push(m_queue1.front());
			m_queue1.pop();
		}

		int top = m_queue1.front();
		m_queue1.pop();

		swap(m_queue1, m_queue2);

		return top;
	}

	int top() {
		if (m_queue1.empty())
			return NULL;

		while (m_queue1.size() > 1) {
			m_queue2.push(m_queue1.front());
			m_queue1.pop();
		}

		int top = m_queue1.front();
		m_queue2.push(top);
		m_queue1.pop();

		swap(m_queue1, m_queue2);

		return top;
	}

	bool empty() {
		return m_queue1.empty();
	}

private:
	queue<int> m_queue1;
	queue<int> m_queue2;
};


int main()
{
	std::cout << "Hello World!\n";
}

