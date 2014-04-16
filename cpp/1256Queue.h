#ifndef QUEUE_H
#define QUEUE_H

#include "1256Customer.h"

typedef Customer Item;

class Queue {
private:
	static const int Q_SIZE = 10;
	struct Node	{
		Item item;
		Node* next;
	};
	Node* front;
	Node* rear;
	int items;
	const int qsize;

	Queue(const Queue& queue) : qsize(0) {};
	Queue& operator=(const Queue&) {return *this;}
public:
	Queue(int qsize = Q_SIZE);
	~Queue();
	bool isempty() const;
	bool isfull() const;
	int queuecount() const;
	bool dequeue(Item& item);
	bool enqueue(const Item& item);
};
#endif