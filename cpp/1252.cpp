#include <iostream>
#include <cstring>
#include <cctype>

using namespace std;

class String {
private:
	char* str;
	void init(const char* str);
	void transform(int (*pf)(int c));
public:
	String();
	String(const char* str);
	String(const String& string);
	~String();
	String& operator=(const String& string);
	void stringlow();
	void stringup();
	friend ostream& operator<<(ostream& out, const String& string);
	friend istream& operator>>(istream& in, String& string);
	friend bool operator==(String& s1, String& s2);
	friend const  String operator+(const String& s1, const String& s2);
	int has(char c) const;
};

void String::init(const char* str) {
	if (str == NULL) {
		this->str = NULL;
		return;
	}

	this->str = new char[strlen(str) + 1];
	strcpy(this->str, str);
}

String::String() {
	init(NULL);
}

String::String(const char* str) {
	init(str);
}

String::String(const String& string) {
	init(string.str);
}

String::~String() {
	delete [] str;
}

String& String::operator=(const String& string) {
	if (this == &string)
		return *this;
	delete [] str;
	init(string.str);
	return *this;
}

ostream& operator<<(ostream& out, const String& s) {
	return out << (s.str == NULL ? "NULL" : s.str);
}

istream& operator>>(istream& in, String& s) {
	char temp[80];
	in.getline(temp, 80);
	s = temp;	// 这里不要直接给s.str进行赋值，会引起s.str的旧数据不释放
	return in;
}

const String operator+(const String& s1, const String& s2) {
	char* str = new char[strlen(s1.str) + strlen(s2.str) + 1];
	strcpy(str, s1.str);
	strcat(str, s2.str);
	String string(str);
	delete [] str;
	return string;
}

bool operator==(String& s1, String& s2) {
	return strcmp(s1.str, s2.str) == 0;
}

void String::stringlow() {
	transform(tolower);
}

void String::stringup() {
	transform(toupper);
}

void String::transform(int (*pf)(int c)) {
	for(int i = 0; i < strlen(str); i++){
		str[i] = (*pf)(str[i]);
	}
}

int String::has(char c) const {
	if (str == NULL)
		return 0;

	int count = 0;
	for(int i = 0; i < strlen(str); i++) {
		if (str[i] == c)
			count++;
	}
	return count;
}

int main() {
	String s1(" and I am a C++ student.");
	String s2 = "Please enter your name: ";
	String s3;
	cout << s2;
	cin >> s3;
	s2 = "My name is " + s3;
	cout << s2 << endl;
	s2 = s2 + s1;
	s2.stringup();
	cout << "the string" << endl << s2 << endl << "contains " << s2.has('A') << " 'A' characters in it." << endl;

	s1 = "red";
	String rgb[3] = {String(s1), String("green"), String("blue")};
	cout << "enter the name of a primary color for mixing light: ";
	String ans;
	bool success = false;
	while(cin >> ans) {
		ans.stringlow();
		for(int i = 0; i < 3; i++) {
			if (ans == rgb[i]) {
				cout << "that's right!" << endl;
				success = true;
				break;
			}
		}
		if (success)
			break;
		else
			cout << "try again" << endl;
	}
	cout << "Bye" << endl;
	return 0;
}