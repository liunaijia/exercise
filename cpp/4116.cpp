#include <iostream>

int main()
{
	using namespace std;

	struct  CandyBar 
	{
		string brand;
		float weight;
		int calorie;
	};

	CandyBar snacks[3] = {
			{"A", 2.3, 350},
			{"B", 3.3, 250},
			{"C", 4.4, 150}
		};
	for(int i = 0; i < sizeof(snacks) / sizeof(CandyBar); i++)
	{
		CandyBar snack = snacks[i];
		cout << snack.brand << endl
			<< snack.weight << endl
			<< snack.calorie << endl;
	}

	return 0;
}