#include <iostream>
using namespace std;
class Stock {
private:
	char* company;
	int shares;
	double share_val;
	double total_val;
	void set_tot() {
		total_val = share_val * shares;
	}
	void init(const char* company, int shares, double share_val);
	
public:
	Stock();
	Stock(const char* company, int shares = 0, double share_val = 0);
	Stock(const Stock&);
	~Stock();
	void buy(int num, double price);
	void sell(int num, double price);
	void update(double price);
	Stock& operator=(const Stock& s);
	friend ostream& operator<<(ostream& out, const Stock& s);
	friend bool operator>(const Stock& s1, const Stock& s2);
};

Stock::Stock() {
	init(NULL, 0, 0);
}

Stock::Stock(const char* company, int shares, double share_val) {
	init(company, shares, share_val);
}

Stock::Stock(const Stock& s) {
	init(s.company, s.shares, s.share_val);
}

void Stock::init(const char* company, int shares, double share_val) {
	if (company == NULL)
		this->company = NULL;
	else {
		this->company = new char[strlen(company) + 1];
		strcpy(this->company, company);
	}
	this->shares = shares;
	this->share_val = share_val;
	set_tot();
}

Stock& Stock::operator=(const Stock& s) {
	if (this == &s)
		return *this;

	delete [] company;
	init(s.company, s.shares, s.share_val);

	return *this;
}

Stock::~Stock() {
	delete [] company;
}

void Stock::buy(int num, double price) {
	shares += num;
	share_val = price;
	set_tot();
}

void Stock::sell(int num, double price) {
	if (num > shares) {
		cerr << "not enough";
		return;
	}
	shares -= num;
	share_val = price;
	set_tot();
}

void Stock::update(double price) {
	share_val = price;
	set_tot();
}

ostream& operator<<(ostream& out, const Stock& s) {
	return out << s.company << "\t" << s.shares << "\t" << s.share_val << "\t" << s.total_val;
}

bool operator>(const Stock& s1, const Stock& s2) {
	return s1.total_val > s2.total_val;
}

int main() {
	Stock stocks[4] = {
		Stock("NanoSmart", 12, 20),
		Stock("Boffo Objects", 200, 2),
		Stock("Monolighic Obelisks", 130, 3.25),
		Stock("Fleep Enterprises", 60, 6.5)
	};
	cout.precision(2);
	cout.setf(ios_base::fixed, ios_base::floatfield);
	cout.setf(ios_base::showpoint);

	cout << "Stock holdings:" << endl;
	for(int i = 0; i < 4; i++)
		cout << stocks[i] << endl;

	Stock top = stocks[0];
	for(int i = 1; i < 4; i++)
		if (stocks[i] > top)
			top = stocks[i];
	cout << "Most valuable holding:" << endl;
	cout << top;

	return 0;
}