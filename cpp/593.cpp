#include <iostream>

int main()
{
	using namespace std;

	float total1 = 100;
	float total2 = 100;
	int after_years = 0;
	while(total1 >= total2)
	{
		total1 += 100 * 0.1;
		total2 += total2 * 0.05;
		after_years++;
	}

	cout << after_years << " years later: " << endl
		<< "Daphne has " << total1 << endl
		<< "Cleo has " << total2 << endl;

	return 0;
}