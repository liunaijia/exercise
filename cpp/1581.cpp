#include <iostream>

using namespace std;

class Remote;
class Tv{
friend class Remote;
private:
	bool is_on;
public:
	Tv(bool is_on);
	void switch_state(Remote& r);
};

class Remote {
friend class Tv;
private:
	enum states {normal, interactive};
	states state;
public:
	Remote() {
		state = normal;
	}
	void show_state() const;
};

void Remote::show_state() const {
	cout << this->state << endl;
}

Tv::Tv(bool is_on) {
	this->is_on = is_on;
}

void Tv::switch_state(Remote& r) {
	if (this->is_on)
		r.state = r.state == Remote::normal ? Remote::interactive : Remote::normal;
}

int main() {
	Remote r1;
	Tv offed_tv(false);
	r1.show_state();
	offed_tv.switch_state(r1);
	r1.show_state();

	Tv on_tv(true);
	on_tv.switch_state(r1);
	r1.show_state();

	return 0;
}