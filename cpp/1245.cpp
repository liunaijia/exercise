#include <iostream>

using namespace std;

class Golfer {
private:
	char* fullname;
	int games;
	int* scores;
public:
	Golfer();
	Golfer(const char* name, int g = 0);
	Golfer(const Golfer& g);
	~Golfer();
};

Golfer::Golfer() {
	cout << (void*)this << " Golfer()" << endl;
	fullname = NULL;
	games = 0;
	scores = NULL;
}

Golfer::Golfer(const char* name, int g) {
	cout << (void*)this << " Golfer(const char* name = " << name << ", int g = " << g << ")" << endl;
	fullname = new char[strlen(name) + 1];
	strcpy(fullname, name);
	games = g;
	scores = NULL;
}

Golfer::Golfer(const Golfer& g) {
	cout << (void*)this << " Golfer(const Golfer& g)" << endl;

	if (g.fullname == NULL)
		fullname = NULL;
	else {
		fullname = new char[strlen(g.fullname) + 1];
		strcpy(fullname, g.fullname);
	}

	games = g.games;

	if (g.scores == NULL)
		scores == NULL;
	else{
		int len = sizeof(g.scores) / sizeof(int);
		scores = new int[len];
		for(int i = 0; i < len; i++)
			scores[i] = g.scores[i];
	}
}

Golfer::~Golfer() {
	cout << (void*)this << " ~Golfer() " << fullname << endl;
	delete [] fullname;
	delete [] scores;
}

int main() {
	Golfer nancy;	// Golfer() ~Golfer()
	Golfer lulu("Little LuLu");	// Golfer(const char* name, int g = 0)
	Golfer roy("Roy Hobbs", 12);	// Golfer(const char* name, int g = 0)
	Golfer* par = new Golfer;	// 这里是初始化 Golfer()
	Golfer next = lulu;	// Golfer(const Golfer& g)
	Golfer hazzard = "Weed Thwacker";	// Golfer(const char* name, int g = 0)
	*par = nancy;	// 这里是对象赋值，没有重写operator=
	nancy = "Nancy Putter"; // 相当于nancy = Golfer("Nancy Putter")，调用Golfer(const char* name, int g = 0)创建了一个临时对象，把临时对象operator=给nancy变量，然后销毁临时对象
	
	// ~Golfer() 临时对象 - Nancy Putter，nancy对象中的变量和临时对象中的指针内存空间一样，所以nancy的指针这时已经被释放了
	// ~Golfer() hazzard - Weed Thwacker
	// ~Golfer() next - Little LuLu
	// ~Golfer() roy - Roy Hobbs
	// ~Golfer() lulu - Little LuLu
	// ~Golfer() nancy 出错，因为*par和nancy的成员指针指向相同区域，而par已经释放了
	// par 没有写delete，不会释放

	// 应该重写operator=方法，以防数据被破坏
	return 0;
}