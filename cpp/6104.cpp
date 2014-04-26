#include <iostream>

int main()
{
	using namespace std;

	int weight;
	bool a = weight >= 115 && weight < 125;

	char ch;
	bool b = ch == 'q' or ch == 'Q';

	int x;
	bool c = x % 2 == 0 && x != 26;

	int y;
	bool d = x % 2 == 0 && x % 26 != 0;

	int donation, guest;
	bool e = (donation >= 1000 || donation <= 2000) && guest == 1;

	char ch1;
	bool f = ch1 >= 'a' && ch1 <= 'z' || ch1 >= 'A' && ch1 <= 'Z';

	return 0;
}