#include <iostream>
#include <string>
#include <vector>

template<typename T>
T AccumulateVector(const std::vector<T>& v)
{
	T value = T();
	for (auto first = v.begin(); first != v.end(); ++first)
	{
		value = value + *first;
	}
	return value;
}


int main()
{
	std::vector<int> v = { 10, 20, 5 };
	int r = AccumulateVector(v);// r = 35
	std::cout << r << std::endl;
	std::vector<std::string> vs = { "A", "B", "C" };
	std::string rs = AccumulateVector(vs);// rs = "ABC“
	std::cout << rs << std::endl;
	return 0;
}

