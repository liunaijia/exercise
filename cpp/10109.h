#include <string>
using std::string;

class Stock {
private:
	char company[30];
	int shares;
	double share_val;
	double total_val;
	void set_tot() {
		total_val = share_val * shares;
	}
public:
	Stock();
	Stock(const char* co, int n = 0, double pr = 0.0);
	~Stock() {}
	// void buy(int num, double price);
	// void sell(int num, double price);
	// void update(double price);
	// void show() const;
	// const Stock& topval(const Stock& s) const;

	const char* get_company() const;
	const int get_shares() const;
	const double get_share_val() const;
	const double get_total_val() const;
};