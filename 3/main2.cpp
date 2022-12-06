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
		std::string get_items()
		{
			return _items;
		}
		size_t find_priority_total()
		{
			size_t prio = 0;
			for(char& c : _items) 
			{
   				if (c >= 'a' && c <= 'z')
				{
					prio += c - ('a' - 1);
				}
   				if (c >= 'A' && c <= 'Z')
				{
					prio +=  26 + c - ('A' - 1);
				}
			}
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
		char compair(Rugsack &myrugsack1, Rugsack &myrugsack2, Rugsack &myrugsack3)
		{
			for (int i = 0; i < myrugsack1.get_items().length(); i++)
			{
				for (int j = 0; j < myrugsack2.get_items().length(); j++)
				{
					if (myrugsack1.get_items()[i] == myrugsack2.get_items()[j])
					{
						for (int k = 0; k < myrugsack3.get_items().length(); k++)
						{
							if (myrugsack2.get_items()[j] == myrugsack3.get_items()[k])
								return myrugsack3.get_items()[k];
						}
					}
				}
			}
			return 0;
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
		Rugsack myrugsack1(input, i);
		if (!std::getline(fs, input))
			break;
		i++;
		Rugsack myrugsack2(input, i);
		if (!std::getline(fs, input))
			break;
		i++;
		Rugsack myrugsack3(input, i);

		char c = myrugsack1.compair(myrugsack1, myrugsack2, myrugsack3);
		if (c == 0)
			std::cout << "i is " << i << "    ERROR c is 0" << std::endl;
		if (c >= 'a' && c <= 'z')
			_total += c - ('a' - 1);
		else if (c >= 'A' && c <= 'Z')
			_total += 26 + c - ('A' - 1);
	}

	// for (int k = 0; k < 52; k++)
	// {
	// 	std::cout << k << " " << mylist.get_list_item(k) << std::endl;
	// }
	//std::cout << mylist.calc_total() << std::endl;
	std::cout << _total << std::endl;

	fs.close();
}