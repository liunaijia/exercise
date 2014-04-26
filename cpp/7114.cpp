#include <iostream>

using namespace std;

int main()
{
	void init_array(int*, int*, int);
	void show_array(const int*, const int*);

	int* array = new int[5];
	show_array(array, array + 5);
	cout << endl;

	init_array(array, array + 5, 3);
	show_array(array, array + 5);
	cout << endl;

	delete [] array;

	return 0;
}

void init_array(int* begin, int* end, int x)
{
	for(int* p = begin; p < end; p++)
		*p = x;
}

void show_array(const int* begin, const int* end)
{
	for(const int* p = begin; p < end; p++)
	{
		cout << *p;
		if (p < end - 1)
			cout << ",";
	}
}