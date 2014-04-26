#include <iostream>

int main()
{
	using namespace std;

	int degrees, minutes, seconds;
	cout << "Enter a latitude in degrees, minutes, and seconds:" << endl
		<< "First, enter the degrees: ";
	cin >> degrees;

	cout << "Next, enter the minutes of arc: ";
	cin >> minutes;

	cout << "Finally, enter the seconds of arc: ";
	cin >> seconds;

	const float MINUTES_PER_DEGREE = 60.0;
	const float SECONDS_PER_MINUTE = 60.0;
	float d = degrees + minutes / MINUTES_PER_DEGREE + seconds / SECONDS_PER_MINUTE / MINUTES_PER_DEGREE;
	
	cout << degrees << " degrees, " << minutes << " minutes, " << seconds << " seconds = " << d << " degrees";
}