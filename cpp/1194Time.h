#include <iostream>

class Time {
private:
	int hours;
	int minutes;
public:
	Time(int hours = 0, int minutes = 0);
	friend Time operator+(const Time& t1, const Time& t2);
	friend Time operator-(const Time& t1, const Time& t2);
	friend Time operator*(const Time& t1, double m);
	friend std::ostream& operator<<(std::ostream& out, const Time& t);
};