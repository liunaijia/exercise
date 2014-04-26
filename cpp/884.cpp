#include <iostream>
#include <cstring>

using namespace std;

struct stringy
{
	char* str;
	int ct;	// length
};

void set(stringy&, char[]);
void show(const stringy& stringy, int times = 1);
void show(const char str[], int times = 1);

int main() {
	stringy beany;
	char testing[] = "Reality isn't what it used to be.";

	set(beany, testing);
	show(beany);
	show(beany, 2);

	testing[0] = 'D';
	testing[1] = 'u';

	show(testing);
	show(testing, 3);
	show("Done!");

	return 0;
}

void set(stringy& stringy, char str[]) {
	stringy.ct = strlen(str);
	stringy.str = new char[stringy.ct];
	strcpy(stringy.str, str);
}

void show(const stringy& stringy, int times) {
	for(int i = 0; i < times; i++)
		cout << stringy.str << "[" << stringy.ct << "]" << endl;
}

void show(const char str[], int times) {
	for(int i = 0; i < times; i++)
		cout << str << endl;
}