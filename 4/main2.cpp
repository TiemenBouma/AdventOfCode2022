#include <iostream>
#include <string>
#include <fstream>

size_t _total = 0;

class Elf
{
	private:
		std::string _range;
		int			_min;
		int			_max;
	public:
		Elf(std::string range)
		{
			_range = range;
			_min = std::stoi(range.substr(0, range.find('-')));
			_max = std::stoi(range.substr(range.find('-') + 1, range.size()));
		}
		int get_min() { return _min; }
		int get_max() { return _max; }
		std::string get_range() { return _range; }
		int compair(Elf &elf1, Elf &elf2)
		{
			if (elf1.get_min() > elf2.get_max())
				return 0;
			else if (elf1.get_max() < elf2.get_min())
				return 0;
			else
				return 1;
		}
};

int main(void)
{
	std::string input;
	size_t total_points = 0;
	std::fstream fs;

	fs.open("input", std::fstream::in | std::fstream::out);

	//List mylist;

	for (int i = 0; 1 ; i++)
	{
		if (!std::getline(fs, input))
			break;
		Elf elf1(input.substr(0, input.find(',')));
		Elf elf2(input.substr(input.find(',') + 1, input.size()));
		_total += elf1.compair(elf1, elf2);
		std::cout << "index: " << i << " " << elf1.get_range() << " " << elf2.get_range() << " total is " << _total << std::endl;
		std::cout << i << std::endl;
	}
	std::cout << _total << std::endl;

}