#include <iostream>

using namespace std;

int main() {
	int fill_array(double array[], int max_length);
	void show_array(const double array[], int length);
	void reverse_array(double array[], int length);
	
	double array[5];

	cout << "input array: ";
	int length = fill_array(array, 5);
	cout << "fill array: ";
	show_array(array, length);

	reverse_array(array, length);
	cout << endl << "reverse array: ";
	show_array(array, length);

	reverse_array(array + 1, length - 2);
	cout << endl << "reverse array: ";
	show_array(array, length);

	return 0;
}

int fill_array(double array[], int max_length) {
	int length = 0;
	while(length < max_length) {
		if (!(cin >> array[length]))
			break;
		length++;
	}
	return length;
}

void show_array(const double array[], int length) {
	for (int i = 0; i < length; i++) {
		cout << array[i];
		if (i < length - 1)
			cout << ", ";
	}
}

void reverse_array(double array[], int length) {
	for (int i = 0, j = length - 1; i < j; i++, j--) {
		double temp = array[i];
		array[i] = array[j];
		array[j] = temp;
	}
}