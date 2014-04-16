#include <iostream>

using namespace std;


int main() {
	double add(double x, double y);
	double sub(double x, double y);
	double mul(double x, double y);
	double* calculate(double x, double y, double (*pf[])(double, double), int n);

	double (*pf[])(double, double) = {add, sub, mul};

	double x, y;
	cout << "input two numbers: ";
	while(cin >> x >> y) {
		double* results = calculate(x, y, pf, 3);
	
		for(int i = 0; i < 3; i++)
			cout << results[i] << endl;

		delete [] results;
	}

	return 0;
}

double add(double x, double y){
	return x + y;
}

double sub(double x, double y){
	return x - y;
}

double mul(double x, double y){
	return x * y;
}

double* calculate(double x, double y, double (*pf[])(double, double), int n) {
	double* results = new double[n];
	for(int i = 0; i < n; i++)
		results[i] = (*pf[i])(x, y);

	return results;
}