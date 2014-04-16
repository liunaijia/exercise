#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
#include <iterator>

using namespace std;

int main() {
	void read_from_file(vector<string>& words);
	void count_words(const vector<string>& words, map<string, int>& result);

	vector<string> words;
    read_from_file(words);

    map<string, int> result;
    count_words(words, result);

    for(auto it = result.begin(); it != result.end(); it++)
    	cout << it->first << "\t" << it->second << endl;

	return 0;
}

void read_from_file(vector<string>& words) {
	ifstream fin;
    fin.open("c:\\data.txt");

    if (!fin.is_open())    // 因为即使文件不存在或无法打开，C++也不会报错，所以需要通过`is_open()`判断是否正常打开
    {
        cout << "can't open file.";
        exit(EXIT_FAILURE);    // 需要include cstdlib
    }

    string word;
    while(fin >> word) {
    	words.push_back(word);
    }

    fin.close();
}

void count_words(const vector<string>& words, map<string, int>& result) {
	set<string> unique_words(words.begin(), words.end());

	for(auto it = unique_words.begin(); it != unique_words.end(); it++) {
		result[*it] = count(words.begin(), words.end(), *it);
	}
}