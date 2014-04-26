#include <iostream>

int main()
{
	using namespace std;

	struct Pizza
	{
		char name[50];
		int size;
		int weight;
	};

	Pizza* p = new Pizza;

	cout << "size: ";
	cin >> p -> size;

	cout << "name: ";
	cin.get();
	cin.getline(p -> name, 50);
	
	cout << "weight: ";
	cin >> p -> weight;

	cout << p -> name << " " << p -> size << " " << p -> weight;

	delete p;

	return 0;
}