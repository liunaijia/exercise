#include <iostream>

using namespace std;

template<typename T> T max5(T array[]);

int main(){
	int array1[] = {1, 3, 4, 5, 6};
	cout << max5(array1) << endl;

	double array2[] = {6.2, 39.1, 359.3, -93.3, 2};
	cout << max5(array2) << endl;

	return 0;
}

template<typename T> T max5(T array[]) {
	T max = array[0];
	for(int i = 1; i < 5; i++)
		if (array[i] > max)
			max = array[i];

	return max;
}