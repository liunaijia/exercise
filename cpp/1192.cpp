#include <cmath>
#include <iostream>

using namespace std;

class Vector {
private:
	static const double RAD_TO_DEG = 57.2957795130823;
	double x;
	double y;
public:
	Vector(double x = 0, double y = 0);
	double mag() const;
	double ang() const;
	friend ostream& operator<<(ostream& out, const Vector v);
};

Vector::Vector(double x, double y) {
	this->x = x;
	this->y = y;
}

double Vector::mag() const {
	return sqrt(x * x + y * y);
}

double Vector::ang() const {
	if (x == 0 && y == 0)
		return 0;
	else
		return atan2(y, x);
}

int main() {
    Vector v(1, 1);
    cout << v.mag() << " " << v.ang();

	return 0;
}
