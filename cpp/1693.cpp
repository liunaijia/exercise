#include <iostream>
#include <cctype>
#include <string>

using namespace std;

int main() {
	void to_upper(string& s);

	string s = "hello";
	to_upper(s);
	cout << s << endl;

	return 0;
}

void to_upper(string& s) {
	for(int i = 0; i < s.size(); i++) {
		s[i] = toupper(s[i]);
	}
}