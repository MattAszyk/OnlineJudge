#include <iostream>
#include <string>

char command(char input) {
	switch (input) {
	case 'R':
		return '/';
	case 'F':
		return '\\';
	case 'C':
		return '_';
	}
}



int main()
{
	int cases = 1;
	int tests;
	std::cin >> tests;
	while (tests--)
	{
		char table[110][60];
		for (int y = 0; y < 110; y++)
			for (int x = 0; x < 60; x++)
				table[y][x] = ' ';
		std::string input;
		std::cin >> input;
		int upper = 0, lower = 0;
		for (int i = 0; i < input.length(); ++i)
		{
			if (input[i] == 'R') upper++;
			else if (input[i] == 'L') lower++;
		}

		int x_coor = 0;
		int y_coor = 55;
		int y_min = 55;
		for (int i = 0; i < input.length(); i++) {
			if (input[i] == 'R')
			{
				if (i && input[i - 1] == 'R') y_coor--;
				table[y_coor][i] = '/';
			}
			else if (input[i] == 'F')
			{
				if (i && input[i - 1] == 'F' || input[i - 1] == 'C') y_coor++;
				table[y_coor][i] = '\\';
			}
			else
			{
				if (i && input[i - 1] == 'R') y_coor--;
				table[y_coor][i] = '_';
			}
		}
		for (int y = 0; y < 110; y++) {
			int d = 0;
			for (int x = 0; x < 50; x++) {
				if (table[y][x] != ' ') d = x + 1;
			}
			table[y][d] = '\0';
		}

		std::cout << "Case #" << cases++ << ":\n";
		for (int y = 0; y < 110; y++) {
			if (table[y][0] == '\0') continue;
			std::cout << "| ";

			for (int x = 0; x < 60; x++)
			{
				if (table[y][x] == '\0') break;
				std::cout << table[y][x];
			}
			std::cout << std::endl;
		}
		std::cout << '+';
		for (int i = 0; i < input.length() + 2; i++)
			std::cout << '-';
		std::cout << std::endl;
	}
	return 0;
}
