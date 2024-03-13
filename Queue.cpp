#include "Queue.h"
using std::cout;

Queue::Queue() {
	pHead = nullptr;
	pTail = nullptr;
}
 
Queue::Queue(Queue& copy) {
	pHead = nullptr;
	pTail = nullptr;

	QueueNode* current = copy.getHead();
	while (current != nullptr)
	{
		enqueue(current->getData());
		current = current->getpNext();
	}
}

Queue::~Queue() {
	DestroyQueue();
};

void Queue::DestroyQueue() {
	
	QueueNode* current = getHead();
	while (current != nullptr)
	{
		QueueNode* del = current;
		current = current->getpNext();
		delete del;
	}

	pHead = nullptr;
	pTail = nullptr;
}

QueueNode* Queue::getHead() {
	return pHead;
}

QueueNode* Queue::getTail() {
	return pTail;
}

void Queue::enqueue(Data data) {
	QueueNode* newNode = new QueueNode(data); //Allocates memory for new node
	if (pHead == nullptr) {
		pHead = pTail = newNode;
	}
	else{
		newNode->setpNext(pHead);
		pTail = newNode;
	}
}

Data Queue::dequeue() {
	Data last = pHead->getData();
	auto oldHead = pHead;
	pHead = pHead->getpNext();
	delete oldHead;

	return last;
}

bool Queue::isEmpty() const{
	return pHead == nullptr;
}

void Queue::printQueue(Queue print) {

	QueueNode* current = print.getHead();
	while (current != nullptr)
	{
		cout << current->getData() << " ";
		current = current->getpNext();
	}
}

std::ostream& operator << (std::ostream& lhs, Queue& rhs) {
	rhs.printQueue(rhs);
	return lhs;
}
