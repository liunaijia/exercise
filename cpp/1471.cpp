#include <iostream>
#include <string>
#include <valarray>

using namespace std;

template <typename K, typename V>
class Pair{
private:
	K key;
	V value;
public:
	Pair(const K& key, const V& value);
	K& getKey();
	const K& getKey() const;
	V& getValue();
	const V& getValue() const;
};

template <typename K, typename V>
Pair<K, V>::Pair(const K& key, const V& value) {
	this->key = key;
	this->value = value;
}

template <typename K, typename V>
K& Pair<K, V>::getKey() {
	return key;
}

template <typename K, typename V>
const K& Pair<K, V>::getKey() const {
	return key;
}

template <typename K, typename V>
V& Pair<K, V>::getValue() {
	return value;
}

template <typename K, typename V>
const V& Pair<K, V>::getValue() const {
	return value;
}

class Wine {
private:
	string name;
	Pair<valarray<int>, valarray<int> >* data;
	int count;
public:
	Wine();
	Wine(const char* name, int count, const int years[], const int bottles[]);
	Wine(const char* name, int count);
	~Wine();
	void getBottles();
	const string& getName() const;
	int getTotalBottles() const;
	friend ostream& operator<<(ostream& out, const Wine& wine);
};

Wine::Wine() {
	name = "none";
	data = NULL;
	count = 0;
}

Wine::Wine(const char* name, int count, const int years[], const int bottles[]) {
	this->name = string(name);
	this->count = count;
	this->data = new Pair<valarray<int>, valarray<int> >(valarray<int>(years, count), valarray<int>(bottles, count));
}

Wine::Wine(const char* name, int count) {
	this->name = string(name);
	this->count = count;
	this->data = new Pair<valarray<int>, valarray<int> >(valarray<int>(count), valarray<int>(count));
}

Wine::~Wine() {
	delete data;
}

void Wine::getBottles() {
	for(int i = 0; i < count; i++) {
		cout << "(" << i + 1 << "/" << count << ")input year and bottles:";
		cin >> data->getKey()[i] >> data->getValue()[i];
	}
}

const string& Wine::getName() const {
	return name;
}

int Wine::getTotalBottles() const {
	if (data == NULL)
		return 0;
	return data->getValue().sum();
}

ostream& operator<<(ostream& out, const Wine& wine) {
	out << wine.name << "(";
	for(int i = 0; i < wine.count; i++) {
	  	out << wine.data->getKey()[i] << "x" << wine.data->getValue()[i];
	  	if (i < wine.count - 1)
	  		out << ", ";
	}
	out << ") " << wine.getTotalBottles() << " bottles";
}

int main() {
	cout << "Enter name of wine: ";
	char name[50];
	cin.getline(name, 50);

	cout << "Enter number of years: ";
	int count;
	cin >> count;

	Wine holding(name, count);
	holding.getBottles();
	cout << holding << endl;

	const int COUNT = 3;
	int years[COUNT] = {1993, 1995, 1998};
	int bottles[COUNT] = {48, 60, 72};
	Wine more("Gushing Grape Red", COUNT, years, bottles);
	cout << more << endl;
	cout << "Total bottles for " << more.getName() << ": " << more.getTotalBottles() << endl;
	cout << "Bye" << endl;

	return 0;
}