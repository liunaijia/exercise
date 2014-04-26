#include <iostream>

int main()
{
	using namespace std;

	float lp100km_to_mpg(float);
	float mpg_to_lp100km(float);

	float x;

	cout << "Enter number of l/100km:";
	cin >> x;
	cout << lp100km_to_mpg(x) << " mpg" << endl;

	cout << "Enter number of miles per gallon:";
	cin >> x;
	cout << mpg_to_lp100km(x) << " l/100km" << endl;
}

float lp100km_to_mpg(float lp100km)
{
	return 1 / lp100km * 62.14 * 3.785;
}

float mpg_to_lp100km(float mpg)
{
	return 1 / mpg * 3.785 * 62.14;
}