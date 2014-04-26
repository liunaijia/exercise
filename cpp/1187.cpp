#include <iostream>
#include <cmath>

using namespace std;

class Vector {
private:
	double x;
	double y;
	double mag;
	double ang;
	char mode;
public:
	Vector(double x, double y, char mode = 'r');
	operator double();
};

Vector::Vector(double x, double y, char mode) {
	if (mode == 'r') {
		this->x = x;
		this->y = y;
		mag = sqrt(x * x + y * y);
		if (x == 0 && y == 0)
			ang = 0;
		else
			ang = atan2(y, x);
		mode = mode;
	}
}

Vector::operator double() {
	return this->mag;
}

int main() {
	Vector v(1, 1);
	double x = v;
	cout << x;
	return 0;
}