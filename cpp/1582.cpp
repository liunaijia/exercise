#include <iostream>
#include <cmath>
#include <stdexcept>

using namespace std;

class bad_hmean : public logic_error {
public:
	bad_hmean(const string& func_name, const string& reason);
};

bad_hmean::bad_hmean(const string& func_name, const string& reason)
	: logic_error("@" + func_name + ":" + reason) {

}

class bad_gmean : public logic_error {
public:
	bad_gmean(const string& func_name, const string& reason);
};

bad_gmean::bad_gmean(const string& func_name, const string& reason)
	: logic_error("@" + func_name + ":" + reason) {

}


int main() {
	double hmean(double a, double b) throw(bad_hmean);
	double gmean(double a, double b) throw(bad_gmean);

	try{
		hmean(1, -1);
		gmean(3, -4);
	}
	catch(bad_hmean& e) {
		cout << e.what();
	}
	catch(bad_gmean& e) {
		cout << e.what();
	}

	return 0;
}

double hmean(double a, double b) throw(bad_hmean) {
	if (a + b == 0)
		throw bad_hmean("hmean()", "a + b = 0");
	return 2.0 * a * b / (a + b);
}

double gmean(double a, double b) throw(bad_gmean) {
	if (a < 0 || b < 0)
		throw bad_gmean("gmean()", "a < 0 or b < 0");
	return std::sqrt(a * b);
}