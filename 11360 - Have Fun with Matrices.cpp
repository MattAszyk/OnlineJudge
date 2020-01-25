#include <iostream>
#include <sstream>
#include <utility>
#include <functional>

class matrix {
private:
	int** data;
	int modulo(int, unsigned int = 10);
	unsigned int size;
	int input_line = 0;
	void row(unsigned int, unsigned int);
	void col(unsigned int, unsigned int);
	void swap(int* a, int* b)
	{
		int temp = *b;
		*b = *a;
		*a = temp;
	};
	void inc();
	void dec();
	void transpose();
	std::pair<int, int> get_ab(std::string);
public:
	matrix(unsigned int);
	void print(int);
	void command();
	void input(std::string);
	~matrix();
};

void matrix::print(int c)
{
	std::cout << "Case #" << c << "\n";
	for (int i = 0; i < size; ++i)
	{
		for (int j = 0; j < size; ++j)
		{
			std::cout << data[i][j];
		}
		std::cout << "\n";
	}
	std::cout << "\n";
}

std::pair<int, int> matrix::get_ab(std::string input)
{
	std::stringstream ss(input);
	std::string z; int a, b;
	ss >> z >> a >> b;
	return  std::make_pair(a - 1, b - 1);
}

void matrix::command()
{
	std::string wcommand;
	int a, b;
	std::cin >> wcommand;
	switch (wcommand[0])
	{
	case 'r':
		std::cin >> a >> b;
		row(a-1, b-1);
		break;
	case 'c':
		std::cin >> a >> b;
		col(a-1, b-1);
		break;
	case 'i':
		inc();
		break;
	case 'd':
		dec();
		break;
	case 't':
		transpose();
		break;
	default:
		std::cout << "hehe";
		break;
	}
}

void matrix::input(std::string line)
{
	for (int i = 0; i < size; ++i)
	{
		data[input_line][i] = line[i] - '0';
	}
	input_line++;
}

int matrix::modulo(int y, unsigned int p)
{
	return  (y % p < 0) ? y % p + p : y % p;
}

void matrix::row(unsigned int a, unsigned int b)
{
	for (int i = 0; i < size; ++i)
	{
		swap(this->data[a]+i, this->data[b]+i);
	}
}

matrix::matrix(unsigned int size)
{
	this->size = size;
	data = new int* [size];
	for (int i = 0; i < size; ++i)
	{
		data[i] = new int[size];
	}
}

void matrix::col(unsigned int a, unsigned int b)
{
	for (int i = 0; i < size; ++i)
	{
		swap(this->data[i]+a, this->data[i]+b);

	}
}

void matrix::inc()
{
	for (int i = 0; i < size; ++i)
	{
		for (int j = 0; j < size; ++j)
		{
			data[i][j] = (data[i][j] + 1) % 10;
		}
	}
}

void matrix::dec()
{
	for (int i = 0; i < size; ++i)
	{
		for (int j = 0; j < size; ++j)
		{
			data[i][j] = (data[i][j] + -1) % 10;
			if (data[i][j] < 0) data[i][j] += 10;

		}
	}
}

void matrix::transpose() {
	int** temp = new int* [size];
	for (int i = 0; i < size; ++i)
	{
		temp[i] = new int[size];
	}
	for (int i = 0; i < size; ++i)
	{
		for (int j = 0; j < size; ++j)
		{
			temp[i][j] = data[i][j];
		}
	}

	for (int i = 0; i < size; ++i)
	{
		for (int j = 0; j < size; ++j)
		{
			data[i][j] = temp[j][i];
		}
	}

	for (int i = 0; i < size; ++i)
	{
		delete[] temp[i];
	}
	delete[] temp;
}

matrix::~matrix()
{
	for (int i = 0; i < size; ++i)
	{
		delete[] data[i];
	}
	delete[] data;
}


int main()
{
	int test_cases = 1, n, dem, oper;
	std::string input_line;
	std::cin >> n;
	while (n--)
	{
		std::cin >> dem;
		matrix o_matrix(dem);
		for (int i = 0; i < dem; i++)
		{
			std::cin >> input_line;
			o_matrix.input(input_line);
		}
		std::cin >> oper;
		for (int i = 0; i < oper; ++i)
		{
			o_matrix.command();
		}
		o_matrix.print(test_cases++);
	}
	return 0;
}
