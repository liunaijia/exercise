#include <iostream>
#include <fstream>

int main()
{
	using namespace std;

	struct contributor
	{
		char name[80];
		double amount;
	};

	ifstream fin;
	fin.open("6118.txt");

	int numbers;
	if (fin >> numbers)
	{
		contributor* contributors = new contributor[numbers];

		for(int i = 0; i < numbers; i++)
		{
			fin.get();
			fin.getline(contributors[i].name, 80);
			fin >> contributors[i].amount;
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
	}

	fin.close();

	return 0;
}