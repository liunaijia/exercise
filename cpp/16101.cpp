#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main() {
	bool is_palindrome(const string s);
	cout << is_palindrome("madam");
	cout << is_palindrome("hi");
	return 0;
}

bool is_palindrome(const string s) {
	string reversed = s;
	reverse(reversed.begin(), reversed.end());
	return reversed == s;
}