#include "CIterator.h"
#include "CList.h"
#include "ConstCIterator.h"
#include "ConstReverseCIterator.h"
#include "ReverseCIterator.h"
#include <algorithm>
#include <iostream>
#include <stdexcept>

CList::CList()
	:m_front(nullptr)
	, m_back(nullptr)
	, m_size(0)
{
}

CList::CList(const std::string& value)
	:m_front(nullptr)
	, m_back(nullptr)
	, m_size(0)
{
	try
	{
		m_front = new Node(value);
		m_back = m_front;
		m_size = 1;
	}
	catch (...)
	{
		delete m_front;
		m_front = nullptr;
		m_back = nullptr;
		m_size = 0;
		throw;
	}
}

CList::CList(const CList& other)
	: m_front(nullptr)
	, m_back(nullptr)
	, m_size(0)
{
	if (other.m_size > 0)
	{
		Node* current = other.m_front;
		Node* temp = nullptr;
		try
		{
			while (current != nullptr)
			{
				PushBack(current->item);
				temp = current;
				current = current->next;
			}
		}
		catch (...)
		{
			while (temp != nullptr)
			{
				Node* toDelete = temp;
				temp = temp->prev;
				delete toDelete;
			}
			m_front = nullptr;
			m_back = nullptr;
			m_size = 0;
			throw;
		}
	}
}

CList::CList(CList&& other) noexcept
	: m_front(other.m_front)
	, m_back(other.m_back)
	, m_size(other.m_size)
{
	if (this != &other)
	{
		other.m_front = nullptr;
		other.m_back = nullptr;
		other.m_size = 0;
	}
}

CList::~CList() noexcept
{
	Clear();
}

CList& CList::operator=(const CList& other)
{
	if (this != &other)
	{
		CList temp(other);
		std::swap(m_front, temp.m_front);
		std::swap(m_back, temp.m_back);
		std::swap(m_size, temp.m_size);
	}
	return *this;
}

CList& CList::operator=(CList&& other) noexcept
{
	if (this != &other)
	{
		Clear();
		m_front = other.m_front;
		m_back = other.m_back;
		m_size = other.m_size;
		other.m_front = nullptr;
		other.m_back = nullptr;
		other.m_size = 0;
	}
	return *this;
}

void CList::Clear()
{
	Node* current = m_back;
	while (current != nullptr)
	{
		Node* temp = current;
		current = current->next;
		temp->prev = nullptr;
		temp->next = nullptr;
	}
	delete m_front;
	delete m_back;
	m_size = 0;
}

bool CList::IsEmpty() const
{
	return m_size == 0;
}

int CList::GetSize() const
{
	return m_size;
}

std::string const& CList::GetBack() const
{
	if (IsEmpty())
	{
		throw std::out_of_range("List is empty");
	}
	return m_back->item;
}

std::string const& CList::GetFront() const
{
	if (IsEmpty())
	{
		throw std::out_of_range("List is empty");
	}
	return m_front->item;
}

void CList::PushBack(const std::string& value)
{
	try
	{
		Node* newNode = new Node(value);
		if (IsEmpty())
		{
			m_front = m_back = newNode;
		}
		else
		{
			newNode->prev = m_back;
			m_back->next = newNode;
			m_back = newNode;
		}
		++m_size;
	}
	catch (std::bad_alloc& e)
	{
		std::cerr << "Allocation failed: " << e.what() << std::endl;
		throw;
	}
}

void CList::PushFront(const std::string& value)
{
	try
	{
		Node* newNode = new Node(value);
		if (IsEmpty())
		{
			m_front = m_back = newNode;
		}
		else
		{
			newNode->next = m_front;
			m_front->prev = newNode;
			m_front = newNode;
		}
		++m_size;
	}
	catch (std::bad_alloc& e)
	{
		std::cerr << "Allocation failed: " << e.what() << std::endl;
		throw;
	}
}

void CList::PopBack()
{
	if (IsEmpty())
	{
		throw std::out_of_range("List is empty");
	}
	Node* temp = m_back;
	if (m_back->prev)
	{
		m_back = m_back->prev;
		m_back->next = nullptr;
	}
	else
	{
		m_front = nullptr;
		m_back = nullptr;
	}
	delete temp;
	--m_size;
}

void CList::PopFront()
{
	if (IsEmpty())
	{
		throw std::out_of_range("List is empty");
	}
	Node* temp = m_front;
	if (m_front->next)
	{
		m_front = m_front->next;
		m_front->prev = nullptr;
	}
	else
	{
		m_front = nullptr;
		m_back = nullptr;
	}
	delete temp;
	--m_size;
}

void CList::Insert(CIterator pos, const std::string& value)
{
	try
	{
		Node* newNode = new Node(value);
		if (pos.m_node == nullptr)
		{
			if (m_back == nullptr)
			{
				m_front = m_back = newNode;
			}
			else
			{
				newNode->prev = m_back;
				m_back->next = newNode;
				m_back = newNode;
			}
		}
		else
		{
			newNode->next = pos.m_node;
			newNode->prev = pos.m_node->prev;
			if (pos.m_node->prev != nullptr)
			{
				pos.m_node->prev->next = newNode;
			}
			else
			{
				m_front = newNode;
			}
			pos.m_node->prev = newNode;
		}
		++m_size;
	}
	catch (std::bad_alloc& e)
	{
		std::cerr << "Allocation failed: " << e.what() << std::endl;
		throw;
	}
}

void CList::Erase(CIterator pos)
{
	if (pos.m_node == nullptr)
	{
		return;
	}
	if (pos.m_node->prev != nullptr)
	{
		pos.m_node->prev->next = pos.m_node->next;
	}
	else
	{
		m_front = pos.m_node->next;
	}
	if (pos.m_node->next != nullptr)
	{
		pos.m_node->next->prev = pos.m_node->prev;
	}
	else
	{
		m_back = pos.m_node->prev;
	}
	delete pos.m_node;
	--m_size;
}

CList::CIterator CList::begin()
{
	return CIterator(m_front);
}

CList::CIterator CList::end()
{
	return CIterator(nullptr);
}

CList::ConstCIterator CList::begin() const
{
	return ConstCIterator(m_front);
}

CList::ConstCIterator CList::end() const
{
	return ConstCIterator(nullptr);
}

CList::ReverseCIterator CList::rbegin()
{
	return ReverseCIterator(m_back);
}

CList::ReverseCIterator CList::rend()
{
	return ReverseCIterator(nullptr);
}

CList::ConstReverseCIterator CList::rbegin() const
{
	return ConstReverseCIterator(m_back);
}

CList::ConstReverseCIterator CList::rend() const
{
	return ConstReverseCIterator(nullptr);
}