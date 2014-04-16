#include <iostream>
#include <fstream>

using namespace std;

int main(int argc, char* argv[]) {
	if (argc < 4) {
		cerr << "no input file";
		return 1;
	}

	ifstream fin1(argv[1]);
	if (!fin1.is_open()) {
		cerr << "can't open " << argv[1];
		return 1;
	}

	ifstream fin2(argv[2]);
	if (!fin2.is_open()) {
		cerr << "can't open " << argv[2];
		return 1;
	}

	ofstream fout(argv[3]);

	while(!fin1.eof() || !fin2.eof()) {
		string line1;
		if (!fin1.eof())
			getline(fin1, line1);
		string line2;
		if (!fin2.eof())
			getline(fin2, line2);
		fout << line1;
		if (!line1.empty() && !line2.empty())
			fout << " ";
		fout << line2 << endl;
	}

	fout.close();
	fin1.close();
	fin2.close();

	return 0;
}