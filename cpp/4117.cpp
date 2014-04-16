#include <iostream>

int main()
{
	using namespace std;

	struct Pizza
	{
		string name;
		int size;
		int weight;
	} p;

	cout << "name: ";
	cin >> p.name;
	cout << "size: ";
	cin >> p.size;
	cout << "weight: ";
	cin >> p.weight;

	cout << p.name << " " << p.size << " " << p.weight;

	return 0;
}