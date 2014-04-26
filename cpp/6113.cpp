#include <iostream>

int main()
{
	using namespace std;

	cout << "Please enter one of the following choices:" << endl
		<< "c) carnivore p) pianlst t)tree g)game" << endl;

	char ch;
	bool invalid_input = true;
	while(cin.get(ch) && invalid_input)
	{
		switch(ch)
		{
			case 'c':
				cout << "A maple is a carnivore" << endl;
				invalid_input = false;
				break;
			case 'p':
				cout << "A maple is a pianlst" << endl;
				invalid_input = false;
				break;
			case 't':
				cout << "A maple is a tree" << endl;
				invalid_input = false;
				break;
			case 'g':
				cout << "A maple is a game" << endl;
				invalid_input = false;
				break;
			default:
				cout << "Please enter a c, p, t, or g: ";
				// read left char
				//cin.clear();
				while(cin.get() != '\n');
		}

	}

	return 0;
}