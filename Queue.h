#pragma once

#include "PA5.h"
#include "QueueNode.h"
#include "Data.h"

class Queue {
public:
	Queue();
	Queue(Queue&);
	~Queue();
	void DestroyQueue();

	QueueNode* getHead();
	QueueNode* getTail();

	void enqueue(Data);
	Data dequeue();
	bool isEmpty() const; //Cant dequeue if its empty so we need to know if its empty or not to dequeue
	void printQueue(Queue);

private:
	QueueNode* pHead;
	QueueNode* pTail;
};

std::ostream& operator << (std::ostream& lhs, Queue& rhs);
