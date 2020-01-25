#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <string>
#include <stack>
#include <queue>
#include <sstream>

class Rational {
public:
	Rational();
	Rational(int numerator, int denominator = 1);
	Rational(const Rational& r);
	int get_numerator() { return numerator; }
	friend Rational operator+(const Rational& r1, const Rational& r2);
	friend Rational operator-(const Rational& r1, const Rational& r2);
	friend Rational operator*(const Rational& r1, const Rational& r2);
	friend Rational operator/(const Rational& r1, const Rational& r2);
	friend bool operator<(const Rational& r1, const Rational& r2);
	friend bool operator>(const Rational& r1, const Rational& r2);
	void power(int);
	friend std::ostream& operator<<(std::ostream& output, Rational& r);
	friend std::istream& operator>>(std::istream& input, Rational& r);

private:
	int numerator;
	int denominator;
	void shorten();
	static int lcm(int x, int y);
	static int gcd(int x, int y);
};

void Rational::power(int power)
{
	numerator = pow(numerator, power);
	denominator = pow(denominator, power);
	shorten();
}

Rational::Rational(int numerator, int denominator)
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
	int num;
	int den;
	int lcm_val = r1.lcm(r1.denominator, r2.denominator);
	int v1 = lcm_val / r1.denominator;
	int v2 = lcm_val / r2.denominator;
	num = r1.numerator * v1 + r2.numerator * v2;
	den = lcm_val;
	return Rational(num, den);
}

Rational operator-(const Rational& r1, const Rational& r2)
{
	int num;
	int den;
	int lcm_val = r1.lcm(r1.denominator, r2.denominator);
	int v1 = lcm_val / r1.denominator;
	int v2 = lcm_val / r2.denominator;
	num = r1.numerator * v1 - r2.numerator * v2;
	den = lcm_val;
	return Rational(num, den);
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


int Rational::gcd(int x, int y) {
	std::cout << "[" << x / y << ';';
	x = x % y;
	while (x != 1)
	{
		std::cout << y / x << ',';
		y = y % x; 
		std::swap(x, y);
	}
	std::cout << y << "]\n";

	return x;
}


int Rational::lcm(int x, int y) {
	return (x * y) / gcd(x, y);
}

void Rational::shorten() {
	if (denominator == 1)return;
	int _gcd = gcd(this->numerator, this->denominator);
	this->numerator /= _gcd;
	this->denominator /= _gcd;
	if (denominator < 0)
	{
		numerator *= -1;
		denominator *= -1;
	}
}

std::ostream& operator<<(std::ostream& output, Rational& r) {
	output << r.numerator;

	if (r.denominator != 1)
		output << "|" << r.denominator;

	return output;
}

std::istream& operator>>(std::istream& input, Rational& r) {
	int a, b = 1;
	/**if (!(input >> a));
	if (input.peek() == '|')
	{
		input.ignore(1);
		if (!(input >> b));
	} **/
	input >> a >> b;
	r = Rational(a, b);
	return input;
}


unsigned int priority(char c)
{
	switch (c)
	{
	case '+':
	case' -':
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

int main()
{
	Rational input;
	while (std::cin >> input);
	return 0;
}

