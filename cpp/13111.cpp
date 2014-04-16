#include <iostream>
#include <cstring>

using namespace std;

class Cd {
private:
	char performers[50];
	char label[20];
	int selections;
	double playtime;
	void init(const char* performers, const char* label, int selections, double playtime);
public:
	Cd(const char* performers, const char* label, int selections, double playtime);
	Cd(const Cd& cd);
	//Cd();
	virtual ~Cd();
	virtual void Report() const;
	Cd& operator=(const Cd& cd);
};

void Cd::init(const char* performers, const char* label, int selections, double playtime) {
	strncpy(this->performers, performers, sizeof(this->performers) - 1);
	this->performers[sizeof(this->performers) - 1] = '\0';
	strncpy(this->label, label, sizeof(this->label) - 1);
	this->label[sizeof(this->label) - 1] = '\0';
	this->selections = selections;
	this->playtime = playtime;
}

Cd::Cd(const char* performers, const char* label, int selections, double playtime) {
	init(performers, label, selections, playtime);
}

Cd::Cd(const Cd& cd) {
	init(cd.performers, cd.label, cd.selections, cd.playtime);	
}

// Cd::Cd() {
// 	init("", "", 0, 0);
// }

Cd::~Cd() {

}

void Cd::Report() const {
	cout << "performers: " << performers << endl
		<< "label: " << label << endl
		<< "selections: " << selections << endl
		<< "playtime: " << playtime << endl;
}

Cd& Cd::operator=(const Cd& cd) {
	if (this == &cd)
		return *this;
	init(cd.performers, cd.label, cd.selections, cd.playtime);
	return *this;
}

class Classic : public Cd {
private:
	char* summary;
public:
	Classic(const char* summary, const char* performers, const char* label, int selections, double playtime);
	Classic();
	Classic(const Classic& c);
	virtual ~Classic();
	virtual void Report() const;
	Classic& operator=(const Classic& c);
};

Classic::Classic(const char* summary, const char* performers, const char* label, int selections, double playtime) : Cd(performers, label, selections, playtime) {
	this->summary = new char[strlen(summary) + 1];
	strcpy(this->summary, summary);
	this->summary[strlen(summary)] = '\0';
}

Classic::Classic() : Cd("", "", 0, 0) {
	summary = NULL;
}

Classic::Classic(const Classic& c) : Cd(c) {
	this->summary = new char[strlen(c.summary) + 1];
	strcpy(this->summary, c.summary);
	this->summary[strlen(c.summary)] = '\0';	
}

Classic::~Classic() {
	delete [] summary;
}

void Classic::Report() const {
	Cd::Report();
	cout << "summary: " << summary << endl;
}

Classic& Classic::operator=(const Classic& c) {
	if (this == &c)
		return *this;
	delete [] summary;
	Cd::operator=(c);
	this->summary = new char[strlen(c.summary) + 1];
	strcpy(this->summary, c.summary);
	this->summary[strlen(c.summary)] = '\0';
	return *this;
}

int main() {
	Cd c1("Beatles", "Capitol", 14, 35.5);
	Classic c2 = Classic("Piano Sonata in B flat, Fantasia in C", "Alfred Brendel", "Philips", 2, 57.17);
	Cd* pcd = &c1;
	cout << "Using object directly:" << endl;
	c1.Report();
	c2.Report();

	cout << "Using type cd* pointer to objects:" << endl;
	pcd->Report();
	pcd = &c2;
	pcd->Report();

	cout << "Calling a function with a Cd reference argument:" << endl;
	void Bravo(const Cd& disk);
	Bravo(c1);
	Bravo(c2);

	cout << "Testing assignment:";
	Classic copy;
	copy = c2;
	copy.Report();

	return 0;
}

void Bravo(const Cd& disk) {
	disk.Report();
}