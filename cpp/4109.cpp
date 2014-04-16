#include <iostream>

int main()
{
	using namespace std;

	double ted = 123.4;
	double* p_ted = &ted;
	cout << *p_ted;

	return 0;
}