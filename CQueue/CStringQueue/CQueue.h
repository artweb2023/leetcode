#pragma once
#include <string>

class CQueue
{
public:
	CQueue();
	explicit CQueue(const std::string& str);
	~CQueue();
	int GetSize() const;
	std::string GetFront() const;
	std::string GetBack() const;
	bool IsEmpty() const;
	void Enqueue(const std::string& str);
	void Dequeue();
private:
	struct Node
	{
		std::string item;
		Node* next;
	};
	Node* m_front;
	Node* m_back;
	int m_size;
};
