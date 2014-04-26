#include <iostream>
#include <cstdlib>
#include <ctime>
#include <queue>
#include "1255Customer.h"

// 队列最大长度为10，每小时17～18人时，模拟1000小时，平均等待时间约1分钟。
int main() {
	using std::cin;
	using std::cout;
	using std::endl;
	using std::ios_base;
	using std::queue;

	const int MIN_PER_HR = 60;
	bool newcustomer(double x);

	std::srand(std::time(0));

	cout << "sim bank" << endl;
	cout << "enter max size of queue: ";
	int qs;
	cin >> qs;
	queue<Customer> line;

	cout << "enter simulation hours: ";
	int hours;
	cin >> hours;
	long cyclelimit = MIN_PER_HR * hours;

	cout << "enter avg number of customers per hour: ";
	double perhour;
	cin >> perhour;
	double min_per_cust;
	min_per_cust = MIN_PER_HR / perhour;

	long turnaways = 0;
	long customers = 0;
	long served = 0;
	long sum_line = 0;
	int wait_time = 0;
	long line_wait = 0;

	for (int cycle = 0; cycle < cyclelimit; cycle++) {
		if (newcustomer(min_per_cust)){
			if (line.size() == qs)
				turnaways++;
			else {
				customers++;
				Customer customer;
				customer.set(cycle);
				line.push(customer);
			}
		}
		if (wait_time <=0 && !line.empty()) {
			Customer customer = line.front();
			line.pop();
			wait_time = customer.ptime();
			line_wait += (cycle - customer.when());
			served++;
		}
		if (wait_time > 0)
			wait_time--;
		sum_line += line.size();
	}

	if (customers > 0) {
		cout << "accepted:" << customers << endl;
		cout << "served:" << served << endl;
		cout << "turnaways:" << turnaways << endl;
		cout << "avg queue size: " << (double)sum_line / cyclelimit << endl;
		cout << "avg wait time: " << (double)line_wait / served << endl;
	}
	cout << "done." << endl;
	
	
	return 0;
}

bool newcustomer(double x) {
	return std::rand() * x / RAND_MAX < 1;
}