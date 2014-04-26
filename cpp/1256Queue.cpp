#include <iostream>
#include "1256Queue.h"

Queue::Queue(int qsize) : qsize(qsize) {
	items = 0;
	front = NULL;
	rear = NULL;
}

Queue::~Queue() {
	while(front != NULL) {
		Node* next = front->next;
		delete front;
		front = next;
	}
}

bool Queue::isempty() const {
	return items == 0;
}

bool Queue::isfull() const {
	return items == qsize;
}

int Queue::queuecount() const {
	return items;
}

bool Queue::enqueue(const Item& item) {
	if (isfull())
		return false;

	Node* p = new Node;
	if (p == NULL)
		return false;	// 分配内存失败

	p->item = item;
	p->next = NULL;

	if (front == NULL)
		front = p;
	else
		rear->next = p;
	rear = p;

	items++;
	return true;
}

bool Queue::dequeue(Item& item) {
	if (isempty())
		return false;

	item = front->item;
	Node* next = front->next;
	delete front;	// maybe NULL
	front = next;
	items--;
	if (isempty())
		rear = NULL;
	return true;
}