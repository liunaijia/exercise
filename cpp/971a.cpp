#include <iostream>
#include <cstring>
#include "971.h"

using namespace std;

void setgolf(golf& g, const char* name, int hc) {
	strncpy(g.fullname, name, Len - 1);
	g.handicap = hc;
}

int setgolf(golf& g) {
	cout << "enter fullname: ";
	cin.getline(g.fullname, Len);
	if (strlen(g.fullname) == 0)
		return 0;

	cout << "enter handicap: ";
	cin >> g.handicap;
	return 1;
}

void handicap(golf& g, int hc) {
	g.handicap = hc;
}

void showgolf(const golf& g) {
	cout << g.fullname << "\t" << g.handicap << endl;
}