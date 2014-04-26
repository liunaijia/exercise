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

int main() {
	void show(const box& box);
	box b = {"xiaomi", 1.5, 10, 10, 300};
	show(b);

	void cacl_volume(box& box);
	cacl_volume(b);
	show(b);
	return 0;
}

void show(const box& box) {
	cout << box.maker << "\t" << box.height << "x" << box.width << "x" << box.length << "\t" << box.volume << endl;
}

void cacl_volume(box& box) {
	box.volume = box.height * box.width * box.length;
}