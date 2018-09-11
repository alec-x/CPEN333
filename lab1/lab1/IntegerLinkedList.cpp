#include "pch.h"
#include <stdio.h>
#include <iostream>
#include "IntegerLinkedList.h"

List::List()
{
	head = NULL;
}

List::~List()
{
}

void List::Insert(int data)
{
	Node* insertion = new Node(data);
	
	// Traverse to end of list
	Node* temp = head;
	
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

void List::Delete()
{
	Node* temp = head;
	Node* prev = NULL;

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

int List::Get(int index)
{
	Node* temp = head;
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

void List::PrintList()
{
	// Traverse list
	Node* temp = head;
	while (temp != NULL)
	{
		std::cout << temp->data << std::endl;
		temp = temp->next;
	}

}
