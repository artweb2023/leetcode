#include "ConstCIterator.h"


CList::ConstCIterator::ConstCIterator(const Node* node)
	: m_node(node)
{
}

const std::string& CList::ConstCIterator::operator*() const
{
	return m_node->item;
}

const std::string* CList::ConstCIterator::operator->() const
{
	return &m_node->item;
}

CList::ConstCIterator& CList::ConstCIterator::operator++()
{
	m_node = m_node->next;
	return *this;
}

CList::ConstCIterator CList::ConstCIterator::operator++(int)
{
	ConstCIterator temp = *this;
	m_node = m_node->next;
	return temp;
}

CList::ConstCIterator& CList::ConstCIterator::operator--()
{
	m_node = m_node->prev;
	return *this;
}

CList::ConstCIterator CList::ConstCIterator::operator--(int)
{
	ConstCIterator temp = *this;
	m_node = m_node->prev;
	return temp;
}

bool CList::ConstCIterator::operator==(const ConstCIterator& other) const
{
	return m_node == other.m_node;
}

bool CList::ConstCIterator::operator!=(const ConstCIterator& other) const
{
	return m_node != other.m_node;
}