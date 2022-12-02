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
		if (input.at(2) == 'X')//ROCK
		{
			score += 1;
			if (input.at(0) == 'A')//ROCK
				score += 3;
			else if (input.at(0) == 'C')//SISSOR
				score += 6;
		}
		else if (input.at(2) == 'Y')//Paper
		{
			score += 2;
			if (input.at(0) == 'B')//PAPER
				score += 3;
			else if (input.at(0) == 'A')//ROCK
				score += 6;
		}
		else if (input.at(2) == 'Z')//Sissor
		{
			score += 3;
			if (input.at(0) == 'C')//SISSOR
				score += 3;
			else if (input.at(0) == 'B')//PAPER
				score += 6;
		}
	}
	std::cout << "score is: " << score << " round is: " << round << std::endl;
}