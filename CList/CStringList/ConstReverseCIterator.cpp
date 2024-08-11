#include "ConstReverseCIterator.h"

CList::ConstReverseCIterator::ConstReverseCIterator(const Node* node)
	: m_node(node)
{
}

const std::string& CList::ConstReverseCIterator::operator*() const
{
	return m_node->item;
}

const std::string* CList::ConstReverseCIterator::operator->() const
{
	return &m_node->item;
}

CList::ConstReverseCIterator& CList::ConstReverseCIterator::operator++()
{
	m_node = m_node->prev;
	return *this;
}

CList::ConstReverseCIterator CList::ConstReverseCIterator::operator++(int)
{
	ConstReverseCIterator temp = *this;
	m_node = m_node->prev;
	return temp;
}

CList::ConstReverseCIterator& CList::ConstReverseCIterator::operator--()
{
	m_node = m_node->next;
	return *this;
}

CList::ConstReverseCIterator CList::ConstReverseCIterator::operator--(int)
{
	ConstReverseCIterator temp = *this;
	m_node = m_node->next;
	return temp;
}

bool CList::ConstReverseCIterator::operator==(const ConstReverseCIterator& other) const
{
	return m_node == other.m_node;
}

bool CList::ConstReverseCIterator::operator!=(const ConstReverseCIterator& other) const
{
	return m_node != other.m_node;
}