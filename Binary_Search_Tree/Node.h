#pragma once

#include <iostream>

struct Node
{
	int data;
	Node *left;
	Node *right;

	Node(int val, Node *l = NULL, Node *r = NULL)
	{
		data = val;
		left = l;
		right = r;
	}
};