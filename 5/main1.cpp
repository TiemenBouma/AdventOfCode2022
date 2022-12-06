#include <iostream>
#include <string>
#include <fstream>
#include <array>

class Stack
{
	private:
		std::array <char, 100> _stack;
		int _top = 0;
	public:
		void push(char c)
		{
			_stack[_top] = c;
			_top++;
		}
		char pop()
		{
			if (_top <= 0)
			{
				std::cout << "ERROR: Stack is empty" << std::endl;
				exit(1);
			}
			_top--;
			return _stack[_top];
		}
		char top()
		{
			return _stack[_top - 1];
		}
		bool empty()
		{
			return _top == 0;
		}
		std::string toString()
		{
			std::string s;
			for (int i = 0; i < _top; i++)
				s += _stack[i];
			return s;
		}
		int get_top()
		{
			return _top;
		}
};

size_t _total = 0;

class Move
{
	private:
		int _amount;
		int _from;
		int _to;
	public:
		Move(int amount, int from, int to)
		{
			_amount = amount;
			_from = from - 1;
			_to = to - 1;
		}
		int amount()
		{
			return _amount;
		}
		int from()
		{
			return _from;
		}
		int to()
		{
			return _to;
		}
		void move_action(Stack stack[])
		{
			for (int i = 0; i < _amount; i++)
			{
				char c = stack[_from].pop();
				stack[_to].push(c);
			}
		}
};


void parse(std::string input[], std::fstream &fs, Stack stack[])
{
	for (int i = 0; i < 8 ; i++)
	{
		if (!std::getline(fs, input[i]))
			break;
		std::cout << input[i] << std::endl;
	}
	for (int i = 7; i >= 0; i--)
	{
		int index = 0;
		for (int j = 1; j < input[i].length(); j += 4)
		{
			if (input[i][j] != ' ')
				stack[index].push(input[i][j]);
			index++;
		}
	}
}

int main(void)
{
	std::string input[8];
	std::string input2;

	std::fstream fs;
	Stack stack[9];


	fs.open("input", std::fstream::in | std::fstream::out);
	parse(input, fs, stack);
	std::getline(fs, input2);
	std::getline(fs, input2);
	for (int i = 0; 1 ; i++)
	{
		if (!std::getline(fs, input2))
			break;
		std::cout << std::endl << "MOVE " << i << std::endl;
		std::cout << input2 << std::endl;
		std::cout << "-----------------STACKS----------------" << std::endl;

		int pos1 = input2.find(' ', 0);
		int pos2 = input2.find(' ', pos1 + 1);
		int pos3 = input2.find(' ', pos2 + 1);
		int pos4 = input2.find(' ', pos3 + 1);
		int pos5 = input2.find(' ', pos4 + 1);
		Move move(input2[pos1 + 1] - '0', input2[pos3 + 1] - '0', input2[pos5 + 1] - '0');
		std::cout << move.from() + 1 << " " << stack[move.from()].toString() << "\t\ttotal: " << stack[move.from()].get_top() <<  std::endl;
		std::cout << move.to() + 1 << " " << stack[move.to()].toString() << "\t\ttotal: " << stack[move.to()].get_top() <<  std::endl << std::endl;


		move.move_action(stack);

		std::cout << move.from() + 1 << " " << stack[move.from()].toString() << "\t\ttotal: " << stack[move.from()].get_top() <<  std::endl;
		std::cout << move.to() + 1 << " " << stack[move.to()].toString() << "\t\ttotal: " << stack[move.to()].get_top() <<  std::endl;
		// for (int j = 0; j < 9; j++)
		// 	std::cout << j + 1 << " " << stack[j].toString() << "\t\ttotal: " << stack[j].get_top() <<  std::endl;
		std::cout << "-----------------STACKS----------------" << std::endl;
		
	}
	fs.close();

}