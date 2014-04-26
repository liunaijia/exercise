#include <iostream>
#include <new>

using namespace std;

struct chaff
{
	char dross[20];
	int slag;
};

void init(chaff* p, int size);
void show(const chaff* p, int size);

int main() {
	char buffer[1024];

	cout << "buffer @ " << &buffer << endl;
	chaff* p1 = new (buffer)chaff[2];
	init(p1, 2);
	show(p1, 2);

	chaff* p2 = new chaff[2];
	init(p2, 2);
	show(p2, 2);

	return 0;
}

void init(chaff* p, int size) {
	for(int i = 0; i < size; i++) {
		strcpy(p[i].dross, "dross");
		p[i].slag = i;
	}
}

void show(const chaff* p, int size) {
	for(int i = 0; i < size; i++) {
		cout << "#" << i + 1 << " @" << &p[i] << endl;
		cout << p[i].dross << "\t" << p[i].slag << endl;
	}
}