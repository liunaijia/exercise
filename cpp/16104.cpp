#include <iostream>
#include <algorithm>

using namespace std;

int main() {
	int reduce(long array[], int n);

	long array[] = {1, 1, 4, 3, 2};
	int length = reduce(array, 5);
	for(int i = 0; i < length; i++)
		cout << array[i] << " ";
	return 0;
}

int reduce(long array[], int n) {
	sort(array, array + n);
	auto it = unique(array, array + n);
	return distance(array, it);
}