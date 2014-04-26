#include <iostream>

int main()
{
	using namespace std;

	struct CandyBar 
	{
		string brand;
		float weight;
		int calorie;
	};

	CandyBar* snacks = new CandyBar[3];
	
	snacks[0].brand = "A";
	snacks[0].weight = 2.3;
	snacks[0].calorie = 350;
	
	snacks[1].brand = "B";
	snacks[1].weight = 3.3;
	snacks[1].calorie = 250;

	snacks[2].brand = "C";
	snacks[2].weight = 4.4;
	snacks[2].calorie = 150;
	
	for(int i = 0; i < 3; i++)
	{
		CandyBar snack = snacks[i];
		cout << snack.brand << endl
			<< snack.weight << endl
			<< snack.calorie << endl;
	}

	delete [] snacks;

	return 0;
}