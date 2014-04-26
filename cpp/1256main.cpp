#include <iostream>
#include <cstdlib>
#include <ctime>
#include "1256Queue.h"
#include "1256Customer.h"

// 队列最大长度为10，每小时51人时，模拟1000小时，平均等待时间约1分钟。
// 如果一个队列，每小时17～18人的时候，平均等待时间就达到1分钟，而再增加一个ATM，吞吐量居然翻倍。为什么会这样？
// 一名客户的平均处理时间约为1～3分钟，说明客户人数太少，有时没有人办理业务，ATM闲置，而有时客户激增导致排队。所以如果增加了1台ATM，将有效
// 应对客户激增的情况（选择人少的队），所以同样等待1分钟，后者吞吐量反而增大。
int main() {
	using std::cin;
	using std::cout;
	using std::endl;
	using std::ios_base;

	const int MIN_PER_HR = 60;
	bool newcustomer(double x);

	std::srand(std::time(0));

	cout << "sim bank dual queues" << endl;
	cout << "enter max size of queue: ";
	int qs;
	cin >> qs;
	Queue line1(qs);
	Queue line2(qs);

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
	int wait_time_in_queue1 = 0;
	int wait_time_in_queue2 = 0;
	long line_wait = 0;

	for (int cycle = 0; cycle < cyclelimit; cycle++) {
		if (newcustomer(min_per_cust)){
			if (line1.isfull() && line2.isfull())
				turnaways++;
			else {
				customers++;
				Item customer;
				customer.set(cycle);
				if (line1.queuecount() < line2.queuecount())
					line1.enqueue(customer);
				else
					line2.enqueue(customer);
			}
		}
		
		if (wait_time_in_queue1 <= 0 && !line1.isempty()) {
			Item customer;
			line1.dequeue(customer);
			wait_time_in_queue1 = customer.ptime();
			line_wait += (cycle - customer.when());
			served++;
		}

		if (wait_time_in_queue2 <= 0 && !line2.isempty()) {
			Item customer;
			line2.dequeue(customer);
			wait_time_in_queue2 = customer.ptime();
			line_wait += (cycle - customer.when());
			served++;
		}
		

		if (wait_time_in_queue1 > 0)
			wait_time_in_queue1--;
		if (wait_time_in_queue2 > 0)
			wait_time_in_queue2--;

		sum_line += (line1.queuecount() + line2.queuecount());
	}

	if (customers > 0) {
		cout << "accepted:" << customers << endl;
		cout << "served:" << served << endl;
		cout << "turnaways:" << turnaways << endl;
		cout << "avg queue size: " << (double)sum_line / cyclelimit / 2 << endl;	// sum_line是两个队列的长度和，所以要/2
		cout << "avg wait time: " << (double)line_wait / served << endl;
	}
	cout << "done." << endl;
	
	
	return 0;
}

bool newcustomer(double x) {
	return std::rand() * x < RAND_MAX;
}