#include <iostream>

int main()
{
	using namespace std;

	string months[] = {"Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"};
	int order_amount[12];
	int sum = 0;
	for(int i = 0; i < 12; i++)
	{
		cout << months[i] << ": ";
		cin >> order_amount[i];
		sum += order_amount[i];
	}

	cout << sum;

	return 0;
}