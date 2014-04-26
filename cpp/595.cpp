#include <iostream>

int main()
{
	using namespace std;

	string months[] = {"Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"};
	int order_amount[3][12];
	int sum = 0;
	for(int year = 0; year < 3; year++){
		cout << 2010 + year << endl;
		for(int i = 0; i < 12; i++)
		{
			cout << "\t" << months[i] << ": ";
			cin >> order_amount[year][i];
			sum += order_amount[year][i];
		}
	}

	cout << sum;

	return 0;
}