#include <iostream>

int main()
{
	using namespace std;

	int abs(int);
	cout << abs(123) << endl;
	cout << abs(0) << endl;
	cout << abs(-10) << endl;

	return 0;
}

int abs(int x)
{
	return x > 0 ? x : -x;
}