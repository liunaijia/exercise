#include <iostream>

int main()
{
	using namespace std;

	int numbers;
	cout << "input numbers: ";
	cin >> numbers;

	struct contributor
	{
		string name;
		double amount;
	};

	contributor* contributors = new contributor[numbers];

	for(int i = 0; i < numbers; i++)
	{
		cout << "#" << i + 1 << endl;
		cout << "\tname: ";
		cin >> contributors[i].name;
		cout << "\tamount: ";
		cin >> contributors[i].amount;
	}

	// over 10000
	cout << "[Grand Patrons]" << endl;
	for(int i = 0; i < numbers; i++)
	{
		if (contributors[i].amount >= 10000)
			cout << contributors[i].name << "\t" << contributors[i].amount << endl;
	}


	// below 10000
	cout << "[Patrons]" << endl;
	for(int i = 0; i < numbers; i++)
	{
		if (contributors[i].amount < 10000){
			cout << contributors[i].name << "\t";
			if (contributors[i].amount > 0)
			 	cout << contributors[i].amount;
			 else
			 	cout << "none";
			 cout << endl;
		}
	}

	delete [] contributors;

	return 0;
}