#ifndef   __Node__
#define   __Node__

class Node
{
public:
	Node();
	Node(int value);
	~Node();
	int* dataPtr;
	Node* next;
	int data;

};

#endif