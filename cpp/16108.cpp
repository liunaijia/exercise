#include <iostream>
#include <set>
#include <iterator>
#include <algorithm>

using namespace std;

int main() {
	string mat_friends[] = {"tom", "jerry", "jenny", "alex", "mike"};
	string pat_friends[] = {"tom", "jerry", "joseph", "daiyu", "baochai"};

	sort(mat_friends, mat_friends + 5);
	copy(mat_friends, mat_friends + 5, ostream_iterator<string, char>(cout, " "));
	cout << endl;

	sort(pat_friends, pat_friends + 5);
	copy(pat_friends, pat_friends + 5, ostream_iterator<string, char>(cout, " "));
	cout << endl;

	vector<string> all_friends;
	all_friends.resize(10);
	merge(mat_friends, mat_friends + 5, pat_friends, pat_friends + 5, all_friends.begin());
	auto it = unique(all_friends.begin(), all_friends.end());
	all_friends.resize(distance(all_friends.begin(), it));
	copy(all_friends.begin(), all_friends.end(), ostream_iterator<string, char>(cout, " "));
}