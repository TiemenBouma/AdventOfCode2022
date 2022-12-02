#include <iostream>
#include <string>
#include <fstream> 

int main(void)
{
	std::string input;
	int	number;
	std::fstream fs;
	std::string::size_type sz;
	int score = 0;
	int round = 0;

	fs.open("input", std::fstream::in | std::fstream::out);
	while (1)
	{
		if (!std::getline(fs, input))
			break;
		round++;
		if (input.at(0) == 'A')//ROCK
		{
			if (input.at(2) == 'X')//SISSOR
			{
				score += 3;
				score += 0;
			}
			else if (input.at(2) == 'Y')//ROCK
			{
				score += 1;
				score += 3;
			}
			else if (input.at(2) == 'Z')//PAPER
			{
				score += 2;
				score += 6;
			}
		}
		else if (input.at(0) == 'B')//Paper
		{
			if (input.at(2) == 'X')//ROCK
			{
				score += 1;
				score += 0;
			}
			else if (input.at(2) == 'Y')//PAPER
			{
				score += 2;
				score += 3;
			}
			else if (input.at(2) == 'Z')//SISSOR
			{
				score += 3;
				score += 6;
			}
		}
		else if (input.at(0) == 'C')//Sissor
		{
			if (input.at(2) == 'X')//PAPER
			{
				score += 2;
				score += 0;
			}
			else if (input.at(2) == 'Y')//SISSOR
			{
				score += 3;
				score += 3;
			}
			else if (input.at(2) == 'Z')//ROCK
			{
				score += 1;
				score += 6;
			}
		}
	}
	std::cout << "score is: " << score << " round is: " << round << std::endl;
}