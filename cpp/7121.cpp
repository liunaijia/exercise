#include <iostream>

int main() {
	using namespace std;

	double avg(double x, double y);

	double x, y;
	while(true) {
		cout << "input x, y:";
		if (!(cin >> x >> y) || x == 0 || y == 0)
			break;
		cout << avg(x, y) << endl;
	}
	return 0;
}

double avg(double x, double y) {
	return 2.0 * x * y / (x + y);
}