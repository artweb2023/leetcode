#define CATCH_CONFIG_MAIN 
#include "../catch2/catch.hpp"
#include "../CStringList/CIterator.h"
#include "../CStringList/CList.h"
#include "../CStringList/ConstCIterator.h"
#include "../CStringList/ConstReverseCIterator.h"
#include "../CStringList/ReverseCIterator.h"

SCENARIO("Testing CStringList functionality")
{
	GIVEN("An empty list")
	{
		CList list;
		THEN("The list should be empty")
		{
			REQUIRE(list.IsEmpty());
			REQUIRE(list.GetSize() == 0);
		}
		WHEN("An element is added to the front")
		{
			list.PushFront("str");

			THEN("The list should contain one element")
			{
				REQUIRE_FALSE(list.IsEmpty());
				REQUIRE(list.GetSize() == 1);
				REQUIRE(list.GetFront() == "str");
				REQUIRE(list.GetBack() == "str");
			}
		}
		WHEN("An element is added to the back")
		{
			list.PushBack("str");

			THEN("The list should contain one element")
			{
				REQUIRE_FALSE(list.IsEmpty());
				REQUIRE(list.GetSize() == 1);
				REQUIRE(list.GetFront() == "str");
				REQUIRE(list.GetBack() == "str");
			}
		}
		WHEN("Multiple elements are added to the front")
		{
			list.PushFront("str1");
			list.PushFront("str2");

			THEN("The list should contain the elements in the correct order")
			{
				REQUIRE(list.GetSize() == 2);
				REQUIRE(list.GetFront() == "str2");
				REQUIRE(list.GetBack() == "str1");
			}
		}
		WHEN("Multiple elements are added to the back")
		{
			list.PushBack("str1");
			list.PushBack("str2");

			THEN("The list should contain the elements in the correct order")
			{
				REQUIRE(list.GetSize() == 2);
				REQUIRE(list.GetFront() == "str1");
				REQUIRE(list.GetBack() == "str2");
			}
		}
		WHEN("Elements are added to both front and back")
		{
			list.PushFront("str1");
			list.PushBack("str2");
			list.PushFront("str3");
			list.PushBack("str4");
			THEN("The list should contain the elements in the correct order")
			{
				REQUIRE(list.GetSize() == 4);
				REQUIRE(list.GetFront() == "str3");
				REQUIRE(list.GetBack() == "str4");
			}
		}
		WHEN("Elements are removed from the front")
		{
			list.PushFront("str1");
			list.PushFront("str2");
			list.PopFront();
			THEN("The list should have the correct size and elements")
			{
				REQUIRE(list.GetSize() == 1);
				REQUIRE(list.GetFront() == "str1");
			}
		}
		WHEN("Elements are removed from the back")
		{
			list.PushBack("str1");
			list.PushBack("str2");
			list.PopBack();
			THEN("The list should have the correct size and elements")
			{
				REQUIRE(list.GetSize() == 1);
				REQUIRE(list.GetBack() == "str1");
			}
		}
		WHEN("Inserting an element using an iterator")
		{
			list.PushBack("str1");
			auto it = list.begin();
			list.Insert(it, "str2");
			THEN("The element should be inserted correctly")
			{
				REQUIRE(list.GetSize() == 2);
				REQUIRE(list.GetFront() == "str2");
			}
		}
		WHEN("Erasing an element using an iterator")
		{
			list.PushBack("str1");
			auto it = list.begin();
			list.Erase(it);
			THEN("The element should be erased correctly")
			{
				REQUIRE(list.GetSize() == 0);
				REQUIRE(list.IsEmpty());
			}
		}
		WHEN("Iterating over the list")
		{
			list.PushBack("str1");
			list.PushBack("str2");
			list.PushBack("str3");
			THEN("The elements should be iterated in the correct order")
			{
				std::vector<std::string> elements;
				for (auto it = list.begin(); it != list.end(); ++it)
				{
					elements.push_back(*it);
				}
				REQUIRE(elements.size() == 3);
				REQUIRE(elements[0] == "str1");
				REQUIRE(elements[1] == "str2");
				REQUIRE(elements[2] == "str3");
			}
		}
		WHEN("Reverse iterating over the list")
		{
			list.PushBack("str1");
			list.PushBack("str2");
			list.PushBack("str3");
			THEN("The elements should be iterated in the reverse order")
			{
				std::vector<std::string> elements;
				for (auto it = list.rbegin(); it != list.rend(); ++it)
				{
					elements.push_back(*it);
				}
				REQUIRE(elements.size() == 3);
				REQUIRE(elements[0] == "str3");
				REQUIRE(elements[1] == "str2");
				REQUIRE(elements[2] == "str1");
			}
		}
	}
}