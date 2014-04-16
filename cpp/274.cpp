#include <iostream>

int main()
{
	using std::cout;
	using std::cin;

	double c_to_f(double);

	double c;
	cout << "Please enter a Celsius value: ";
	cin >> c;
	cout << c << " degrees Celsius is " << c_to_f(c) << " degrees Fahrenheit.";
}

double c_to_f(double c)
{
	return 1.8 * c + 32;
}