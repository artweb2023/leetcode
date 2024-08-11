#include <iostream>
#include <sstream>
#include <string>

struct Node
{
	std::string item;
	Node* next;
	Node(const std::string& str) : item(str), next(nullptr) {};
};

void AddWordInList(const std::string& word, Node*& ptr)
{
	Node* newNode = new Node(word);
	if (ptr == nullptr)
	{
		ptr = newNode;
	}
	else
	{
		Node* current = ptr;
		while (current->next != nullptr)
		{
			current = current->next;
		}
		current->next = newNode;
	}
}

void CleanList(Node*& ptr)
{
	Node* temp = ptr;
	ptr = ptr->next;
	delete temp;
}

void PrintWord(Node* ptr)
{
	while (ptr != nullptr)
	{
		std::cout << ptr->item << std::endl;
		CleanList(ptr);
	}
}

int main()
{
	std::string line;
	Node* ptr = nullptr;
	while (std::getline(std::cin, line))
	{
		std::istringstream ss(line);
		std::string word;
		while (ss >> word)
		{
			AddWordInList(word, ptr);
		}
	}
	PrintWord(ptr);
	return 0;
}
