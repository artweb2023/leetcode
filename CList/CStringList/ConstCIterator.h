#pragma once
#include "CList.h"

class CList::ConstCIterator
{
public:
	ConstCIterator() = default;
	explicit ConstCIterator(const Node* node = nullptr);

	const std::string& operator*() const;
	const std::string* operator->() const;

	ConstCIterator& operator++();
	ConstCIterator operator++(int);
	ConstCIterator& operator--();
	ConstCIterator operator--(int);

	bool operator==(const ConstCIterator& other) const;
	bool operator!=(const ConstCIterator& other) const;

private:
	const Node* m_node;
	friend class CList;
};
