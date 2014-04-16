#include <iostream>
#include <cmath>
#include <string>
#include <stdexcept>

using namespace std;

template<typename T>
class bad_mean : public logic_error {
private:
	T a;
	T b;
	string msg;
public:
	bad_mean(const char* func_name, const T& a, const T& b);
	~bad_mean() throw() {}
	const char* what() const throw();
};

template<typename T>
bad_mean<T>::bad_mean(const char* func_name, const T& a, const T& b)
	: logic_error("bad_mean") {
	this->a = a;
	this->b = b;
	msg = string(func_name) + "\narg1 = " + to_string(a) + ",arg2 = " + to_string(b);
}

template<typename T>
const char* bad_mean<T>::what() const throw() {
	return msg.c_str();
}

int main() {
	double hmean(double a, double b) throw(bad_mean<double>);
	double gmean(double a, double b) throw(bad_mean<double>);

	try{
		//hmean(1, -1);
		gmean(3, -4);
	}
	catch(bad_mean<double>& e) {
		cout << e.what();
	}
	
	return 0;
}

double hmean(double a, double b) throw(bad_mean<double>) {
	if (a + b == 0)
		throw bad_mean<double>("hmean()", a, b);
	return 2.0 * a * b / (a + b);
}

double gmean(double a, double b) throw(bad_mean<double>) {
	if (a < 0 || b < 0)
		throw bad_mean<double>("gmean()", a, b);
	return sqrt(a * b);
}