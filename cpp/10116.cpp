#include <iostream>
using namespace std;

class Move {
private:
	double x;
	double y;
public:
	Move(double x = 0, double y = 0);
	void Show() const;
	Move Add(const Move& m) const;
	void Reset(double x = 0, double y = 0);
};

Move::Move(double x, double y) {
	this->x = x;
	this->y = y;
}

void Move::Show() const {
	cout << "(" << x << ", " << y << ")" << endl;
}

Move Move::Add(const Move& m) const {
	Move result(x + m.x, y + m.y);
	return result;
}

void Move::Reset(double x, double y) {
	this->x = x;
	this->y = y;
}

int main() {
	Move m;
	m.Show();

	Move m1(2, 3);
	Move m2(10, 1);
	Move m3 = m1.Add(m2);
	m1.Show();
	m2.Show();
	m3.Show();

	m3.Reset(1, 1);
	m3.Show();
}