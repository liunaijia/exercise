#include <string>
using namespace std;

class Account {
private:
	string name;
	string number;
	double money;
public:
	Account(string name, string number, double money);
	void show() const;
	void deposit(double money);
	void withdraw(double money);
};
