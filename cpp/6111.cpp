#include <iostream>

int main()
{
	using namespace std;

	char ch;
	while((ch = cin.get()) != '@')
	{
		if (ch >= '0' && ch <= '9')
			continue;

		if (isalpha(ch))
			cout << (char)(islower(ch) ? toupper(ch) : tolower(ch));
		else
			cout << ch;
	}

	return 0;
}