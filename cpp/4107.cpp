#include <iostream>

int main()
{
	using namespace std;

	struct fish
	{
		char category[10];
		int weight;
		float length;
	};

	fish a_fish = {"金鱼", 1, 30};
	cout << a_fish.category << endl
		<< a_fish.weight << endl
		<< a_fish.length << endl;
		
	return 0;
}