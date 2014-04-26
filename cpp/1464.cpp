#include <iostream>
#include <string>

using namespace std;

template <typename T>
class Stack {
private:
	const static int MAX = 10;
	T items[MAX];
	int top;
public:
	Stack();
	bool isempty();
	bool isfull();
	bool push(const T& item);
	bool pop(T& item);
};

template<typename T>
Stack<T>::Stack() {
	top = 0;
}

template<typename T>
bool Stack<T>::isempty() {
	return top == 0;
}

template<typename T>
bool Stack<T>::isfull() {
	return top == MAX;
}

template<typename T>
bool Stack<T>::push(const T& item) {
	if (top < MAX) {
		items[top++] = item;
		return true;
	}
	else
		return false;
}

template<typename T>
bool Stack<T>::pop(T& item) {
	if (top > 0) {
		item = items[--top];
		return true;
	}
	else
		return false;
}

class Worker {
private:
	string fullname;
	long id;
// protected:
// 	virtual void Data() const;
// 	virtual void Get();
public:
	Worker() : fullname("no one"), id(0L) {}
	Worker(const string& s, long n) : fullname(s), id(n) {}
	// virtual ~Worker() = 0;
	// virtual void Set() = 0;
	// virtual void Show() const = 0;
	void show() const {cout << fullname << "\t" << id;}
};

template <>
class Stack<Worker*> {
private:
	const static int MAX = 10;
	const Worker* items[MAX];
	int top;
public:
	Stack();
	bool isempty();
	bool isfull();
	bool push(const Worker* item);
	const Worker* pop();
};

Stack<Worker*>::Stack() {
	top = 0;
}

bool Stack<Worker*>::isempty() {
	return top == 0;
}

bool Stack<Worker*>::isfull() {
	return top == MAX;
}

bool Stack<Worker*>::push(const Worker* item) {
	if (top < MAX) {
		items[top++] = item;
		return true;
	}
	else
		return false;
}

const Worker* Stack<Worker*>::pop() {
	if (top > 0) {
		return items[--top];
	}
	else
		return NULL;
}



int main() {

	Stack<Worker*> sw;
	cout << sw.isempty() << endl;

	Worker w1;
	sw.push(&w1);
	const Worker* p = sw.pop();
	cout << &w1 << endl << p << endl;
	p->show();
	

	return 0;
}

// class Waiter: virtual public Worker {
// private:
// 	int panache;
// protected:
// 	void Data() const;
// 	void Get();
// public:
// 	Waiter() : Worker(), panache(0) {}
// 	Waiter(const string& s, long n, int p = 0) : Worker(s, n), panache(p) {}
// 	Waiter(const Worker& wk, int p = 0) : Worker(wk), panache(p) {}
// 	void Set();
// 	void Show() const;
// };

// class Singer: virtual public Worker {
// protected:
// 	enum {other, alto, contralto, soprano, bass, baritone, tenor };
// 	const static int Vtypes = 7;
// 	void Data() const;
// 	void Get();
// private:
// 	static char* pv[Vtypes];
// 	int voice;
// public:
// 	Singer() : Worker(), voice(other) {}
// 	Singer(const string& s, long n, int v = other) : Worker(s, n), voice(v) {}
// 	Singer(const Worker& wk, int v = other) : Worker(wk), voice(v) {}
// 	void Set();
// 	void Show() const;
// };

// class SingingWaiter: public Singer, public Waiter {
// protected:
// 	void Data() const;
// 	void Get();
// public:
// 	SingingWaiter() {}
// 	SingingWaiter(const string& s, long n, int p = 0, int v = other) : Worker(s, n), Waiter(s, n, p), Singer(s, n, v){}
// 	SingingWaiter(const Worker& wk, int p = 0, int v = other) : Worker(wk), Waiter(wk, p), Singer(wk, v) {}
// 	SingingWaiter(const Waiter& wt, int v = other) : Worker(wt), Waiter(wt), Singer(wt, v) {}
// 	SingingWaiter(const Singer& wt, int p = 0) : Worker(wt), Waiter(wt, p), Singer(wt) {}
// 	void Set();
// 	void Show() const;
// };


