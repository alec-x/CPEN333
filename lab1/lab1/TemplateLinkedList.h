// Completed by:
// Alex von Schulmann	- 13975140
// Alec Xu				- 38108130

#ifndef   __TemplateLinkedList__
#define   __TemplateLinkedList__
#include <stdio.h>
#include <iostream>

// Node Implementation.
template <class T>
class Node
{
	public:
		Node();
		Node(T value);
		~Node();
		Node* next;
		T data;
};

template <class T>
Node<T>::Node()
{
	data = NULL;
	next = NULL;
}

template <class T>
Node<T>::Node(T value)
{
	data = value;
	next = NULL;
}

template <class T>
Node<T>::~Node()
{
}

// LinkedList Implementation
template <class T>
class List
{
public:
	List();
	~List();
	void Insert(T data);
	void Delete();
	int Get(int index);
	void PrintList();

private:
	Node<T>* head;

};

template <class T>
List<T>::List()
{
	head = NULL;
}

template <class T>
List<T>::~List()
{
}

template <class T>
void List<T>::Insert(T data)
{
	Node<T>* insertion = new Node<T>(data);

	// Traverse to end of list
	Node<T>* temp = head;

	if (head == NULL)
	{
		head = insertion;
		return;
	}

	while (temp->next != NULL)
	{
		temp = temp->next;
	}

	temp->next = insertion;

}

template <class T>
void List<T>::Delete()
{
	Node<T>* temp = head;
	Node<T>* prev = NULL;

	// Nothing left to delete
	if (head == NULL)
	{
		return;
	}

	// Traverse to end of list
	while (temp->next != NULL)
	{
		prev = temp;
		temp = temp->next;
	}

	prev->next = NULL;
	delete(temp);
}

template <class T>
int List<T>::Get(int index)
{
	Node<T>* temp = head;
	int counter = 0;

	// If no data in list, throw exception.
	if (head == NULL)
	{
		throw std::invalid_argument("No data in list");
	}

	// Traverse to index (or end of list)
	while (counter < index && temp->next != NULL)
	{
		temp = temp->next;
		counter++;
	}

	// Return data if at index, if index out of bounds throw exception.
	if (counter == index)
	{
		return temp->data;
	}
	else {
		throw std::invalid_argument("Index out of bounds");
	}


}

template <class T>
void List<T>::PrintList()
{
	// Traverse list
	Node<T>* temp = head;
	while (temp != NULL)
	{
		std::cout << temp->data << std::endl;
		temp = temp->next;
	}

}








#endif
