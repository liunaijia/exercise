#include <ctime>
#include <cstdlib>
#include <cmath>
#include <iostream>

using namespace std;

struct step_stat
{
	int min;
	int max;
	int avg;
	friend ostream& operator<<(ostream& out, const step_stat s);
};

ostream& operator<<(ostream& out, const step_stat s) {
	return out << "min:" << s.min << "\t max:" << s.max << "\tavg:" << s.avg << endl;
}

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

step_stat test_walk(double target, double step_length, int times);

int main() {
    srand(time(0));

	double target;
	cout << "Enter target distance (q to quit): ";
	while(cin >> target) {
		double step_length;
		cout << "Enter step length: ";
		if (!(cin >> step_length))
			break;

		int times;
		cout << "Enter test times: ";
		if (!(cin >> times))
			break;

		step_stat stat = test_walk(target, step_length, times);
		cout << stat << endl;
		
		cout << "Enter target distance (q to quit): ";
	}
	cout << "done.";

	return 0;
}



step_stat test_walk(double target, double step_length, int times) {
	int walk(double target, double step_length);
	step_stat stat;

	unsigned long total_steps = 0;
	int* steps_array = new int[times];
	for(int i = 0; i < times; i++) {
		steps_array[i] = walk(target, step_length);

		if (i == 0 || stat.min > steps_array[i])
			stat.min = steps_array[i];
		if (i == 0 || stat.max < steps_array[i])
			stat.max = steps_array[i];
		total_steps += steps_array[i];
	}
	stat.avg = total_steps / times;
	delete [] steps_array;
	return stat;
}

int walk(double target, double step_length) {
	// out << "Target Distance: " << target << ", Step Size: " << step_length << endl;
	Vector result;
	unsigned long steps = 0;
	while(result.magval() < target) {
		double direction = rand() % 360;
		Vector step(step_length, direction, 'p');
		result = result + step;

		//out << steps << ": " << result.set_mode('r') << endl;
		steps++;
	}
	return steps;
	// out << "After " << steps << " steps, the subject has the following location:" << endl;
	// out << result.set_mode('r') << endl;
	// out << "or" << endl;
	// out << result.set_mode('p') << endl;
	// out << "Average outward distance per step = " << result.magval() / steps << endl;
}