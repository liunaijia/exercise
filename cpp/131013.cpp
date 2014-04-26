#include <iostream>
using namespace std;

class Corporation {
public:
	virtual void head() {cout << "@Corporation" << this;}
};

class PublicCorporation : public Corporation {
public:
	virtual void head() {cout << "@PublicCorporation" << this;}
};

int main() {
	PublicCorporation pc;
	Corporation* ph = &pc;
	ph->head();	// call Corporation::head() if head() is normal
	ph->head();	// call PublicCorporation::head() if head() is virtual

	return 0;
}