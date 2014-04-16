#include <iostream>
#include "1197Complex.h"

using namespace std;

Complex::Complex(double real, double img) {
	this->real = real;
	this->img = img;
}

bool operator>>(istream& in, Complex& c) {
	cout << "real: ";
	if (!(cin >> c.real))
		return false;
	cout << "imaginary: ";
	return cin >> c.img;
}

ostream& operator<<(ostream& out, const Complex& c) {
	return out << "(" << c.real << ", " << c.img << "i)";
}

Complex operator~(const Complex& c) {
	Complex conjugate(c.real, -c.img);
	return conjugate;
}

Complex operator+(const Complex& c1, const Complex& c2) {
	Complex c(c1.real + c2.real, c1.img + c2.img);
	return c;
}

Complex operator-(const Complex& c1, const Complex& c2) {
	Complex c(c1.real - c2.real, c1.img - c2.img);
	return c;
}

Complex operator*(const Complex& c1, const Complex& c2) {
	Complex c(c1.real * c2.real - c1.img * c2.img, c1.real * c2.img + c1.img * c2.real);
	return c;
}

Complex operator*(double x, const Complex& c) {
	Complex m(x * c.real, x * c.img);
	return m;
}

int main() {
	Complex a(3.0, 4.0);
	Complex c;
	cout << "Enter a complex number (q to quit):" << endl;
	while(cin >> c) {
		cout << "c is " << c << endl;
		cout << "complex conjugate is " << ~c << endl;
		cout << "a is " << a << endl;
		cout << "a + c is " << a + c << endl;
		cout << "a - c is " << a - c << endl;
		cout << "a * c is " << a * c << endl;
		cout << "2 * c is " << 2 * c << endl;
		cout << "Enter a complex number (q to quit):" << endl;
	}
	cout << "done!"
	return 0;
}