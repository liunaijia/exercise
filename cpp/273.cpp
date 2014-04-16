#include <iostream>

using std::cout;
using std::endl;

int main()
{
	void output1();
	void output2();
	
	output1();
	output1();
	output2();
	output2();
}

void output1()
{
	cout << "Three blind mice" << endl;
}

void output2()
{
	cout << "See how they run" << endl;
}