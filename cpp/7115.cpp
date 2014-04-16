#include <iostream>

int main() {
	using namespace std;
	
	double max(const double array[], int length);

	double array[] = {-2.9, 2.4, 45};
	cout << max(array, 3);

	return 0;
}

double max(const double array[], int length) {
	if (length == 0)
		return 0;
	double max_value = array[0];
	for(int i = 1; i < length; i++) {
		if (array[i] > max_value)
			max_value = array[i];
	}
	return max_value;
}