// Completed by:
// Alex von Schulmann	- 13975140
// Alec Xu				- 38108130

#include "pch.h"
#include <stdio.h>
#include <iostream>
#include "Node.h"

Node::Node()
{
	data = NULL;
	next = NULL;
}

Node::Node(int value)
{
	data = value;
	next = NULL;
}

Node::~Node()
{
}
