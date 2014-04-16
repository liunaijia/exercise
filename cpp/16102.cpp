#include <iostream>
#include <string>
#include <algorithm>
#include <cctype>

using namespace std;

int main() {
	bool is_palindrome(const string s);
	cout << is_palindrome("~mAdam!") << endl;
	cout << is_palindrome("haha") << endl;
	return 0;
}


bool is_palindrome(const string s) {
	string trimmed;
	trimmed.resize(s.size());
	auto it = copy_if(s.begin(), s.end(), trimmed.begin(), [](char c){return isalpha(c);});
	trimmed.resize(distance(trimmed.begin(), it));

	transform(trimmed.begin(), trimmed.end(), trimmed.begin(), [](char c){return tolower(c);});

	string reversed = trimmed;
	reverse(reversed.begin(), reversed.end());
	return reversed == trimmed;
}