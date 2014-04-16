#include <iostream>

int main()
{
	using namespace std;

	struct car
	{
		string make;
		int year;
	};

	int number;
	cout << "How many cars do you wish to catalog? ";
	cin >> number;
	car* cars = new car[number];

	for(int i = 0; i < number; i++)
	{
		cout << "Car #" << i + 1 << ":" << endl
			<< "Please enter the make: ";
		char make[80];
		cin.get();
		cin.getline(make, 80);
		cars[i].make = make;

		cout << "Please enter the year made: ";
		cin >> cars[i].year;
	}

	cout << "Here is your collection: " << endl;
	for(int i = 0; i < number; i++)
	{
		cout << cars[i].year << " " << cars[i].make << endl;
	}

	delete [] cars;

	return 0;
}