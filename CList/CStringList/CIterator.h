#pragma once
#include "CList.h"

class CList::CIterator
{
public:
	CIterator() = default;
	explicit CIterator(Node* node = nullptr);

	std::string& operator*() const;
	std::string* operator->() const;

	CIterator& operator++();
	CIterator operator++(int);
	CIterator& operator--();
	CIterator operator--(int);

	bool operator==(const CIterator& other) const;
	bool operator!=(const CIterator& other) const;

private:
	Node* m_node;
	friend class CList;
};