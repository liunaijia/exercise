#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>

using namespace std;

int main() {
	vector<int> lotto(int m, int n);	

	auto v = lotto(51, 6);
	copy(v.begin(), v.end(), ostream_iterator<int, char>(cout, " "));
}

vector<int> lotto(int m, int n) {
	vector<int> v;
	for(int i = 1; i <= m; i++)
		v.push_back(i);
	random_shuffle(v.begin(), v.end());
	v.erase(v.begin() + n, v.end());
	return v;
}