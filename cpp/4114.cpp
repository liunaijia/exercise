#include <iostream>

int main()
{
	using namespace std;

	cout << "Enter your first name: ";
	string first_name;
	cin >> first_name;

	cout << "Enter your last name: ";
	string last_name;
	cin >> last_name;

	string full_name = last_name + ", " + first_name;

	cout << "Here's the information in a single string: " << full_name;

	return 0;
}