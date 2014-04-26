#include <iostream>

int main()
{
	using namespace std;

	int inches;
	cout << "Enter your height in inches:___\b\b\b";
	cin >> inches;

	const float FACTOR = 12.0;
	cout.setf(ios_base::fixed, ios_base::floatfield);
	cout << "Your height is " << inches << " inches, and " << inches / FACTOR << " feet.";
}