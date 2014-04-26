#include <iostream>
#include <string>

using namespace std;

template <typename T, int n>
class QueueTp {
private:
	T items[n];
	int head;
	int length;
public:
	QueueTp();
	bool enqueue(const T& t);
	bool dequeue(T& t);
	bool isEmpty() const;
	bool isFull() const;
	int getLength() const;
};

template <typename T, int n>
QueueTp<T, n>::QueueTp() {
	head = 0;
	length = 0;
}

template <typename T, int n>
bool QueueTp<T, n>::isEmpty() const {
	return length == 0;
}

template <typename T, int n>
bool QueueTp<T, n>::isFull() const {
	return length == n;
}

template <typename T, int n>
bool QueueTp<T, n>::enqueue(const T& t) {
	if (isFull())
		return false;
	int i = (head + length) % n;
	items[i] = t;
	length++;
	return true;
}

template <typename T, int n>
bool QueueTp<T, n>::dequeue(T& t) {
	if (isEmpty())
		return false;
	t = items[head];
	head = (head + 1) % n;
	length--;
}

template<typename T, int n>
int QueueTp<T, n>::getLength() const {
	return length;
}

class Worker {
private:
	string fullname;
	long id;
protected:
	virtual void Data() const;
	virtual void Get();
public:
	Worker() : fullname("no one"), id(0L) {}
	Worker(const string& s, long n) : fullname(s), id(n) {}
	virtual ~Worker() = 0;
	virtual void Set() = 0;
	virtual void Show() const = 0;
	void show() const {cout << fullname << "\t" << id;}
};

void Worker::Data() const {
	cout << "Name: " << fullname << endl;
	cout << "Employee ID: " << id << endl;
}

void Worker::Get() {
	getline(cin, fullname);
	cout << "Enter Worker's ID: ";
	cin >> id;
}

Worker::~Worker() {

}

class Waiter: virtual public Worker {
private:
	int panache;
protected:
	void Data() const;
	void Get();
public:
	Waiter() : Worker(), panache(0) {}
	Waiter(const string& s, long n, int p = 0) : Worker(s, n), panache(p) {}
	Waiter(const Worker& wk, int p = 0) : Worker(wk), panache(p) {}
	void Set();
	void Show() const;
};

void Waiter::Set() {
	cout << "Enter waiter's name: ";
	Worker::Get();
	Get();
}

void Waiter::Show() const {
	cout << "[Category: waiter]" << endl;
	Worker::Data();
	Data();
}

void Waiter::Data() const {
	cout << "Panache rating: " << panache << endl;
}

void Waiter::Get() {
	cout << "Enter waiter's panache rating: ";
	cin >> panache;
}

class Singer: virtual public Worker {
protected:
	enum {other, alto, contralto, soprano, bass, baritone, tenor };
	const static int Vtypes = 7;
	void Data() const;
	void Get();
private:
	static string pv[Vtypes];
	int voice;
public:
	Singer() : Worker(), voice(other) {}
	Singer(const string& s, long n, int v = other) : Worker(s, n), voice(v) {}
	Singer(const Worker& wk, int v = other) : Worker(wk), voice(v) {}
	void Set();
	void Show() const;
};

string Singer::pv[Singer::Vtypes] = {"other", "alto", "contralto", "soprano", "bass", "baritone", "tenor"};

void Singer::Set() {
	cout << "Enter singer's name: ";
	Worker::Get();
	Get();
}

void Singer::Show() const {
	cout << "[Category: singer]" << endl;
	Worker::Data();
	Data();
}

void Singer::Data() const {
	cout << "Vocal range: " << pv[voice] << endl;
}

void Singer::Get() {
	cout << "Enter number for singer's vocal range:" << endl;
	for(int i = 0; i < Vtypes; i++) {
		cout << i << ": " << pv[i] << " ";
	}
	cin >> voice;
}

class SingingWaiter: public Singer, public Waiter {
protected:
	void Data() const;
	void Get();
public:
	SingingWaiter() {}
	SingingWaiter(const string& s, long n, int p = 0, int v = other) : Worker(s, n), Waiter(s, n, p), Singer(s, n, v){}
	SingingWaiter(const Worker& wk, int p = 0, int v = other) : Worker(wk), Waiter(wk, p), Singer(wk, v) {}
	SingingWaiter(const Waiter& wt, int v = other) : Worker(wt), Waiter(wt), Singer(wt, v) {}
	SingingWaiter(const Singer& wt, int p = 0) : Worker(wt), Waiter(wt, p), Singer(wt) {}
	void Set();
	void Show() const;
};

void SingingWaiter::Data() const {
	Singer::Data();
	Waiter::Data();
}

void SingingWaiter::Get() {
	Waiter::Get();
	Singer::Get();
}

void SingingWaiter::Set() {
	cout << "Enter singing waiter's name: ";
	Worker::Get();
	Get();
}

void SingingWaiter::Show() const {
	cout << "[Category: singing waiter]" << endl;
	Worker::Data();
	Data();
}

int main() {
	QueueTp<Worker*, 3> q;

	q.enqueue(new Waiter("jean", 1, 10));
	q.enqueue(new Singer("shawn", 2, 3));
	q.enqueue(new SingingWaiter("mix", 3, 10, 4));

	while(q.getLength() > 0) {
		Worker* w;
		q.dequeue(w);
		w->Show();
		delete w;
	}

	return 0;
}