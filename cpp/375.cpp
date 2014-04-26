#include <iostream>

int main()
{
	using namespace std;

	int miles, gallons;
	cout << "Enter miles: ";
	cin >> miles;
	cout << "Enter gallons: ";
	cin >> gallons;
	cout << (float)miles / gallons << " miles per gallon" << endl;

	int km, litre;
	cout << "Enter km: ";
	cin >> km;
	cout << "Enter litre: ";
	cin >> litre;
	cout << 100.0 * litre / km << " litre / 100km" << endl;
}