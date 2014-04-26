#include <iostream>

int main()
{
	using namespace std;

	unsigned long seconds;
	cout << "Enter the number of seconds: ";
	cin >> seconds;

	const int HOURS_PER_DAY = 24.0;
	const int MINUTES_PER_HOUR = 60.0;
	const int SECONDS_PER_MINUTE = 60.0;

	float days = seconds / (SECONDS_PER_MINUTE * MINUTES_PER_HOUR * HOURS_PER_DAY);
	float hours = seconds / (SECONDS_PER_MINUTE * MINUTES_PER_HOUR) % HOURS_PER_DAY;
	float minutes = seconds / SECONDS_PER_MINUTE % MINUTES_PER_HOUR;
	float sec = seconds % SECONDS_PER_MINUTE;
	cout << seconds << " seconds = " << days << " days, " << hours << " hours, " << minutes << " minutes, " << sec << " seconds";
}