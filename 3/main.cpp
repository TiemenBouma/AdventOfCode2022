#include <iostream>
#include <string>
#include <fstream> 

class List
{
	private;
		int _list[52]
	public
		list()
		{
			for (int i = 0; i < 52, i++)
				_list[i] = 0;
		}
		void add_to_list(char c)
		{
			int i;
			if (c >= 'a' && c <= 'z')
				i = c - ('a' - 1);
			if (c >= 'A' && c <= 'Z')
				i =  26 + c - ('A' - 1);
			if (_list[i - 1] != 0)
				_list[i - 1] = i;
		}
		size_t calc_total()
		{
			size_t total;
			for (int i = 0; i < 52, i++)
			
		}
};

class	Rugsack
{
	private:
		std::string		_items;
		size_t			_sack_n;
		size_t			_total_items;
		
	
	public:
		void get_items(std::string input)
		{
			_items = input;
		}
		void get_index(int index)
		{
			_sack_n = index;
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
		void find_double(list &mylist)
		{
			size_t length;
			for(char& c : _items) 
				length++;
			for (int i = 0; i < length / 2; i++)
			{
				for (int j = length / 2; j < length; j++)
				{
					if (_items[i] == _items[j])
						mylist.
				}
			}
		}

};

int main(void)
{
	std::string input;
	size_t total_points = 0;
	size_t	i = 0;
	std::fstream fs;
	std::string::size_type sz;
	int score = 0;
	int round = 0;

	fs.open("input", std::fstream::in | std::fstream::out);

	while(1)
	{
		if (!std::getline(fs, input))
			break;
		i++;
	}
	List mylist();

	fs.close();
	fs.open("input", std::fstream::in | std::fstream::out);
	Rugsack *ptr = new Rugsack[i];
	i = 0;
	while (1)
	{
		if (!std::getline(fs, input))
			break;
		//std::getline(fs, input);
		ptr[i].get_items(input);
		ptr[i].get_index(i);
		ptr[i].find_double(mylist);
		i++;
	}
	std::cout << total_points << std::endl;
}