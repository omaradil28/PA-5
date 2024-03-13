#pragma once

#include "Data.h"
#include "PA5.h"

class QueueNode {
public:
	QueueNode(Data);
	~QueueNode();

	Data getData();
	void setData(Data);
	
	QueueNode* getpNext();
	void setpNext(QueueNode*);

private:
	Data pData;
	QueueNode* pNext;
};
