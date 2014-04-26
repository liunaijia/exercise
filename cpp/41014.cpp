#include <iostream>

int main()
{
	using namespace std;

	cout << "year: ";
	int year;
	cin >> year;

	cout << "address: ";
	char address[80];
	//cin.getline(address, 80);
	cin >> address;	// cause memory problem when input string length over size of address.

	cout << year << " " << address << endl;

	return 0;
}