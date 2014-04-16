#include <iostream>

using namespace std;

int main()
{
	void init_array(int[], int, int);
	void show_array(const int[], int);

	int array[5];
	show_array(array, 5);
	cout << endl;

	init_array(array, 5, 3);
	show_array(array, 5);
	cout << endl;	

	return 0;
}

void init_array(int array[], int length, int x)
{
	for(int i = 0; i < length; i++)
	{
		array[i] = x;
	}
}

void show_array(const int array[], int length)
{
	for(int i = 0; i < length; i++)
	{
		cout << array[i];
		if (i < length - 1)
			cout << ",";
	}
}