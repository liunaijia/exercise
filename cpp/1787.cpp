#include <iostream>
#include <iomanip>

using namespace std;

int main() {
	cout << "Enter your name: ";
	string name = "lnj";
	getline(cin, name);

	float wages = 12;
	cout << "Enter your hourly wages: ";
	cin >> wages;

	float hours = 7.5;
	cout << "Enter number of hours worked: ";
	cin >> hours;

	cout << endl;
	cout << "First format:" << endl;
	cout << setw(20) << name << ": $"
		<< setw(10) << fixed << setprecision(2) << wages
		<< ":" << setw(5) << hours << endl;

	cout << "Second format:" << endl;
	cout << setw(20) << left << name << ": $"	
		<< setw(10) << fixed << setprecision(2) << wages
		<< ":" << setw(5) << hours << endl;

	return 0;
}
