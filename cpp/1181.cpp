#include <iostream>
using namespace std;

class Stonewt {
private:
	static const int LBS_PER_STN = 14;
	int stone;
	double pds_left;
	double pounds;
public:
	Stonewt(double lbs);
	Stonewt(int stone, double lbs);
	Stonewt();
	Stonewt operator*(double m);
	friend ostream& operator<<(ostream& out, Stonewt s);
};

Stonewt::Stonewt(double lbs) {
	stone = int(lbs) / LBS_PER_STN;
	pds_left = int(lbs) % LBS_PER_STN + lbs - int(lbs);
	pounds = lbs;
}

Stonewt::Stonewt(int stone, double lbs) {
	this->stone = stone;
	pds_left = lbs;
	pounds = stone * LBS_PER_STN + lbs;
}

Stonewt::Stonewt() {
	stone = pounds = pds_left = 0;
}

Stonewt Stonewt::operator*(double m) {
	return Stonewt(this->pounds * m);
}

ostream& operator<<(ostream& out, Stonewt s) {
	out << s.stone << "," << s.pds_left << " " << s.pounds;
}

int main() {
	Stonewt s(10, 8);
	cout << s * 2;
}