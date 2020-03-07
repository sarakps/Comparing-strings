#include "Queue.h"
#include "Utility.h"
#include <iostream>
using namespace std;

Queue::Queue() 
// The Queue is initialized to be empty.
{
	count = 0;
	rear = maxqueue - 1;
	front = 0;
}


Error_code Queue::append(const Queue_entry& item)	
// Item is added to the rear of the Queue. 
// If the Queue is full return an Error_code of overflow and leave the Queue unchanged.
{
	if (count >= maxqueue) return overflow;
	count++;
	rear = ((rear + 1) == maxqueue) ? 0 : (rear + 1);
	entry[rear] = item;
	return success;
}


Error_code Queue::serve()
// The front of the Queue is removed. 
// If the Queue is empty return an Error_code of underflow.
{
	if (count <= 0) return underflow;
	count--;
	front = ((front + 1) == maxqueue) ? 0 : (front + 1);
	return success;
}


Error_code Queue::retrieve(Queue_entry& item) const
//The front of the Queue retrieved to the output parameter item. 
// If the Queue is empty return an Error_code of underflow.
{
	if (count <= 0) return underflow;
	item = entry[front];
	return success;
}

int Queue::size() const
{
	return count;
}
