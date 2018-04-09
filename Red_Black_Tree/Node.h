#pragma once

#include <iostream>

struct Node
{
	int data;

	Node *parent;
	Node *left;
	Node *right;
	char color;

	Node(int x, Node *par = NULL, Node *l = NULL, Node *r = NULL, char col = 'R')
	{
		data = x;
		parent = par;
		left = l;
		right = r;
		color = col;
	}

	void display()
	{
		if (left)
			std::cout << left->data << "_";
		else
			std::cout << "nill_";

		std::cout << data << color << "_";

		if (right)
			std::cout << right->data << "\t";
		else
			std::cout << "nill\t";
	}
};