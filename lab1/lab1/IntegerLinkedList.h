#ifndef   __IntegerLinkedList__
#define   __IntegerLinkedList__
#include "IntegerLinkedList.h"

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

class Node 
{
	public:
		Node();
		~Node();
		int* dataPtr;
		Node* next;
		int data;

};


#endif
