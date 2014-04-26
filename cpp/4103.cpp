#include <iostream>

int main()
{
	using namespace std;

	int numbers[5] = {1, 3, 5, 7, 9};

	int even = numbers[0] + numbers[sizeof(numbers) / sizeof(int) - 1];
	cout << even;
		
	return 0;
}