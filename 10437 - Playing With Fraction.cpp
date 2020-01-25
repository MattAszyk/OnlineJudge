#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <string>
#include <stack>
#include <queue>
#include <string>
#include <sstream>

class Rational {
public:
	Rational();
	Rational(long long numerator, long long denominator = 1);
	Rational(const Rational& r);
	long long get_numerator() { return numerator; }
	friend Rational operator+(const Rational& r1, const Rational& r2);
	friend Rational operator-(const Rational& r1, const Rational& r2);
	friend Rational operator*(const Rational& r1, const Rational& r2);
	friend Rational operator/(const Rational& r1, const Rational& r2);
	friend bool operator<(const Rational& r1, const Rational& r2);
	friend bool operator>(const Rational& r1, const Rational& r2);
	void power(long long);
	friend std::ostream& operator<<(std::ostream& output, Rational& r);
	friend std::istream& operator>>(std::istream& input, Rational& r);

private:
	long long numerator;
	long long denominator;
	void shorten();
	static long long lcm(long long x, long long y);
	static long long gcd(long long x, long long y);
};

void Rational::power(long long power)
{
	numerator = pow(numerator, power);
	denominator = pow(denominator, power);
	shorten();
}

Rational::Rational(long long numerator, long long denominator)
{
	this->numerator = numerator;
	this->denominator = denominator;
	shorten();
}

Rational::Rational() {
	numerator = 0;
	denominator = 1;
}


Rational operator+(const Rational& r1, const Rational& r2)
{
	long long num;
	long long den;
	long long lcm_val = r1.lcm(r1.denominator, r2.denominator);
	long long v1 = lcm_val / r1.denominator;
	long long v2 = lcm_val / r2.denominator;
	num = r1.numerator * v1 + r2.numerator * v2;
	den = lcm_val;
	return Rational(num, den);
}

Rational operator-(const Rational& r1, const Rational& r2)
{
	Rational temp((-1) * r2.numerator, r2.denominator);
	return r1 + temp;
}

Rational operator*(const Rational& r1, const Rational& r2)
{
	return Rational(r1.numerator * r2.numerator, r1.denominator * r2.denominator);
}

Rational operator/(const Rational& r1, const Rational& r2)
{
	return Rational(r1.numerator * r2.denominator, r1.denominator * r2.numerator);
}

bool operator<(const Rational& r1, const Rational& r2)
{
	Rational temp = r1;
	temp - r2;
	return temp.numerator < 0 ? true : false;
}

bool operator>(const Rational& r1, const Rational& r2)
{
	return !(r1 < r2);
}

Rational::Rational(const Rational& r) {
	this->numerator = r.numerator;
	this->denominator = r.denominator;
}


long long Rational::gcd(long long x, long long y) {
	while (y != 0) {
		long long r = x % y;
		x = y;
		y = r;
	}

	return x;
}


long long Rational::lcm(long long x, long long y) {
	return (x * y) / gcd(x, y);
}

void Rational::shorten() {
	if (denominator == 0)
	{
		throw std::invalid_argument("got 0 as denominator");
	}
	
	long long _gcd = gcd(this->numerator, this->denominator);
	this->numerator /= _gcd;
	this->denominator /= _gcd;
	if (denominator < 0)
	{
		numerator = 0 - numerator;
		denominator = 0 - denominator;
	}
}

std::ostream& operator<<(std::ostream& output, Rational& r) {
	output << r.numerator;

	if (r.denominator != 1)
		output << "|" << r.denominator;

	return output;
}

std::istream& operator>>(std::istream& input, Rational& r) {
	char separator;
	input >> r.numerator >> separator >> r.denominator;
	r.shorten();

	return input;
}


unsigned long long priority(char c)
{
	switch (c)
	{
	case '+':
	case '-':
		return 1;
	case '*':
	case '/':
		return 2;
	default:
		return 0;
	}
}

bool make_space(char c)
{
	return (c == '+' || c == '-' || c == '*' || c == '/' || c == '(' || c == ')');
}

bool math_operator(char c)
{
	return (c == '+' || c == '-' || c == '*' || c == '/');
}

std::vector<std::string> infix(std::string input)
{
	std::istringstream ss(input);
	std::vector<std::string> notation;
	std::string input_stream;
	std::stack<std::string> stack;
	while (ss >> input_stream)
	{
		if (isdigit(input_stream[0]))
		{
			notation.push_back(input_stream);
		}
		else if (input_stream == "(")
		{
			stack.push(input_stream);
		}
		else if (input_stream == ")")
		{
			while (!stack.empty() && stack.top() != "(")
			{
				notation.push_back(stack.top());
				stack.pop();
			}
			stack.pop();
		}
		else if (math_operator(input_stream[0]))
		{
			while (!stack.empty() && priority(stack.top()[0]) >= priority(input_stream[0]))
			{
				notation.push_back(stack.top());
				stack.pop();
			}
			stack.push(input_stream);
		}
	}
	while (!stack.empty())
	{
		notation.push_back(stack.top());
		stack.pop();
	}

	return notation;
}


void calcule(std::vector<std::string> notation)
{
	std::stack<Rational> stack;
	for (std::string value : notation)
	{
		if (make_space(value[0]))
		{
			Rational temp;
			Rational a = stack.top();
			stack.pop();
			Rational b = stack.top();
			stack.pop();
			try
			{
				switch (value[0])
				{
				case '+':
					temp = a + b;
					break;
				case '-':
					temp = b - a;
					break;
				case '*':
					temp = a * b;
					break;
				case '/':
					temp = b / a;
					break;
				}
				stack.push(temp);
			}
			catch (std::invalid_argument)
			{
				std::cout << "INVALID" << std::endl;
				return;
			}
		}
		else /*number input*/
		{
			Rational input;
			std::stringstream ss;
			ss << value;
			try {
				ss >> input;
				stack.push(input);
			}
			catch (std::invalid_argument)
			{
				std::cout << "INVALID" << std::endl;
				return;
			}

		}
	}
	if (!stack.empty())
		std::cout << stack.top() << std::endl;
}


int main()
{
	std::string input_line;
	std::string correct;
	while (std::getline(std::cin, input_line))
	{
		correct = input_line;
		input_line = "";
		for (char c : correct)
			if (c == ' ') continue;
			else input_line.push_back(c);
		correct = "";
		for (int i = 1; i <= input_line.size(); ++i)
			if (make_space(input_line[i - 1])) {
				correct.push_back(' ');
				correct.push_back(input_line[i - 1]);
				correct.push_back(' ');
			}
			else correct.push_back(input_line[i - 1]);
		calcule(infix(correct));

	}
	return 0;
}
