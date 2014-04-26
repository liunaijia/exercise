#include <iostream>

int main()
{
	using namespace std;

	enum Response
	{
		Yes = 1,
		No = 0,
		Maybe = 2
	};

	Response r = Maybe;
	cout << r;

	return 0;
}