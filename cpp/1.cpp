#include <iostream>
#include <cmath>

int main()
{
	// using namespace std;	lazy approach
	using std::cout;
	using std::cin;
	using std::endl;
	int peak(int);

	int n;
	cout << "input a number:";
	cin >> n;
	cout << peak(n) << endl;
	
	return 0;
}

int peak(int i)
{
	return 3 * i;
}