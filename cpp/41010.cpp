#include <iostream>

int main()
{
	using namespace std;

	float treacle[10] = {1.1, 2.2, 3.3, 4.4, 5.5, 6.6, 7.7, 8.8, 9.9, 10.10};
	float* p_treacle = treacle;
	cout << p_treacle[0] << endl
		<< p_treacle[sizeof(treacle) / sizeof(float) - 1treacle] << endl;

	return 0;
}