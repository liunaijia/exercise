#include <iostream>
#include <string>

using namespace std;

void iquote(int);
void iquote(double);
void iquote(string);

int main() {
	iquote(1);
	iquote(2.3);
	iquote("me");

	return 0;
}

void iquote(int x) {
	cout << "\"" << x << "\"" << endl;
}
void iquote(double x) {
	cout << "\"" << x << "\"" << endl;
}
void iquote(string x) {
	cout << "\"" << x << "\"" << endl;
}