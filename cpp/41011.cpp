#include <iostream>

int main()
{
	using namespace std;

	int size;
	cout << "input size of array: ";
	cin >> size;

	int* p_array = new int[size];
	delete [] p_array;

	return 0;
}