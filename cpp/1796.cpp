// 将题目简化为写入对象和读取对象

#include <iostream>
#include <fstream>
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
	virtual ~AbstrEmp() = 0;
	virtual ostream& write(ostream& out);
	virtual istream& read(istream& in);
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

AbstrEmp::~AbstrEmp() {

}

ostream& AbstrEmp::write(ostream& out) {
	return out << fname << endl << lname << endl << job << endl;
}

istream& AbstrEmp::read(istream& in) {
	getline(in, fname);
	getline(in, lname);
	getline(in, job);
}

class Employee : public AbstrEmp {
public:
	Employee(const string& fname, const string& lname, const string& job);
	virtual ostream& write(ostream& out);
};

Employee::Employee(const string& fname, const string& lname, const string& job)
	: AbstrEmp(fname, lname, job) {

	}

ostream& Employee::write(ostream& out) {
	out << "Employee:" << endl;
	return AbstrEmp::write(out);
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
	virtual ostream& write(ostream& out);
	virtual istream& read(istream& in);
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

ostream& Manager::write(ostream& out) {
	out << "Manager:" << endl;
	AbstrEmp::write(out);
	return out << inChargeOf_ << endl;
}

istream& Manager::read(istream& in) {
	AbstrEmp::read(in);
	in >> inChargeOf_;
	in.ignore(100, '\n');
	return in;
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
	virtual ostream& write(ostream& out);
	virtual istream& read(istream& in);
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

ostream& Fink::write(ostream& out) {
	out << "Fink:" << endl;
	AbstrEmp::write(out);
	return out << reportsTo_ << endl;
}

istream& Fink::read(istream& in) {
	AbstrEmp::read(in);
	return getline(in, reportsTo_);
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
	virtual ostream& write(ostream& out);
	virtual istream& read(istream& in);
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

ostream& HighFink::write(ostream& out) {
	out << "HighFink:" << endl;
	AbstrEmp::write(out);
	return out << inChargeOf() << endl << reportsTo() << endl;
}

istream& HighFink::read(istream& in) {
	AbstrEmp::read(in);
	in >> inChargeOf();
	in.ignore(100, '\n');
	return getline(in, reportsTo());
}

int main() {
	Employee em("Trip", "Harris", "Thumper");
	Manager ma("Amorphia", "Spindragon", "Nuancer", 5);
	Fink fi("Matt", "Oggs", "Oiler", "Juno Barr");
	HighFink hf(ma, "Curly Kew");

	AbstrEmp* tri[4] = {&em, &ma, &fi, &hf};

	ofstream fout("1796.dat");
	for(int i = 0; i < 4; i++)
		tri[i]->write(fout);
	fout.close();

	ifstream fin("1796.dat");
	AbstrEmp* results[4];
	int i = 0;
	while(fin) {
		string line;
		getline(fin, line);
		if (line == "Employee:")
			results[i] = new Employee("", "", "");
		else if (line == "Manager:")
			results[i] = new Manager();
		else if (line == "Fink:")
			results[i] = new Fink();
		else
			results[i] = new HighFink();

		results[i++]->read(fin);
	}
	fin.close();
	
	for(int i = 0; i < 4; i++) {
		results[i]->showAll();
		cout << endl;
	}


	return 0;
}