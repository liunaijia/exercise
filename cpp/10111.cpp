#include <iostream>
#include "10105.h"

Account::Account(string name, string number, double money) {
	this->name = name;
	this->number = number;
	this->money = money;
}

void Account::show() const {
	using namespace std;
	cout << name << "\t" << number << "\t" << money << endl;
}

void Account::deposit(double money) {
	this->money += money;
}

void Account::withdraw(double money) {
	if (this->money >= money)
		this->money -= money;
	else
		cout << "balance not enough: " << this->money << endl;
}

int main() {
	Account a("lnj", "3339", 100);
	a.show();
	a.deposit(10);
	a.show();
	a.withdraw(50);
	a.show();
	a.withdraw(70);
	a.show();
	return 0;
}