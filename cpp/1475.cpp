#include <iostream>
#include <string>

using namespace std;

class AbstrEmp {
private:
	string fname;
	string lname;
	string job;
public:
	AbstrEmp();
	AbstrEmp(const string& fname, const string& lname, const string& job);
	virtual void showAll() const;
	virtual void setAll();
	friend ostream& operator<<(ostream& out, const AbstrEmp& o);
	virtual ~AbstrEmp() = 0;
};

AbstrEmp::AbstrEmp() {}

AbstrEmp::AbstrEmp(const string& fname, const string& lname, const string& job) {
	this->fname = fname;
	this->lname = lname;
	this->job = job;
}

void AbstrEmp::showAll() const {
	cout << "fname:" << fname << " lname:" << lname << " job:" << job;
}

void AbstrEmp::setAll() {
	cout << "input fname: ";
	getline(cin, fname);
	cout << "input lname: ";
	getline(cin, lname);
	cout << "input job: ";
	getline(cin, job);
}

AbstrEmp::~AbstrEmp() {

}

ostream& operator<<(ostream& out, const AbstrEmp& o) {
	return out << o.fname << ", " << o.lname;
}

class Employee : public AbstrEmp {
public:
	Employee(const string& fname, const string& lname, const string& job);
	virtual void showAll() const;
	virtual void setAll();
};

Employee::Employee(const string& fname, const string& lname, const string& job)
	: AbstrEmp(fname, lname, job) {

	}

void Employee::showAll() const {
	AbstrEmp::showAll();
}

void Employee::setAll() {
	AbstrEmp::setAll();
}


class Manager : virtual public AbstrEmp {
private:
	int inChargeOf_;
protected:
	int inChargeOf() const {return inChargeOf_;}
	int& inChargeOf() {return inChargeOf_;}
public:
	Manager();
	Manager(const string& fname, const string& lname, const string& job, int inChargeOf);
	Manager(const AbstrEmp& o, int inChargeOf);
	Manager(const Manager& m);
	virtual void showAll() const;
	virtual void setAll();
};

Manager::Manager() : AbstrEmp("", "", "") {
	inChargeOf_ = 0;
}

Manager::Manager(const string& fname, const string& lname, const string& job, int inChargeOf)
	: AbstrEmp(fname, lname, job) {
		this->inChargeOf_ = inChargeOf;
	}

Manager::Manager(const AbstrEmp& o, int inChargeOf) : AbstrEmp(o) {
	this->inChargeOf_ = inChargeOf;
}

Manager::Manager(const Manager& m) : AbstrEmp(m) {
	this->inChargeOf_ = m.inChargeOf();
}

void Manager::showAll() const {
	AbstrEmp::showAll();
	cout << " inChargeOf:" << inChargeOf_;
}

void Manager::setAll() {
	AbstrEmp::setAll();
	cout << "input in charge of: ";
	cin >> inChargeOf_;
}

class Fink : virtual public AbstrEmp {
private:
	string reportsTo_;
protected:
	const string reportsTo() const {return reportsTo_;}
	string& reportsTo() {return reportsTo_;}
public:
	Fink();
	Fink(const string& fname, const string& lname, const string& job, const string& reportsTo);
	Fink(const AbstrEmp& e, const string& reportsTo);
	Fink(const Fink& e);
	virtual void showAll() const;
	virtual void setAll();
};

Fink::Fink() : AbstrEmp("", "", "") {
}

Fink::Fink(const string& fname, const string& lname, const string& job, const string& reportsTo)
	: AbstrEmp(fname, lname, job) {
		this->reportsTo_ = reportsTo;
	}

Fink::Fink(const AbstrEmp& o, const string& reportsTo) : AbstrEmp(o) {
	this->reportsTo_ = reportsTo;
}

Fink::Fink(const Fink& e) : AbstrEmp(e) {
	this->reportsTo_ = e.reportsTo();
}

void Fink::showAll() const {
	AbstrEmp::showAll();
	cout << " reportsTo:" << reportsTo_;
}

void Fink::setAll() {
	AbstrEmp::setAll();
	cout << "reports to: ";
	getline(cin, reportsTo_);
}

class HighFink : public Manager, public Fink {
public:
	HighFink();
	HighFink(const string& fname, const string& lname, const string& job, const string& reportsTo, int inChargeOf);
	HighFink(const AbstrEmp& e, const string& reportsTo, int inChargeOf);
	HighFink(const Fink& f, int inChargeOf);
	HighFink(const Manager& m, const string& reportsTo);
	HighFink(const HighFink& h);
	virtual void showAll() const;
	virtual void setAll();
};

HighFink::HighFink() : Manager(), Fink(), AbstrEmp() {

}

HighFink::HighFink(const string& fname, const string& lname, const string& job, const string& reportsTo, int inChargeOf)
	: AbstrEmp(fname, lname, job),
	Manager(fname, lname, job, inChargeOf),
	Fink(fname, lname, job, reportsTo) {

	}

HighFink::HighFink(const AbstrEmp& e, const string& reportsTo, int inChargeOf)
	: AbstrEmp(e), Manager(e, inChargeOf), Fink(e, reportsTo) {

}

HighFink::HighFink(const Fink& f, int inChargeOf)
	: AbstrEmp(f), Manager(f, inChargeOf), Fink(f) {
}

HighFink::HighFink(const Manager& m, const string& reportsTo)
	: AbstrEmp(m), Manager(m), Fink(m, reportsTo) {

}
HighFink::HighFink(const HighFink& h)
	: AbstrEmp(h), Manager(h), Fink(h) {

}

void HighFink::showAll() const {
	AbstrEmp::showAll();
	cout << " inChargeOf:" << inChargeOf();
	cout << " reportsTo:" << reportsTo();
}

void HighFink::setAll() {
	AbstrEmp::setAll();
	cout << "input in charge of: ";
	cin >> inChargeOf();
	cin.get();
	cout << "reports to: ";
	getline(cin, reportsTo());
}

int main() {
	Employee em("Trip", "Harris", "Thumper");
	cout << em << endl;
	em.showAll();
	cout << endl;

	Manager ma("Amorphia", "Spindragon", "Nuancer", 5);
	cout << ma << endl;
	ma.showAll();
	cout << endl;

	Fink fi("Matt", "Oggs", "Oiler", "Juno Barr");
	cout << fi << endl;
	fi.showAll();
	cout << endl;

	HighFink hf(ma, "Curly Kew");
	hf.showAll();
	cout << endl;
	cout << "Press a key for next phase:" << endl;
	cin.get();

	HighFink hf2;
	hf2.setAll();

	cout << "Using an AbstrEmp* pointer:" << endl;
	AbstrEmp* tri[4] = {&em, &fi, &hf, &hf2};
	for(int i = 0; i < 4; i++) {
		tri[i]->showAll();
		cout << endl;
	}

	return 0;
}

// 因为不需要返回对象和将对象作为参数传递，所以没有定义赋值操作符；
// 这样可以在派生类中重写，多态嘛；
// 因为HighFink只希望拥有一份AbstrEmp的对象拷贝；
// 继承了Manager和Fink，所以不需要了；
// 只显示姓名，一个operator<<()版本就够了
// 只显示姓名和job信息