#include <iostream>

using namespace std;

int call_times = 0;
void print(char* s, int sw = 0, int& t = call_times);

int main() {
	char* s = (char*)"hi";
	print(s);
	cout << "-----" << endl;
	print(s, 1);
	cout << "-----" << endl;
	print(s, 1);
	cout << "-----" << endl;
	print(s);
	cout << "-----" << endl;
	print(s, 1);
	return 0;
}

void print(char* s, int sw, int& t) {
	if (sw) {
		t++;
		for(int i = 0; i < t; i++)
			cout << s << endl;
	}
	else{
		cout << s << endl;
	}
}