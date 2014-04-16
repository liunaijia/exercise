#include <iostream>

int main()
{
	using namespace std;

	int income;
	while(cin >> income) {
		if (income < 0)
			break;
		
		double tax = 0;
		if (income > 35000){
			tax += (income - 35000) * 0.2;
			income = 35000;
		}
		if (income > 15000 && income <= 35000){
			tax += (income - 15000) * 0.15;
			income = 15000;
		}
		if (income > 5000 && income <= 15000){
			tax += (income - 5000) * 0.1;
			income = 5000;
		}

		cout << "tax: " << tax << endl;
	}
	

	return 0;
}