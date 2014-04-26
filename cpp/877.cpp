#include <iostream>

using namespace std;

struct box
{
	char maker[40];
	float height;
	float width;
	float length;
	float volume;
};

template<typename T> T max1(const T a, const T b);
template<> box max1(const box a, const box b);

int main() {
	cout << max1(1, 2) << endl;
	cout << max1('A', 'B') << endl;

	box box1 = {"xiaomi", 1.5, 10, 10, 150};
	box box2 = {"dami", 2, 10, 10, 200};
	box bigger = max1(box1, box2);
	cout << bigger.maker << endl;

	return 0;
}

template<typename T> T max1(const T a, const T b) {
	return a > b ? a : b;
}

template<> box max1(const box a, const box b) {
	return a.volume > b.volume ? a : b;
}