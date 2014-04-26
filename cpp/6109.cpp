#include <iostream>

int main()
{
	using namespace std;

	int line = 0;
	char ch;
	while((ch = cin.get()) != 'Q')
	{
		if (ch == '\n')
			line++;
	}

	cout << line;

	return 0;
}