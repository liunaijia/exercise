#include <iostream>
using namespace std;
void other();
void another();
int x = 10;
int y;

int main() {
	cout << x << endl;		// 10
	{
		int x = 4;
		cout << x << endl;	// 4
		cout << y << endl;	// y编译器初始化为0
	}
	other();	// Other: 10, 1
	another();	// extern x，所以x=10；y是static变量，内部链接性，所以y=-4，输出：another(): 10, -4
	return 0;
}

void other(){
	int y = 1;
	cout << "Other: " << x << ", " << y << endl;
}