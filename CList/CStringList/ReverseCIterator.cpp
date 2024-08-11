#include "ReverseCIterator.h"

CList::ReverseCIterator::ReverseCIterator(Node* node)
	: m_node(node)
{
}

std::string& CList::ReverseCIterator::operator*() const
{
	return m_node->item;
}

std::string* CList::ReverseCIterator::operator->() const
{
	return &m_node->item;
}

CList::ReverseCIterator& CList::ReverseCIterator::operator++()
{
	m_node = m_node->prev;
	return *this;
}

CList::ReverseCIterator CList::ReverseCIterator::operator++(int)
{
	ReverseCIterator temp = *this;
	m_node = m_node->prev;
	return temp;
}

CList::ReverseCIterator& CList::ReverseCIterator::operator--()
{
	m_node = m_node->next;
	return *this;
}

CList::ReverseCIterator CList::ReverseCIterator::operator--(int)
{
	ReverseCIterator temp = *this;
	m_node = m_node->next;
	return temp;
}

bool CList::ReverseCIterator::operator==(const ReverseCIterator& other) const
{
	return m_node == other.m_node;
}
bool CList::ReverseCIterator::operator!=(const ReverseCIterator& other) const
{
	return m_node != other.m_node;
}