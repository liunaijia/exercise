#include <iostream>

using namespace std;

class nifty {
private:
	char* personality;
	int talents;
public:
	nifty();
	nifty(const char* s);
	~nifty();
	friend ostream& operator<<(ostream& os, const nifty& n);
};

nifty::nifty() {
	personality = NULL;
	talents = 0;
}

nifty::nifty(const char* s) {
	personality = new char[strlen(s) + 1];
	strcpy(personality, s);
	talents = 0;
}

nifty::~nifty() {
	delete [] personality;
}

ostream& operator<<(ostream& os, const nifty& n) {
	if (n.personality != NULL)
		return os << n.personality << " " << n.talents;
	else
		return os;
}

int main() {
	nifty n;
	cout << n << endl;

	nifty n1("hi");
	cout << n1 << endl;

	return 0;
}