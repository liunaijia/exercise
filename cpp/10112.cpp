#include <string>
#include <iostream>
#include <cstring>

using namespace std;

class Person {
private:
	static const int LIMIT = 25;
	string lname;
	char fname[LIMIT];
public:
	Person() {lname = ""; fname[0] = '\0';}
	Person(const string& lname, const char* fname = "Heyyou");
	void Show() const;
	void FormalShow() const;
};

Person::Person(const string& lname, const char* fname) {
	this->lname = lname;
	strncpy(this->fname, fname, LIMIT - 1);
	this->fname[LIMIT - 1] = '\0';
}

void Person::Show() const {
	cout << fname << " " << lname << endl;
}

void Person::FormalShow() const {
	cout << lname << " " << fname << endl;
}

int main() {
	Person one;
	one.Show();
	one.FormalShow();

	Person two("Smythecraft");
	two.Show();
	two.FormalShow();

	Person three("Dimwiddy", "Sam");
	three.Show();
	three.FormalShow();

	return 0;
}