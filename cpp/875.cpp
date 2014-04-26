#include <iostream>

using namespace std;

double mass(double density, double volume = 1.0);
void repeat(int times, char s[]);
void repeat(char s[]);
int average(int, int);
double average(double, double);
char mangle1(char s[]);
char* mangle2(char s[]);

int main() {
	cout << mass(2.3, 2) << endl;
	cout << mass(1.0) << endl;

	repeat(10, (char*)"I'm OK");
	repeat((char*)"But your'r kind of stuqid");

	cout << average(3, 6) << endl;
	cout << average(3.0, 6.0) << endl;

	cout << mangle1((char*)"I'm glad to meet you") << endl;
	cout << mangle2((char*)"I'm glad to meet you") << endl;

	return 0;
}


double mass(double density, double volume) {
	return density * volume;
}

void repeat(int times, char s[]) {
	for(int i = 0; i < times; i++)
		cout << s << endl;
}

void repeat(char s[]) {
	repeat(5, s);
}

int average(int a, int b) {
	return (a + b) / 2;
}

double average(double a, double b) {
	return (a + b) / 2;
}

char mangle1(char s[]) {
	return s[0];
}
char* mangle2(char s[]) {
	return s;
}