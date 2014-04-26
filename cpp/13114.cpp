#include <iostream>
#include <cstring>

using namespace std;

class Port {
private:
	char* brand;
	char style[20];
	int bottles;
	void init(const char* brand, const char* style, int bottles);
public:
	Port(const char* brand = "none", const char* style = "none", int bottles = 0);
	Port(const Port& p);
	virtual ~Port() {
		delete [] brand;
	}
	Port& operator=(const Port& p);
	Port& operator+=(int b);
	Port& operator-=(int b);
	int BottleCount() const {
		return bottles;
	}
	virtual void Show() const;
	friend ostream& operator<<(ostream& out, const Port& p);
};

void Port::init(const char* brand, const char* style, int bottles) {
	this->brand = new char[strlen(brand) + 1];
	strcpy(this->brand, brand);

	strncpy(this->style, style, 19);
	this->style[19] = '\0';

	this->bottles = bottles;
}

Port::Port(const char* brand, const char* style, int bottles) {
	init(brand, style, bottles);
}

Port::Port(const Port& p) {
	init(p.brand, p.style, p.bottles);
}

Port& Port::operator=(const Port& p) {
	if (this == &p)
		return *this;
	delete [] brand;
	init(p.brand, p.style, p.bottles);
	return *this;
}

Port& Port::operator+=(int b) {
	if (b > 0)
		bottles += b;
	return *this;
}

Port& Port::operator-=(int b) {
	if (bottles >= b)
		bottles -= b;
	return *this;
}

void Port::Show() const {
	cout << "Brand: " << brand << endl
		<< "Kind: " << style << endl
		<< "Bottles: " << bottles << endl;
}

ostream& operator<<(ostream& out, const Port& p) {
	return out << p.brand << ", " << p.style << ", " << p.bottles;
}

class VintagePort : public Port {
private:
	char* nickname;
	int year;
	void init(const char* nickname, int year);
public:
	VintagePort();
	VintagePort(const char* brand, int bottles, const char* nickname, int year);
	VintagePort(const VintagePort& vp);
	virtual ~VintagePort() {
		delete [] nickname;
	}
	VintagePort& operator=(const VintagePort& vp);
	virtual void Show() const;
	friend ostream& operator<<(ostream& out, const VintagePort& vp);
};

void VintagePort::init(const char* nickname, int year) {
	if (nickname == NULL)
		this->nickname = NULL;
	else {
		this->nickname = new char[strlen(nickname) + 1];
		strcpy(this->nickname, nickname);
	}

	this->year = year;
}

VintagePort::VintagePort() : Port() {
	init(NULL, 0);
}

VintagePort::VintagePort(const char* brand, int bottles, const char* nickname, int year)
	: Port(brand, "vintage", bottles){
	init(nickname, year);
}

VintagePort::VintagePort(const VintagePort& vp)
	: Port(vp) {
	init(vp.nickname, vp.year);
}

VintagePort& VintagePort::operator=(const VintagePort& vp) {
	if (this == &vp)
		return *this;
	delete [] nickname;
	(Port&)*this = vp;
	init(vp.nickname, vp.year);
	return *this;
}

void VintagePort::Show() const {
	Port::Show();
	cout << "nickname: " << nickname << endl
		<< "year: " << year << endl;
}

ostream& operator<<(ostream& out, const VintagePort& vp) {
	out << (Port&)vp;
	return out << ", \"" << vp.nickname << "\" year " << vp.year;
}

int main() {
	void run(Port* p);

	Port p0("GreatWall", "dry red", 10);
	cout << p0 << endl;
	run(&p0);

	VintagePort p1("Lafite", 5, "Rothschild", 1999);
	cout << p1 << endl;
	p0 = p1;
	run(&p0);

	return 0;
}

void run(Port* p) {
	cout << *p << endl;
	p->Show();
	*p += 3;
	cout << p->BottleCount() << " bottles" << endl;
	*p -= 2;
	cout << p->BottleCount() << " bottles" << endl;
}