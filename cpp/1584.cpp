#include <iostream>
#include <cstring>
#include <stdexcept>

using namespace std;

class Sales {
public:
	const static int MONTHS = 12;
	class bad_index : public logic_error {
	private:
		int bi;
	public:
		explicit bad_index(int ix, const char* s = "Index error in sales object\n");
		int bi_val() const {return bi;}
	};
	explicit Sales(int yy = 0);
	Sales(int yy, const double* gr, int n);
	virtual ~Sales() {}
	int Year() const {return year;}
	virtual double operator[](int i) const throw (bad_index);
	virtual double& operator[](int i) throw (bad_index);
private:
	double gross[MONTHS];
	int year;
};

class LabeledSales : public Sales {
public:
	static const int STRLEN = 50;
	class nbad_index : public Sales::bad_index {
	private:
		char lbl[STRLEN];
	public:
		nbad_index(const char* lb, int ix, const char* s = "Index error in LabeledSales objects\n");
		const char* label_val() {return lbl;}
	};
	explicit LabeledSales(const char* lb = "none", int yy = 0);
	LabeledSales(const char* lb, int yy, const double* gr, int n);
	virtual ~LabeledSales() {}
	const char* Label() const {return label;}
	virtual double operator[](int i) const throw(nbad_index);
	virtual double& operator[](int i) throw(nbad_index);
private:
	char label[STRLEN];
};

Sales::bad_index::bad_index(int ix, const char* s)
	: logic_error(s) {
		bi = ix;
	}

Sales::Sales(int yy) {
	year = yy;
	for(int i = 0; i < MONTHS; i++)
		gross[i] = 0;
}

Sales::Sales(int yy, const double* gr, int n){
	year = yy;
	int lim = (n < MONTHS) ? n : MONTHS;
	int i;
	for(i = 0; i < lim; i++)
		gross[i] = gr[i];
	for(; i < MONTHS; i++)
		gross[i] = 0;
}

double Sales::operator[](int i) const throw(bad_index) {
	if (i < 0 || i >= MONTHS)
		throw bad_index(i);
	return gross[i];
}

double& Sales::operator[](int i) throw(bad_index) {
	if (i < 0 || i >= MONTHS)
		throw bad_index(i);
	return gross[i];
}

LabeledSales::nbad_index::nbad_index(const char* lb, int ix, const char* s)
	: bad_index(ix, s) {
		strcpy(this->lbl, lb);
	}

LabeledSales::LabeledSales(const char* lb, int yy)
	: Sales(yy) {
		strcpy(label, lb);
	}

LabeledSales::LabeledSales(const char* lb, int yy, const double* gr, int n)
: Sales(yy, gr, n) {
	strcpy(label, lb);
}

double LabeledSales::operator[](int i) const throw(nbad_index) {
	if (i < 0 || i >= MONTHS)
		throw nbad_index(Label(), i);
	return Sales::operator[](i);
}

double& LabeledSales::operator[](int i) throw(nbad_index) {
	if (i < 0 || i >= MONTHS)
		throw nbad_index(Label(), i);
	return Sales::operator[](i);
}

int main() {
	double vals1[12] = {1220, 1100, 1122, 2212, 1232, 2334, 2884, 2393, 3302, 2922, 3002, 3544};
	double vals2[12] = {12, 11, 22, 21, 32, 34, 28, 29, 33, 29, 32, 35};

	Sales sales1(2004, vals1, 12);
	LabeledSales sales2("Blogstar", 2005, vals2, 12);

	cout << "First try block:" << endl;
	try{
		int i;
		cout << "Year = " << sales1.Year() << endl;
		for(i = 0; i < 12; i++){
			cout << sales1[i] << " ";
		}
		cout << endl;

		cout << "Year = " << sales2.Year() << endl;
		cout << "Label = " << sales2.Label() << endl;
		for(i = 0; i <= 12; i++){
			cout << sales2[i] << " ";
		}
		cout << endl;
	}
	catch(Sales::bad_index& e) {
		cout << e.what();
		LabeledSales::nbad_index* pe = dynamic_cast<LabeledSales::nbad_index*>(&e);
		if (pe)
			cout << "Company:" << pe->label_val() << endl;
		cout << "bad index: " << e.bi_val() << endl;
	}

	cout << "\nNext try block:" << endl;
	try{
		sales2[2] = 37.5;
		sales1[20] = 23345;
		cout << "End of try block 2.\n";
	}
	catch(Sales::bad_index& e) {
		cout << e.what();
		LabeledSales::nbad_index* pe = dynamic_cast<LabeledSales::nbad_index*>(&e);
		if (pe)
			cout << "Company:" << pe->label_val() << endl;
		cout << "bad index: " << e.bi_val() << endl;
	}
	cout << "done.";
	return 0;
}