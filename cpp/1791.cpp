#include <iostream>

using namespace std;

int main() {
	int count = 0;
	while(cin.get() != '$') {
		count++;
	}
	cin.putback('$');
	char c;
	cin >> c;
	cout << count << " next char: " << c;
	return 0;
}