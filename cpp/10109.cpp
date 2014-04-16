#include <iostream>
#include <cstring>
#include "10109.h"

Stock::Stock() {
	strcpy(company, "no company");
	shares = 0;
	share_val = 0;
	set_tot();
}

Stock::Stock(const char* co, int n, double pr) {
	strcpy(this->company, co);
	this->shares = n;
	this->share_val = pr;
	set_tot();
}

const char* Stock::get_company() const {
	return this->company;
}

const int Stock::get_shares() const {
	return shares;
}

const double Stock::get_share_val() const {
	return share_val;
}

const double Stock::get_total_val() const {
	return total_val;
}

int main(){
	using namespace std;

	Stock s1;
	cout << s1.get_company() << endl;
	cout << s1.get_shares() << endl;
	cout << s1.get_share_val() << endl;
	cout << s1.get_total_val() << endl;

	Stock s2("VANCL", 12000, 8.8);
	cout << s2.get_company() << endl;
	cout << s2.get_shares() << endl;
	cout << s2.get_share_val() << endl;
	cout << s2.get_total_val() << endl;

	return 0;
}