#pragma once

namespace vz_struct
{
	class Queue
	{
	private:
		int id;
		static int idCounter;

		struct Queue_node
		{
			int Info;
			Queue_node *next;
		};

		Queue_node *BeginQueue;
		Queue_node *EndQueue;

	public:
		Queue();
		~Queue();
		void EnQueue(int element);
		int DeQueue();
		bool isEmpty() const;
		int Front() const;
	};
}


