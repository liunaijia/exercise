#include <iostream>
#include <fstream>

int main()
{
	using namespace std;

	ifstream fin;
	fin.open("6118.cpp");
	int size = 0;
	char ch;
	while(fin.get(ch))
	{
		cout << ch;
		size++;
	}
	fin.close();

	cout << size;	// 和文件大小不一样，因为windows使用\r\n

	return 0;
}