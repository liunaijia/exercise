#include <iostream>

using namespace std;

void song(char* name = "O. My Papa", int times = 1);

int main() {
	char name[] = "hi";
	song(name, 3);

	cout << endl;
	song(name);
	
	cout << endl;
	song();

	return 0;
}

void song(char* name, int times) {
	for(int i = 0; i < times; i++)
		cout << name << endl;
}