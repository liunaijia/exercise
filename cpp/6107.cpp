#include <iostream>
#include <cstring>

int main()
{
	using namespace std;

	char s[] = "ABBCCCDDDD_";
	int a_grade, b_grade, c_grade, d_grade, f_grade;
	a_grade = b_grade = c_grade = d_grade = f_grade = 0;

	for(int i = 0; i < strlen(s); i++)
	{
		char ch = s[i];
		switch(ch)
		{
			case 'A':
				a_grade++;
				break;
			case 'B':
				b_grade++;
				break;
			case 'C':
				c_grade++;
				break;
			case 'D':
				d_grade++;
				break;
			default:
				f_grade++;
		}
	}
	cout << a_grade << endl;
	cout << b_grade << endl;
	cout << c_grade << endl;
	cout << d_grade << endl;
	cout << f_grade << endl;

	return 0;
}