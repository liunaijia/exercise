#include <iostream>
#include "974.h"

int main() {
	using SALES::Sales;
	using SALES::setSales;
	using SALES::showSales;

	Sales s1, s2;
	double sales[] = {10.3, 9.1, 10.5, 9.0};
	setSales(s1, sales, 4);
	showSales(s1);

	setSales(s2);
	showSales(s2);

	return 0;	
}