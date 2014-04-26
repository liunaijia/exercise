#include <iostream>

using namespace std;

class Cow {
	char name[20];
	char* hobby;
	double weight;
	void init(const char* nm, const char* ho, double wt);
public:
	Cow();
	Cow(const char* nm, const char* ho, double wt);
	Cow(const Cow& c);
	~Cow();
	Cow& operator=(const Cow& c);
	void ShowCow() const;
};

Cow::Cow() {
	name[0] = '\0';
	hobby = NULL;
	weight = 0;
}

Cow::Cow(const char* nm, const char* ho, double wt) {
	init(nm, ho, wt);
}

Cow::Cow(const Cow& c) {
	init(c.name, c.hobby, c.weight);
	// for(int i = 0; i < sizeof(c.name) / sizeof(char); i++)
	// 	name[i] = c.name[i];
	
	// if (c.hobby != NULL) {
	// 	hobby = new char[strlen(c.hobby) + 1];
	// 	strcpy(hobby, c.hobby);
	// }
	// else {
	// 	hobby = NULL;
	// }

	// weight = c.weight;
}

Cow& Cow::operator=(const Cow& c) {
	if (this == &c)
		return *this;

	if (hobby != NULL)
		delete [] hobby;

	init(c.name, c.hobby, c.weight);
	return *this;
}

void Cow::init(const char* nm, const char* ho, double wt) {
	if (nm != NULL) {
		// strncpy并不保证最后写\0
		strncpy(name, nm, 19);
		name[19] = '\0';
	}
	else {
		name[0] = '\0';
	}

	if (ho != NULL) {
		hobby = new char[strlen(ho) + 1];
		strcpy(hobby, ho);
	}
	else
		hobby = NULL;

	weight = wt;
}

Cow::~Cow() {
	delete [] hobby;
}

void Cow::ShowCow() const {
	cout << name << "\t";
	if (hobby != NULL)
		cout << hobby << "\t";
    cout << weight << endl;
}

int main() {
	Cow c1;
	c1.ShowCow();

	Cow c2("niuniu", "happy and stupid", 123);
	c2.ShowCow();

	Cow c3 = c2;
	c3.ShowCow();
	c3.~Cow();

	Cow c4;
	c4 = c2;
	c4.ShowCow();
	c4.~Cow();

	c2.ShowCow();

	return 0;
}