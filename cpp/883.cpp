#include <iostream>
#include <string>

using namespace std;
void toupper(string& s);

int main() {
	cout << "Enter a string (q to quit): ";
	while(true) {
		string s;
		getline(cin, s);
		if (s == "q")
			break;

		toupper(s);
		cout << s << endl << "Next string (q to quit): ";
	}

	cout << "Bye." << endl;
	
	return 0;
}

void toupper(string& s) {
	for(int i = 0; i < s.size(); i++) {
		s[i] = toupper(s[i]);
	}
}