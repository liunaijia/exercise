#include <iostream>

int main()
{
	using std::cout;
	using std::cin;

	double light_years_to_astronomical_units(double);

	double light_years;
	cout << "Enter the number of light years: ";
	cin >> light_years;
	cout << light_years << " light years = " << light_years_to_astronomical_units(light_years) << " astronomical units.";
}

double light_years_to_astronomical_units(double light_years)
{
	return light_years * 63240;
}