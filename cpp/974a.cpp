#include <iostream>
#include "974.h"

namespace SALES {
	using namespace std;

	void setSales(Sales& s, const double ar[], int n) {
		s.min = 0;
		s.max = 0;
		if (n > 0){
			s.min = ar[0];
			s.max = ar[0];
		}
		double total = 0;
		for(int i = 0; i < QUARTERS; i++) {
			if (i < n)
				s.sales[i] = ar[i];
			else
				s.sales[i] = 0;

			total += s.sales[i];
			if (s.min > s.sales[i])
				s.min = s.sales[i];
			if (s.max < s.sales[i])
				s.max = s.sales[i];
		}
		s.average = total / (n > QUARTERS ? QUARTERS : n);
	}

	void setSales(Sales& s) {
		s.min = 0;
		s.max = 0;
		double total = 0;
		int n = 0;
		for(int i = 0; i < QUARTERS; i++) {
			cout << "enter sales #" << i + 1 << ": ";
			if (!(cin >> s.sales[i]))
				s.sales[i] = 0;
			else
				n++;

			total += s.sales[i];
			if (i == 0 || s.min > s.sales[i])
				s.min = s.sales[i];
			if (s.max < s.sales[i])
				s.max = s.sales[i];
		}
		s.average = total / (n > QUARTERS ? QUARTERS : n);
	}


	void showSales(const Sales& s) {
		for(int i = 0; i < QUARTERS; i++)
			cout << s.sales[i] << " ";
		cout << endl << "min:" << s.min;
		cout << endl << "max:" << s.max;
		cout << endl << "avg:" << s.average << endl;
	}
}