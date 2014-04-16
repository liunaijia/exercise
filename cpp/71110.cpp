#include <iostream>
#include <string>

using namespace std;

struct glitz
{
	string name;
};

int main() {
	string call_by_value(const glitz p);
	string call_by_pointer(const glitz* p);

	glitz p = {"it's me."};
	cout << call_by_value(p) << endl
		<< call_by_pointer(&p) << endl;

	return 0;
}

string call_by_value(const glitz p) {
	return p.name;
}

string call_by_pointer(const glitz* p) {
	return p -> name;
}