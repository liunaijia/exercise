#include <iostream>

int main()
{
	using namespace std;

	const int STRSIZE = 20;
	struct bop
	{
		char fullname[STRSIZE];
		char title[STRSIZE];
		char bopname[STRSIZE];
		int preference;
	};

	bop persons[3] = 
	{
		{"FN0", "T0", "N0", 0},
		{"FN1", "T1", "N1", 1},
		{"FN2", "T2", "N2", 2}
	};

	cout << "Benevolent Order of Programmers Report" << endl
		<< "a. display by name\tb. display by title\nc. display by bopname\td. display by preference\nq. quit";

	char cmd;
	bool bye = false;
	while(cin >> cmd && !bye)	
	{
		switch(cmd)
		{
			case 'a':
				for(int i = 0; i < 3; i++)
					cout << persons[i].fullname << endl;
				cout << "Next choice: ";
				break;
			case 'b':
				for(int i = 0; i < 3; i++)
					cout << persons[i].title << endl;
				cout << "Next choice: ";
				break;
			case 'c':
				for(int i = 0; i < 3; i++)
					cout << persons[i].bopname << endl;
				cout << "Next choice: ";
				break;
			case 'd':
				for(int i = 0; i < 3; i++)
					cout << persons[i].preference << endl;
				cout << "Next choice: ";
				break;
			case 'q':
				bye = true;
				cout << "bye!" << endl;
				break;
			default:
				cout << "please enter a, b, c, d or q." << endl;
		}
	}
	

	return 0;
}