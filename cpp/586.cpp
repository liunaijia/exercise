#include <iostream>

int main()
{
	using namespace std;

	int number = 1;
	for(int i = 0; i < 7; i++)
	{
		cout << number << " ";
		number *= 2;
	}

	return 0;
}