#define CATCH_CONFIG_MAIN 
#include "../catch2/catch.hpp"
#include "../CStringQueue/CQueue.h"


SCENARIO("Testing CQueue functionality")
{
	GIVEN("An empty queue")
	{
		CQueue queue;
		THEN("The queue should be empty")
		{
			REQUIRE(queue.IsEmpty());
			REQUIRE(queue.GetSize() == 0);
		}
		WHEN("An element is enqueued")
		{
			queue.Enqueue("str");
			THEN("The queue should contain one element")
			{
				REQUIRE_FALSE(queue.IsEmpty());
				REQUIRE(queue.GetSize() == 1);
				REQUIRE(queue.GetFront() == "str");
				REQUIRE(queue.GetBack() == "str");
			}
		}
		WHEN("Multiple elements are enqueued")
		{
			queue.Enqueue("str1");
			queue.Enqueue("str2");
			THEN("The queue should contain the elements in the correct order")
			{
				REQUIRE(queue.GetSize() == 2);
				REQUIRE(queue.GetFront() == "str1");
				REQUIRE(queue.GetBack() == "str2");
			}
		}
		WHEN("An element is dequeued from a queue with one element")
		{
			queue.Enqueue("str1");
			queue.Dequeue();

			THEN("The queue should be empty")
			{
				REQUIRE(queue.IsEmpty());
				REQUIRE(queue.GetSize() == 0);
			}
		}
		WHEN("An element is dequeued from a queue with multiple elements")
		{
			queue.Enqueue("str1");
			queue.Enqueue("str2");
			queue.Dequeue();
			THEN("The queue should have the correct size and elements")
			{
				REQUIRE(queue.GetSize() == 1);
				REQUIRE(queue.GetFront() == "str2");
				REQUIRE(queue.GetBack() == "str2");
			}
		}
		WHEN("Elements are enqueued and dequeued in various order")
		{
			queue.Enqueue("str1");
			queue.Enqueue("str2");
			queue.Dequeue();
			queue.Enqueue("str3");
			queue.Dequeue();
			queue.Enqueue("str4");
			THEN("The queue should have the correct size and elements")
			{
				REQUIRE(queue.GetSize() == 2);
				REQUIRE(queue.GetFront() == "str3");
				REQUIRE(queue.GetBack() == "str4");
			}
		}
	}
}