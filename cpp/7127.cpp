#include <iostream>

const int Max = 5;

int fill_array(double*, double*);
void show_array(const double*, double*);
void revalue(double r, double*, double*);

int main() {
	using namespace std;
	double properties[Max];

	int size = fill_array(properties, properties + Max);
	show_array(properties, properties + size);
	cout << "Enter revaluation factor: ";
	double factor;
	cin >> factor;
	revalue(factor, properties, properties + size);
	show_array(properties, properties + size);
	cout << "Done.";
	return 0;
}

int fill_array(double* begin, double* end) {
	using namespace std;
	double temp;
	double* i;
	for(i = begin; i < end; i++) {
		cout << "Enter value #" << (i - begin + 1) << ": ";
		cin >> temp;
		if (!cin) {
			cin.clear();
			while(cin.get() != '\n')
				continue;
			cout << "Bad input: input process terminated." << endl;
			break;
		}
		else if (temp < 0)
			break;
		*i = temp;
	}
	return i - begin;
}

void show_array(const double* begin, double* end) {
	using namespace std;
	for(const double* i = begin; i < end; i++) {
		cout << "Property #" << (i - begin + 1) << ": $";
		cout << *i << endl;
	}
}

void revalue(double r, double* begin, double* end) {
	for(double* i = begin; i < end; i++) {
		*i *= r;
	}
}