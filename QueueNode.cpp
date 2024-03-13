#include "QueueNode.h"

//Constructor
QueueNode::QueueNode(Data data) {
	this->pData = data;
	this->pNext = nullptr;
}

//Destructor
QueueNode::~QueueNode(){}

//Setters
void QueueNode::setData(Data data) {
	pData = data;
}
void QueueNode::setpNext(QueueNode* data) {
	pNext = data;
}

//Getters
Data QueueNode::getData(){
	return pData;
}

QueueNode* QueueNode::getpNext() {
	return pNext;
}
