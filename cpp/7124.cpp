#include <iostream>

int main() {
	double ratio(int total, int pick);

	std::cout << ratio(47, 5) * ratio(27, 1);

	return 0;
}

double ratio(int total, int pick) {
	double ratio = 1;
	for(int i = 0; i < pick; i++) {
		ratio *= (total - i) / (i + 1);
	}
	return ratio;
}