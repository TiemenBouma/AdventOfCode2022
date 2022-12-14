#include <iostream>
#include <string>
#include <fstream> 

		size_t _total = 0;
class List
{
	private:
		size_t _list[52];
	public:
		List()
		{
			for (int i = 0; i < 52; i++)
				_list[i] = 0;

		}

		size_t	get_list_item(int index) { return _list[index]; }


		void add_to_list(char c)
		{
			std::cout << "c = " << c << std::endl;
			size_t i = 0;
			if (c >= 'a' && c <= 'z')
			{
				i = c - ('a' - 1);
				if (_list[i - 1] == 0)
					_total += c - ('a' - 1);
			}
			else if (c >= 'A' && c <= 'Z')
			{
				i =  26 + c - ('A' - 1);
				if (_list[i - 1] == 0)
					_total += 26 + c - ('A' - 1);
			}
			if (i != 0)
				_list[i - 1] = i;
		}

		size_t calc_total()
		{
			size_t total = 0;
			for (int i = 0; i < 52; i++)
			{
				
					total += _list[i];
			}
			return total;
		}
};

class	Rugsack
{
	private:
		std::string		_items;
		size_t			_sack_n;
		size_t			_total_items;
		
	
	public:
		Rugsack()
		{
			_items = "";
			_sack_n = 0;
		}
		Rugsack(std::string input, int sack_n)
		{
			_items = input;
			_sack_n = sack_n;
		}

		size_t find_priority_total()
		{
			size_t prio = 0;
			for(char& c : _items) 
			{
   				if (c >= 'a' && c <= 'z')
				{
					prio += c - ('a' - 1);
					//std::cout << c << c - ('a' - 1) << std::endl;
				}
   				if (c >= 'A' && c <= 'Z')
				{
					prio +=  26 + c - ('A' - 1);
					//std::cout << c << 26 + c - ('A' - 1) << std::endl;
				}
			}
			//std::cout << prio << std::endl;
			return prio;
		}
		void find_double()
		{
			size_t length = 0;
			for(char& c : _items)
			{
				length++;
			}
			List mylist;
			for (int i = 0; i < length / 2; i++)
			{
				for (int j = length / 2; j < length; j++)
				{
					if (_items[i] == _items[j])
						mylist.add_to_list(_items[i]);
				}
			}
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
		std::cout << input << std::endl;
		Rugsack myrugsack(input, i);

		myrugsack.find_double();
	}

	// for (int k = 0; k < 52; k++)
	// {
	// 	std::cout << k << " " << mylist.get_list_item(k) << std::endl;
	// }
	//std::cout << mylist.calc_total() << std::endl;
	std::cout << _total << std::endl;

	fs.close();
}