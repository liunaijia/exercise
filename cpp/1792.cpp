#include <iostream>
#include <fstream>

using namespace std;

int main(int argc, char* argv[]) {
	if (argc < 2) {
		cerr << "no file";
		return 1;
	}

	ofstream fout(argv[1]);
	char ch;
	while(cin.get(ch)) {
		fout << ch;
	}
	fout.close();
	return 0;
}