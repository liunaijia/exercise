#include <iostream>

using namespace std;

class Frabjous {
private:
	char fab[20];
public:
	Frabjous(const char* s = "C++") {
		strncpy(fab, s, 19);
		fab[19] = '\0';
	}
	virtual void tell() const {cout << fab;}
};

class Gloam {
private:
	int glip;
	Frabjous fb;
public:
	Gloam(int g = 0, const char* s = "C++");
	Gloam(int g, const Frabjous& f);
	void tell();
};

Gloam::Gloam(int g, const char* s) {
	glip = g;
	fb = Frabjous(s);
}

Gloam::Gloam(int g, const Frabjous& f) {
	glip = g;
	fb = f;
}

void Gloam::tell() {
	cout << "glip:" << glip << "\tfb:";
	fb.tell();
	cout << endl;
}

int main() {
	Gloam g1;
	g1.tell();

	Gloam g2(100, "java");
	g2.tell();

	Frabjous f(".net");
	Gloam g3(300, f);
	g3.tell();

	return 0;
}