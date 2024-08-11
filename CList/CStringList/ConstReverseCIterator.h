#pragma once
#include "CList.h"

class CList::ConstReverseCIterator
{
public:
	ConstReverseCIterator() = default;
	explicit ConstReverseCIterator(const Node* node = nullptr);

	const std::string& operator*() const;
	const std::string* operator->() const;

	ConstReverseCIterator& operator++();
	ConstReverseCIterator operator++(int);
	ConstReverseCIterator& operator--();
	ConstReverseCIterator operator--(int);

	bool operator==(const ConstReverseCIterator& other) const;
	bool operator!=(const ConstReverseCIterator& other) const;

private:
	const Node* m_node;
	friend class CList;
};
