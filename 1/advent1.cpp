#include <iostream>
#include <string>
#include <fstream> 

int main(void)
{
	std::string input;
	int	number;
	std::fstream fs;
	std::string::size_type sz;
	int max;
	int max1 = 0;
	int max2 = 0;
	int max3 = 0;
	int current_amount;
	int temp1;
	int temp2;

	fs.open("inputfile", std::fstream::in | std::fstream::out);
	while (1)
	{
		if (!std::getline(fs, input))
			break;
		if (input.length() == 0)
		{
			if (current_amount > max3)
			{
				if (current_amount > max1)
				{
					temp1 = max1;
					temp2 = max2;
					max1 = current_amount;
					max2 = temp1;
					max3 = temp2;
				}
				else if (current_amount < max2)
				{
					temp2 = max2;
					max2 = current_amount;
					max3 = temp2;
				}
				else if (current_amount < max3)
					max3 = current_amount;
			}
			current_amount = 0;
			continue;
		}
		number = std::stoi(input, &sz);
		current_amount += number;
	}
	std::cout << "first elf: " << max1 << std::endl;
	std::cout <<  "second elf: " << max2 << std::endl;
	std::cout <<  "third elf: " << max3 << std::endl;
	std::cout <<  "total: " << max1 + max2 + max3 << std::endl;
}