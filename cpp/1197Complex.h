#include <iostream>

class Complex {
private:
	double real;
	double img;
public:
	Complex(double real = 0, double img = 0);
	friend bool operator>>(std::istream& in, Complex& c);
	friend std::ostream& operator<<(std::ostream& out, const Complex& c);
	friend Complex operator~(const Complex& c);
	friend Complex operator+(const Complex& c1, const Complex& c2);
	friend Complex operator-(const Complex& c1, const Complex& c2);
	friend Complex operator*(const Complex& c1, const Complex& c2);
	friend Complex operator*(double x, const Complex& c);
};