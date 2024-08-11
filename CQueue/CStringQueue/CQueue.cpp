#include "CQueue.h"

CQueue::CQueue()
	:m_front(nullptr)
	, m_back(nullptr)
	, m_size(0)
{
}

CQueue::CQueue(const std::string& str)
	: m_front(new Node{ str,nullptr })
	, m_back(m_front)
	, m_size(1)
{
}

CQueue::~CQueue()
{
	Node* temp;
	while (m_front != nullptr)
	{
		temp = m_front;
		m_front = m_front->next;
		delete temp;
	}
}

std::string CQueue::GetFront() const {
	return m_front != nullptr ? m_front->item : "";
}

std::string CQueue::GetBack() const {
	return m_back != nullptr ? m_back->item : "";
}


int CQueue::GetSize() const
{
	return m_size;
}

bool CQueue::IsEmpty() const
{
	return m_size == 0;
}

void CQueue::Enqueue(const std::string& str)
{
	Node* newNode = new Node{ str,nullptr };
	if (m_back != nullptr)
	{
		m_back->next = newNode;
	}
	m_back = newNode;
	++m_size;
};

void CQueue::Dequeue()
{
	if (m_size == 0)
	{
		return;
	}
	Node* temp = m_front;
	m_front = m_front->next;
	delete temp;
	--m_size;
};