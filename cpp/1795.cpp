#include <iostream>
#include <fstream>
#include <set>
#include <vector>
#include <iterator>
#include <algorithm>

using namespace std;

int main() {
	string line;
	
	set<string> mat_friends;
	ifstream fin_mat("d:\\mat.dat");
	while(getline(fin_mat, line))
		mat_friends.insert(line);
	fin_mat.close();

	set<string> pat_friends;
	ifstream fin_pat("d:\\pat.dat");
	while(getline(fin_pat, line))
		pat_friends.insert(line);
	fin_pat.close();

	cout << "mat's friend:";
	copy(mat_friends.begin(), mat_friends.end(), ostream_iterator<string, char>(cout, " "));
	cout << endl;

	cout << "pat's friend:";
	copy(pat_friends.begin(), pat_friends.end(), ostream_iterator<string, char>(cout, " "));
	cout << endl;

	vector<string> all_friends;
	all_friends.resize(mat_friends.size() + pat_friends.size());
	auto it = set_union(mat_friends.begin(), mat_friends.end(), pat_friends.begin(), pat_friends.end(), all_friends.begin());
	all_friends.resize(distance(all_friends.begin(), it));

	void append_to_file(string line);
	for_each(all_friends.begin(), all_friends.end(), append_to_file);
	return 0;
}

void append_to_file(string line) {
	ofstream fout("d:\\matnpat.dat", ios_base::app);
	fout << line << endl;
	fout.close();
}