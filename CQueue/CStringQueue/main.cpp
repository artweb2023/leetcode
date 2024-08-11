#include "CQueue.h"
#include <iostream>
#include <sstream>

int main()
{
	system("chcp 1251>nul");
	CQueue queue;
	std::string input;
	std::cout << "Введите текст ";
	std::getline(std::cin, input);
	std::stringstream ss(input);
	std::string word;
	while (ss >> word)
	{
		queue.Enqueue(word);
	}
	std::string result;
	while (!queue.IsEmpty())
	{
		result += queue.GetFront();
		queue.Dequeue();
		if (!queue.IsEmpty())
		{
			result += " ";
		}
	}
	std::cout << "Предложение без лишних пробелов: " << result << std::endl;
	std::cout << queue.GetBack() << std::endl;
	return 0;
}