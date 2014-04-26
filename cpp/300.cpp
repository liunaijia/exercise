#include <iostream>
#include <climits>

int main()
{
	using namespace std;

	cout << sizeof(bool) << endl;
	cout << sizeof(char) << endl;
	cout << sizeof(short) << endl;
	cout << sizeof(int) << endl;
	cout << sizeof(long) << endl;
	cout << sizeof(long long) << endl;

	cout << SHRT_MIN << endl;
	cout << INT_MAX << endl;
	cout << LONG_MAX << endl;
	cout << LONG_LONG_MAX << endl;

	int x;
	cout << x << endl;

	unsigned char c = 255;
	cout << (int)c << endl;

	cout << 0x64 << endl;

	double f = 1.0 / 3E6;
	cout.setf(ios_base::fixed, ios_base::floatfield);
	cout << f;
}