#include <iostream>

int main()
{
	using namespace std;

	cout << "What is your first name? ";
	char first_name[10];
	cin.getline(first_name, 10);

	cout << "What is your last name? ";
	char last_name[10];
	cin.getline(last_name, 10);

	cout << "What letter grade do you deserve? ";
	char letter;
	cin >> letter;

	cout << "What is your age? ";
	int age;
	cin >> age;

	cout << "Name: " << last_name << ", " << first_name << endl
		<< "Grade: " << (char)(letter + 1) << endl
		<< "Age: " << age << endl;

	return 0;
}