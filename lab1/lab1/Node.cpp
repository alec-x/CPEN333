#include "pch.h"
#include <stdio.h>
#include <iostream>
#include "Node.h"

Node::Node()
{
	data = NULL;
	dataPtr = &data;
	next = NULL;
}

Node::Node(int value)
{
	data = value;
	dataPtr = &data;
	next = NULL;
}

Node::~Node()
{
}
