#include <iostream>
#include <cstring>
using namespace std;

class Golf {
private:
	static const int Len = 40;
	char fullname[Len];
	int handicap;
public:
	Golf(const char* name, int hc);
	Golf();
	void sethandicap(int hc);
	void show() const;
};

Golf::Golf(const char* name, int hc) {
	strncpy(fullname, name, Len - 1);
	fullname[Len - 1] = '\0';
	handicap = hc;
}

Golf::Golf() {
	cout << "enter fullname: ";
	cin.getline(fullname, Len);
	cout << "enter handicap: ";
	cin >> handicap;
}

void Golf::sethandicap(int hc) {
	handicap = hc;
}

void Golf::show() const {
	cout << fullname << "\t" << handicap << endl;
}

int main() {
	Golf g1("lnj", 13);
	g1.show();
	g1.sethandicap(23);
	g1.show();

	Golf g2;
	g2.show();

	return 0;
}