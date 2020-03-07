#pragma once
#include "Utility.h"

const int maxqueue = 80;

typedef char Queue_entry;

class Queue {
public:
	Queue();
	Error_code serve();
	Error_code append(const Queue_entry& item);
	Error_code retrieve(Queue_entry& item) const;
	int size() const;

protected:
	int count;
	int front, rear;
	Queue_entry entry[maxqueue];
};
