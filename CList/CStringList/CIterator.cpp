#include "CIterator.h"

CList::CIterator::CIterator(Node* node)
	: m_node(node)
{
}

std::string& CList::CIterator::operator*() const
{
	return m_node->item;
}

std::string* CList::CIterator::operator->() const
{
	return &m_node->item;
}

CList::CIterator& CList::CIterator::operator++()
{
	m_node = m_node->next;
	return *this;
}

CList::CIterator CList::CIterator::operator++(int)
{
	CIterator temp = *this;
	m_node = m_node->next;
	return temp;
}

CList::CIterator& CList::CIterator::operator--()
{
	m_node = m_node->prev;
	return *this;
}

CList::CIterator CList::CIterator::operator--(int)
{
	CIterator temp = *this;
	m_node = m_node->prev;
	return temp;
}

bool CList::CIterator::operator==(const CIterator& other) const
{
	return m_node == other.m_node;
}

bool CList::CIterator::operator!=(const CIterator& other) const
{
	return m_node != other.m_node;
}
