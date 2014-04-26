#include <iostream>
#include <cstring>

using namespace std;

template<typename T> T maxn(T array[], int n);
template<> const char* maxn(const char* array[], int n);

int main(){
	int array1[] = {1, 3, 4, 5, 6, 3};
	cout << maxn(array1, 6) << endl;

	double array2[] = {6.2, 39.1, -93.3, 2};
	cout << maxn(array2, 4) << endl;

	const char* strings[] = {"hello", "me", "wish", "world", "you"};
	cout << maxn(strings, 5) << endl;

	return 0;
}

template<typename T> T maxn(T array[], int n) {
	T max = array[0];
	for(int i = 1; i < n; i++)
		if (array[i] > max)
			max = array[i];

	return max;
}

template<> const char* maxn(const char* array[], int n) {
	const char* max = array[0];
	for(int i = 1; i < n; i++)
		if (strlen(array[i]) > strlen(max) ||
			strlen(array[i]) == strlen(max) && array[i] > max)
			max = array[i];

	return max;
}