#include <iostream>

int main() {
	using namespace std;
	
	int replace(char* str, char c1, char c2);

	char str[] = "xyzx1y2z3";
	int count = replace(str, 'x', 'X');
	cout << str << endl << count;

	return 0;
}

int replace(char* str, char c1, char c2) {
	int i = 0;
	int count = 0;
	char ch;
	while((ch = str[i]) != '\0') {
		if (str[i] == c1) {
			str[i] = c2;
			count++;
		}
		i++;
	}
	return count;
}