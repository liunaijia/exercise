#include <iostream>
using namespace std;

class Stonewt {
private:
	static const int LBS_PER_STN = 14;
	int stone;
	double pds_left;
	double pounds;
	char f;
public:
	Stonewt(double lbs);
	Stonewt(int stone, double lbs);
	Stonewt& format(char f);
	Stonewt operator+(const Stonewt& s) const;
	Stonewt operator-(const Stonewt& s) const;
	Stonewt operator*(double m) const;
	friend Stonewt operator*(double m, const Stonewt& s);
	friend ostream& operator<<(ostream& out, Stonewt s);
};

Stonewt::Stonewt(double lbs) {
	stone = int(lbs) / LBS_PER_STN;
	pds_left = int(lbs) % LBS_PER_STN + lbs - int(lbs);
	pounds = lbs;
	f = 'p';
}

Stonewt::Stonewt(int stone, double lbs) {
	this->stone = stone;
	pds_left = lbs;
	pounds = stone * LBS_PER_STN + lbs;
	f = 's';
}

Stonewt& Stonewt::format(char f) {
	this->f = f;
	return *this;
}

Stonewt Stonewt::operator*(double m) const {
	return Stonewt(this->pounds * m);
}

Stonewt Stonewt::operator+(const Stonewt& s) const {
	return Stonewt(this->pounds + s.pounds);
}

Stonewt Stonewt::operator-(const Stonewt& s) const {
	return Stonewt(this->pounds - s.pounds);
}

Stonewt operator*(double m, const Stonewt& s) {
	return s * m;
}

ostream& operator<<(ostream& out, Stonewt s) {
	if (s.f == 'p')
		out << s.pounds << " pounds";
	else if (s.f == 's')
		out << s.stone << " stone " << s.pds_left << " pounds";
	else if (s.f == 'q')
		out << (int)s.pounds << " int pounds";
}

int main() {
	void output(Stonewt& s);

	Stonewt s(10, 8);
	output(s);

	Stonewt s2(3.5);
	output(s2);
	
	Stonewt sum = s + s2;
	output(sum);

	Stonewt diff = s - s2;
	output(diff);

	Stonewt mul = s * 3;
	output(mul);

	Stonewt mul1 = 2 * s;
	output(mul1);
}

void output(Stonewt& s) {
	cout << s.format('p') << endl;
	cout << s.format('q') << endl;
	cout << s.format('s') << endl;	
}