#include <iostream>

int main()
{
	using namespace std;

	int n1;
	cout << "input number1: ";
	cin >> n1;

	int n2;
	cout << "input number2: ";
	cin >> n2;

	int sum = 0;
	for(int i = n1; i <= n2; i++)
	{
		sum += i;
	}
	cout << sum;

	return 0;
}