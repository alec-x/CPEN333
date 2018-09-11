#ifndef   __IntegerLinkedList__
#define   __IntegerLinkedList__
#include "Node.h"

class List
{
	public:
		List();
		~List();
		void Insert(int data);
		void Delete();
		int Get(int index);
		void PrintList();

	private:
		Node* head;

};



#endif
