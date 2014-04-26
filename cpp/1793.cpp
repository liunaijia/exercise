#include <iostream>
#include <fstream>

using namespace std;

int main(int argc, char* argv[]) {
	if (argc < 3) {
		cerr << "no input file";
		return 1;
	}

	ifstream fin(argv[1], ios_base::binary);
	if (!fin.is_open()) {
		cerr << "can't open " << argv[1];
		return 1;
	}

	ofstream fout(argv[2], ios_base::binary);

	const int BUFFER_SIZE = 1024;
	char buffer[BUFFER_SIZE];
	int readed;

	do {
		fin.read(buffer, BUFFER_SIZE);
		readed = fin.gcount();
		fout.write(buffer, readed);
	}while(readed > 0);
		
	fout.close();
	fin.close();

	return 0;
}