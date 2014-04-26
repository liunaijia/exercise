#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;

class Person {
private:
	string familyName;
	string lastName;
protected:
	virtual void data() const;
public:
	Person(const string& familyName, const string& lastName);
	virtual void show() const = 0;
};

Person::Person(const string& familyName, const string& lastName) {
	this->familyName = familyName;
	this->lastName = lastName;
}

void Person::data() const {
	cout << familyName << " " << lastName;
}

class Gunslinger : virtual public Person {
private:
	int count;
	double time;
protected:
	virtual void data() const;
public:
	Gunslinger(const string& familyName, const string& lastName, int count, double time);
	virtual void show() const;
	double draw() const;
};

Gunslinger::Gunslinger(const string& familyName, const string& lastName, int count, double time)
		: Person(familyName, lastName) {
			this->count = count;
			this->time = time;
		}

void Gunslinger::data() const {
	cout << " count:" << count << " time:" << time;
}

void Gunslinger::show() const {
	Person::data();
	data();
}

double Gunslinger::draw() const {
	return time;
}

class PokerPlayer : virtual public Person {
protected:
	virtual void data() const;
public:
	PokerPlayer(const string& familyName, const string& lastName);
	int draw() const;
	virtual void show() const;
};

PokerPlayer::PokerPlayer(const string& familyName, const string& lastName)
	: Person(familyName, lastName) {

	}

int PokerPlayer::draw() const {
	return rand() % 52;
}

void PokerPlayer::data() const {
	cout << " draw: " << draw();
}

void PokerPlayer::show() const {
	Person::data();
	data();
}

class BadDude : public Gunslinger, public PokerPlayer {
protected:
	virtual void data() const;
public:
	BadDude(const string& familyName, const string& lastName, int count, double time);
	double gDraw() const;
	int cDraw() const;
	virtual void show() const;
};

BadDude::BadDude(const string& familyName, const string& lastName, int count, double time)
	: Person(familyName, lastName), Gunslinger(familyName, lastName, count, time), PokerPlayer(familyName, lastName) {

}

double BadDude::gDraw() const {
	return Gunslinger::draw();
}

int BadDude::cDraw() const {
	return PokerPlayer::draw();
}

void BadDude::data() const {

}

void BadDude::show() const {
	Person::data();
	Gunslinger::data();
	PokerPlayer::data();
}

int main() {
	Gunslinger p1("Michael", "Jackson", 3, 0.23);
	p1.show();
	cout << endl;

	PokerPlayer p2("L", "A");
	p2.show();
	cout << endl;
	
	BadDude p3("Sister", "xxx", 4, 0.33);
	p3.show();

	return 0;
}