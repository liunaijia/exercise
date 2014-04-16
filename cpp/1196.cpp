#include <iostream>
using namespace std;

class Stonewt {
private:
	static const int LBS_PER_STN = 14;
	int stone;
	double pds_left;
	double pounds;
public:
	Stonewt();
	Stonewt(double lbs);
	Stonewt(int stone, double lbs);
	bool operator>(const Stonewt& s) const;
	bool operator>=(const Stonewt& s) const;
	bool operator==(const Stonewt& s) const;
	bool operator<=(const Stonewt& s) const;
	bool operator<(const Stonewt& s) const;
	bool operator!=(const Stonewt& s) const;
	friend ostream& operator<<(ostream& out, Stonewt s);
};

Stonewt::Stonewt() {
	stone = pds_left = pounds = 0;
}
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

bool Stonewt::operator>(const Stonewt& s) const {
	return this->pounds > s.pounds;
}

bool Stonewt::operator>=(const Stonewt& s) const {
	return this->pounds >= s.pounds;
}

bool Stonewt::operator==(const Stonewt& s) const {
	return this->pounds == s.pounds;
}

bool Stonewt::operator<=(const Stonewt& s) const {
	return this->pounds <= s.pounds;
}

bool Stonewt::operator<(const Stonewt& s) const {
	return this->pounds < s.pounds;
}

bool Stonewt::operator!=(const Stonewt& s) const {
	return this->pounds != s.pounds;
}

ostream& operator<<(ostream& out, Stonewt s) {
	out << s.stone << " stone " << s.pds_left << " pounds or " << s.pounds << " pounds";
}

int main() {
	Stonewt s1(11, 0);
	Stonewt s2(15, 8);
	Stonewt s3(7, 1);
	Stonewt s[6] = {s1, s2, s3};
	for(int i = 3; i < 6; i++) {
		s[i] = s[i - 3];
	}

	Stonewt min, max;
	Stonewt lookup(11, 0);
	int count = 0;
	for(int i = 0; i < 6; i++) {
		if (i == 0 || s[i] < min)
			min = s[i];
		if (i == 0 || s[i] > max)
			max = s[i];
		if (s[i] >= lookup)
			count++;
		cout << s[i] << endl;
	}

	cout << "min: " << min << endl;
	cout << "max: " << max << endl;
	cout << count << endl;
}

