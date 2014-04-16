#include <iostream>

using namespace std;
template<typename T> T max1(T a, T b);

int main() {
	cout << max1(1, 2) << endl;
	cout << max1('A', 'B') << endl;
	return 0;
}

template<typename T> T max1(T a, T b) {
	return a > b ? a : b;
}