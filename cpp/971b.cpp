#include <iostream>
#include "971.h"

int main() {
	golf g1;
	setgolf(g1, "lnj", 13);
	showgolf(g1);
	handicap(g1, 23);
	showgolf(g1);

	golf g2;
	if (setgolf(g2))
		showgolf(g2);

	return 0;
}