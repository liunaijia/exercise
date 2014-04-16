#include <iostream>
#include <algorithm>

using namespace std;

template<typename T> int reduce(T array[], int n);

int main() {
	long array[] = {1, 1, 4, 3, 2};
	int length = reduce<long>(array, 5);
	for(int i = 0; i < length; i++)
		cout << array[i] << " ";
	cout << endl;

	string strings[] = {"girl", "lady", "boy", "dog", "moon"};
	int length2 = reduce<string>(strings, 5);
	for(int i = 0; i < length2; i++)
		cout << strings[i] << " ";

	return 0;
}

template<typename T>
int reduce(T array[], int n) {
	sort(array, array + n);
	auto it = unique(array, array + n);
	return distance(array, it);
}