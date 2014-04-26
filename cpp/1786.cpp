#include <iostream>
#include <iomanip>

using namespace std;

int main() {
	void show(int i);
	show(100);
	return 0;
}

void show(int i) {
	cout << setw(15) << "0x" << hex << i
		<< setw(15) << "0" << oct << i
		<< setw(15) << dec << i << endl;
}