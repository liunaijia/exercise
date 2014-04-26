#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>

using namespace std;

class Store {
private:
	ofstream& out;
public:
	Store(ofstream& o) : out(o) {}
	void operator()(const string& line) {
		int len = line.size();
		out.write((char*)&len, sizeof(len));
		out.write(line.data(), len);
	}
};

int main() {
	vector<string> v;
	string temp;

	cout << "Enter strings:" << endl;
	while(getline(cin, temp) && !temp.empty())
		v.push_back(temp);
	cout << "Here is your input:" << endl;
	void ShowStr(const string& str);
	for_each(v.begin(), v.end(), ShowStr);

	ofstream fout("1797.dat", ios_base::out | ios_base::binary);
	for_each(v.begin(), v.end(), Store(fout));
	fout.close();

	vector<string> v2;
	ifstream fin("1797.dat", ios_base::in | ios_base::binary);
	if (!fin.is_open()) {
		cerr << "can't open file.";
		exit(1);
	}
	void GetStrings(ifstream& fin, vector<string>& v);
	GetStrings(fin, v2);
	fin.close();
	cout << "Here are the strings read from the file:" << endl;
	for_each(v2.begin(), v2.end(), ShowStr);

	return 0;
}

void ShowStr(const string& str) {
	cout << str << endl;
}

void GetStrings(ifstream& fin, vector<string>& v) {
	int len;
	while(fin.read((char*)&len, sizeof(len))){
		char* s = new char[len];
		fin.read(s, len);
		string str(s, len);
		delete [] s;
		v.push_back(str);
	}
}
