#include <iostream>

using namespace std;

struct CandyBar
{
	char* brand;
	double weight;
	int calories;
};

void init(CandyBar& candy_bar, const char* brand = "Millennium Munch", const double weight = 2.85, const int calories = 350);
void show(const CandyBar& cb);

int main() {
	CandyBar cb;
	init(cb);
	show(cb);
	return 0;
}

void init(CandyBar& cb, const char* brand, const double weight, const int calories) {
	cb.brand = (char*)brand;
	cb.weight = weight;
	cb.calories = calories;
}

void show(const CandyBar& cb) {
	cout << cb.brand << "\t" << cb.weight << "\t" << cb.calories << endl;
}