#pragma once
#include <string>

class CList
{
public:
	CList();
	explicit CList(const std::string& value);
	CList(const CList& other);
	CList(CList&& other) noexcept;
	~CList() noexcept;
	CList& operator=(const CList& other);
	CList& operator=(CList&& other) noexcept;
	class CIterator;
	class ConstCIterator;
	class ReverseCIterator;
	class ConstReverseCIterator;
	bool IsEmpty() const;
	int	GetSize() const;
	void Clear();
	std::string const& GetBack() const;
	std::string const& GetFront() const;
	void PushBack(const std::string& value);
	void PushFront(const std::string& value);
	void PopBack();
	void PopFront();
	void Insert(CIterator pos, const std::string& value);
	void Erase(CIterator pos);
	CIterator begin();
	CIterator end();
	ConstCIterator begin() const;
	ConstCIterator end() const;
	ReverseCIterator rbegin();
	ReverseCIterator rend();
	ConstReverseCIterator rbegin() const;
	ConstReverseCIterator rend() const;
private:
	struct Node
	{
		std::string item;
		Node* next;
		Node* prev;
		Node(const std::string& value)
			:item(value)
			, next(nullptr)
			, prev(nullptr)
		{}
	};
	Node* m_front;
	Node* m_back;
	int m_size;
};
