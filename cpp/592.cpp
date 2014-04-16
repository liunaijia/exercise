#include <iostream>

int main()
{
	using namespace std;

	int n, sum = 0;
	do
	{
		cin >> n;
		sum += n;
	}while(n != 0);

	cout << sum;

	return 0;
}