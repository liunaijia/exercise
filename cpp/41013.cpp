#include <iostream>
#include <cstring>

int main()
{
	using namespace std;

	struct fish
	{
		char category[10];
		int weight;
		float length;
	};
		
	fish* p_fish = new fish;
	strcpy(p_fish -> category, "金鱼");
	p_fish -> weight = 1;
	p_fish -> length = 1.1;

	cout << p_fish -> category << endl
		<< p_fish -> weight << endl
		<< p_fish -> length << endl;

	delete p_fish;

	return 0;
}