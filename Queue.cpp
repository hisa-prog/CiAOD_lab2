#include "Queue.h"

namespace vz_struct
{
	int Queue::idCounter = 0;

	Queue::Queue()
	{
		id = ++idCounter;
		BeginQueue = nullptr;
		EndQueue = nullptr;
	}

	Queue::~Queue()
	{
		Queue_node* pointer = nullptr;

		while (!isEmpty())
		{
			pointer = BeginQueue;
			BeginQueue = pointer->next;
			delete pointer;
		}
		BeginQueue = EndQueue = nullptr;
	}

	void Queue::EnQueue(int element)
	{
		Queue_node* pointer = new Queue_node;

		pointer->Info = element;
		pointer->next = nullptr;

		if (BeginQueue == nullptr)
			BeginQueue = pointer;
		else
			EndQueue->next = pointer;
		EndQueue = pointer;
	}

	int Queue::DeQueue()
	{
		if (isEmpty()) throw "Error when taking from an empty queue!";

		int value;
		Queue_node* pointer = BeginQueue;

		value = BeginQueue->Info;
		BeginQueue = BeginQueue->next;

		if (BeginQueue == nullptr)
			EndQueue == nullptr;

		delete pointer;
		return value;
	}

	int Queue::Front() const
	{
		if (isEmpty())
			throw "error while reading an empty queue!";
	}

	bool Queue::isEmpty() const
	{
		return (BeginQueue == nullptr);
	}
}