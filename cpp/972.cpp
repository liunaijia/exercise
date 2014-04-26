#include <iostream>
#include <string>

using namespace std;

void strcount( string str);

int main() {
	using namespace std;
	
	cout << "Enter a line: \n";
	string input;
	getline(cin, input);
	while(input != ""){
		strcount(input);
		cout << "Enter next line(empty line to quit): \n";
		getline(cin, input);
	}
	cout << "Bye\n";
	return 0;
}

void strcount( string str) {
	using namespace std;
	static int total = 0;
	int count = str.size();

	cout << "\"" << str << "\" contains ";
	
	total += count;
	cout << count << " characters\n";
	cout << total << " characters total\n";
}