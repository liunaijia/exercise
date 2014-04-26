#include <iostream>

int main()
{
	using std::cout;
	using std::cin;

	void show_time(int, int);

	int hour, minute;
	cout << "Enter the number of hours: ";
	cin >> hour;

	cout << "Enter the number of minutes: ";
	cin >> minute;

	show_time(hour, minute);
}

void show_time(int hour, int minute)
{
	using std::cout;
	cout << "Time: " << hour << ":" << minute;
}