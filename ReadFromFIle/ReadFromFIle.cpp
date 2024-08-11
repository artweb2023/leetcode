#include <fstream>
#include <iostream>
#include <string>

int main()
{
	std::fstream input("input.txt");
	std::ofstream output("output.txt");
	std::string line;
	size_t pos = 0;
	if (input.is_open())
	{
		while (std::getline(input, line))
		{
			std::string login;
			std::string pass;
			size_t foundPos = line.find(':', pos);
			login.append(line.substr(pos, foundPos));
			pass.append(line.substr(foundPos + 1, line.length()));
			if (output.is_open())
			{
				output << "login:" << login << "\n";
				output << "password:" << pass << "\n";
			}
		}
	}
	input.close();
	output.close();
}
