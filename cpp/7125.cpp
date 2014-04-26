#include <iostream>

using namespace std;


int main() {
	long long func(int n);
	
	int n;
	cout << "input n: ";
	while(cin >> n) {
		cout << func(n) << endl;
		cout << "input n: ";
	}
	return 0;
}

long long func(int n) {
	if (n == 1)
		return 1;
	else
		return func(n - 1) * n;
}