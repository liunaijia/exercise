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
	void show_by_value(const box box);
	void cacl_volume(box* box);

	box box = {"xiaomi", 1.5, 10, 10, 250};
	show_by_value(box);
	cacl_volume(&box);
	show_by_value(box);

	return 0;
}

void show_by_value(const box box) {
	cout << box.maker
	<< "\t(" << box.height << " x " << box.width << " x " << box.height
	<< ")\t" << box.volume << endl;
}

void cacl_volume(box* box) {
	box -> volume = box -> height * box -> width * box -> length;
}