#include <iostream>
#include <cstring>
using namespace std;

class Plorg {
private:
	static const int LEN = 19;
	char name[LEN];
	int ci;
public:
	Plorg(const char* name = "Plorga", int ci = 50);
	void Set(int ci);
	void Show() const;
};

Plorg::Plorg(const char* name, int ci) {
	strncpy(this->name, name, LEN - 1);
	this->name[LEN - 1] = '\0';
	this->ci = ci;
}

void Plorg::Set(int ci) {
	this->ci = ci;
}

void Plorg::Show() const {
	cout << name << "\t" << ci << endl;
}

int main() {
	Plorg p;
	p.Show();

	Plorg p1("someone", 11);
	p1.Show();
	p1.Set(12);
	p1.Show();
	
	return 0;
}