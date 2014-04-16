#include <iostream>

int main()
{
	using namespace std;

	char ch;
	int ct1, ct2;

	ct1 = ct2 = 0;
	while((ch = cin.get()) != '$')
	{
		cout << ch;
		ct1++;
		if (ch = '$')	// what's this?!
			ct2++;
		cout << ch;
	}
	cout << "ct1 = " << ct1 << ", ct2 = " << ct2 << "\n";

	return 0;
}