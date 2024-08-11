#pragma once
#include "CList.h"

class CList::ReverseCIterator
{
public:
	ReverseCIterator() = default;
	explicit ReverseCIterator(Node* node = nullptr);

	std::string& operator*() const;
	std::string* operator->() const;

	ReverseCIterator& operator++();
	ReverseCIterator operator++(int);
	ReverseCIterator& operator--();
	ReverseCIterator operator--(int);

	bool operator==(const ReverseCIterator& other) const;
	bool operator!=(const ReverseCIterator& other) const;

private:
	Node* m_node;
	friend class CList;
};