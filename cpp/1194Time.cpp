#include <iostream>
#include "1194Time.h"

Time::Time(int hours, int minutes) {
	this->hours = hours + minutes / 60;
	this->minutes = minutes % 60;
}

Time operator+(const Time& t1, const Time& t2) {
	Time t(t1.hours + t2.hours, t1.minutes + t2.minutes);
	return t;
}

Time operator-(const Time& t1, const Time& t2) {
	Time t(0, t1.hours * 60 + t1.minutes - (t2.hours * 60 + t2.minutes));
	return t;
}

Time operator*(const Time& t1, double m) {
	Time t(t1.hours * m, t1.minutes * m);
	return t;
}

std::ostream& operator<<(std::ostream& out, const Time& t) {
	return out << t.hours << ":" << t.minutes;
}

int main() {
	using namespace std;

	Time t1(1, 30);
	Time t2(3, 40);
	cout << t1 + t2 << endl;
	cout << t1 - t2 << endl;
	cout << t2 - t1 << endl;
	cout << t2 * 2 << endl;
	return 0;
}