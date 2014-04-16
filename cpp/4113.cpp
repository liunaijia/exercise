#include <iostream>
#include <cstring>

int main()
{
	using namespace std;

	cout << "Enter your first name: ";
	char first_name[10];
	cin.getline(first_name, 10);

	cout << "Enter your last name: ";
	char last_name[10];
	cin.getline(last_name, 10);

	char full_name[22] = {'\0'};
	strcat(full_name, last_name);
	strcat(full_name, ", ");
	strcat(full_name, first_name);

	cout << "Here's the information in a single string: " << full_name;

	return 0;
}