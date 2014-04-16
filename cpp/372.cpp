#include <iostream>

int main()
{
	using namespace std;

	int feet, inch, pound;
	cout << "Enter your height(feet):";
	cin >> feet;

	cout << "Enter your height(inch):";
	cin >> inch;

	cout << "Enter your weight(pound):";
	cin >> pound;

	const int INCH_PER_FEET = 12;
	const float METER_PER_INCH = 0.0254;
	const float POUND_PER_KILO = 2.2;

	float height = (feet * INCH_PER_FEET + inch) * METER_PER_INCH;
	float weight = pound / POUND_PER_KILO;
	cout << "height: " << height << "(m), weight: " << weight << "(kg), BMI: " << weight / height / height << endl;
}