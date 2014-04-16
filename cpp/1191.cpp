#include <ctime>
#include <cstdlib>
#include <cmath>
#include <iostream>
#include <fstream>

using namespace std;

class Vector {
private:
	static const double RAD_TO_DEG = 57.2957795130823;
	double x;
	double y;
	double mag;
	double ang;
	char mode;
public:
	Vector(double n1 = 0, double n2 = 0, char mode = 'r');
	void set(double n1 = 0, double n2 = 0, char mode = 'r');
	Vector operator+(const Vector& v) const;
	double magval() const;
	Vector& set_mode(char mode);
	friend ostream& operator<<(ostream& out, const Vector v);
};

void Vector::set(double n1, double n2, char mode) {
	if (mode == 'r') {
		x = n1;
		y = n2;
		mag = sqrt(x * x + y * y);
		if (x == 0 && y == 0)
			ang = 0;
		else
			ang = atan2(y, x);
		this->mode = mode;
	}
	else if (mode == 'p') {
		mag = n1;
		ang = n2 / RAD_TO_DEG;
		x = mag * cos(ang);
		y = mag * sin(ang);
		this->mode = mode;
	}
	else{
		x = 0;
		y = 0;
		mag = 0;
		ang = 0;
		this->mode = 'r';
	}
}

Vector::Vector(double n1, double n2, char mode) {
	this->set(n1, n2, mode);
}

Vector Vector::operator+(const Vector& v) const {
	return Vector(x + v.x, y + v.y);
}

double Vector::magval() const {
	return mag;
}

Vector& Vector::set_mode(char mode) {
	this->mode = mode;
	return *this;
}

ostream& operator<<(ostream& out, const Vector v) {
	if (v.mode == 'p')
		return out << "(m, a) = (" << v.mag << ", " << v.ang << ")";
	else
		return out << "(x, y) = (" << v.x << ", " << v.y << ")";
}

void process(double target, double step_length, Vector& result, ostream& out, unsigned long& steps);

int main() {
	ofstream fout;
    fout.open("d:\\data.txt");
    
    srand(time(0));
	unsigned long steps = 0;
	double target;
	double step_length;
	Vector result;
	cout << "Enter target distance (q to quit): ";
	while(cin >> target) {
		cout << "Enter step length: ";
		if (!(cin >> step_length))
			break;

		process(target, step_length, result, fout, steps);

		steps = 0;
		result.set();
		cout << "Enter target distance (q to quit): ";
	}
	cout << "done.";

	fout.close();    // 操作完毕后一定要关闭文件。

	return 0;
}

void process(double target, double step_length, Vector& result, ostream& out, unsigned long& steps) {
	out << "Target Distance: " << target << ", Step Size: " << step_length << endl;

	while(result.magval() < target) {
		double direction = rand() % 360;
		Vector step(step_length, direction, 'p');
		result = result + step;

		out << steps << ": " << result.set_mode('r') << endl;
		steps++;
	}
	out << "After " << steps << " steps, the subject has the following location:" << endl;
	out << result.set_mode('r') << endl;
	out << "or" << endl;
	out << result.set_mode('p') << endl;
	out << "Average outward distance per step = " << result.magval() / steps << endl;
}