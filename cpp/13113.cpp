#include <iostream>
#include <cstring>

using namespace std;

class Abc {
private:
	char* label;
	int rating;
	Abc(const Abc&);
	Abc& operator=(const Abc&);
public:
	Abc(const char* label, int rating);
	virtual ~Abc();
	virtual void View() = 0;
};

Abc::Abc(const char* label, int rating) {
	this->label = new char[strlen(label) + 1];
	strcpy(this->label, label);
	this->rating = rating;
}

Abc::~Abc() {
	delete [] label;
}

void Abc::View() {
	cout << "label: " << label << endl
		<< "rating: " << rating << endl;
}

class BaseDma : public Abc {
private:
	BaseDma(const BaseDma&);
	BaseDma& operator=(const BaseDma&);
public:
	BaseDma(const char* label, int rating);
	virtual ~BaseDma();
	virtual void View();
};

BaseDma::BaseDma(const char* label, int rating) : Abc(label, rating) {
}

BaseDma::~BaseDma() {
}

void BaseDma::View() {
	Abc::View();
}

class LackDma : public Abc {
private:
	char* color;
	LackDma(const LackDma&);
	LackDma operator=(const LackDma&);
public:
	LackDma(const char* label, int rating, const char* color);
	virtual ~LackDma();
	virtual void View();
};

LackDma::LackDma(const char* label, int rating, const char* color) : Abc(label, rating) {
	this->color = new char[strlen(color) + 1];
	strcpy(this->color, color);
}

LackDma::~LackDma() {
	delete [] color;
}

void LackDma::View() {
	Abc::View();
	cout << "color: " << color << endl;
}

class HasDma : public Abc {
private:
	char* style;
	HasDma(const HasDma&);
	HasDma& operator=(const HasDma&);
public:
	HasDma(const char* label, int rating, const char* style);
	virtual ~HasDma();
	virtual void View();
};

HasDma::HasDma(const char* label, int rating, const char* style) : Abc(label, rating) {
	this->style = new char[strlen(style) + 1];
	strcpy(this->style, style);
}

HasDma::~HasDma() {
	delete [] style;
}

void HasDma::View() {
	Abc::View();
	cout << "style: " << style << endl;
}



int main() {
	const int SIZE = 3;
	const int LEN = 80;

	Abc* dmas[SIZE];

	for(int i = 0; i < SIZE; i++) {
		cout << "Enter label:";
		char label[LEN];
		cin.getline(label, LEN);

		cout << "Enter rating:";
		int rating;
		cin >> rating;

		cout << "Enter 1 for BaseDma; 2 for LackDma; 3 for HasDma:";
		char kind;
		while(cin >> kind && kind != '1' && kind != '2' && kind != '3')
			cout << "Enter either 1, 2 or 3: ";
		cin.get();
		if (kind == '1')
			dmas[i] = new BaseDma(label, rating);
		else if (kind == '2') {
			cout << "color:";
			char color[LEN];
			cin.getline(color, LEN);
			dmas[i] = new LackDma(label, rating, color);
		}
		else {
			cout << "style:";
			char style[LEN];
			cin.getline(style, LEN);
			dmas[i] = new HasDma(label, rating, style);
		}
		// while(cin.get() != '\n')
		// 	continue;
	}
	cout << endl;
	for(int i = 0; i < SIZE; i++) {
		dmas[i]->View();
		cout << endl;
	}

	for(int i = 0; i < SIZE; i++) {
		delete dmas[i];
	}
	cout << "Done." << endl;
	return 0;
}