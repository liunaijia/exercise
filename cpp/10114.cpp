#include <iostream>

namespace SALES {
	using namespace std;

	class Sales {
	private:
		static const int QUARTERS = 4;
		double sales[QUARTERS];
		double average;
		double max;
		double min;
	public:
		Sales(const double ar[], int n);
		Sales();
		void Show() const;
	};

	Sales::Sales(const double ar[], int n) {
		min = 0;
		max = 0;
		if (n > 0){
			min = ar[0];
			max = ar[0];
		}
		double total = 0;
		for(int i = 0; i < QUARTERS; i++) {
			if (i < n)
				sales[i] = ar[i];
			else
				sales[i] = 0;

			total += sales[i];
			if (min > sales[i])
				min = sales[i];
			if (max < sales[i])
				max = sales[i];
		}
		average = total / (n > QUARTERS ? QUARTERS : n);
	}

	Sales::Sales() {
		min = 0;
		max = 0;
		double total = 0;
		int n = 0;
		for(int i = 0; i < QUARTERS; i++) {
			cout << "enter sales #" << i + 1 << ": ";
			if (!(cin >> sales[i]))
				sales[i] = 0;
			else
				n++;

			total += sales[i];
			if (i == 0 || min > sales[i])
				min = sales[i];
			if (max < sales[i])
				max = sales[i];
		}
		average = total / (n > QUARTERS ? QUARTERS : n);
	}

	void Sales::Show() const {
		for(int i = 0; i < QUARTERS; i++)
			cout << sales[i] << " ";
		cout << endl << "min:" << min;
		cout << endl << "max:" << max;
		cout << endl << "avg:" << average << endl;
	}
}

int main() {
	using namespace SALES;
	double sales[] = {10.3, 9.1, 10.5, 9.0};
	Sales s1(sales, 4);
	s1.Show();

	Sales s2;
	s2.Show();

	return 0;
}