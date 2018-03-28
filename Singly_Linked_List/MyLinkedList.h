#pragma once

#include <iostream>

class MyLinkedList
{
	//Node data type
    struct Node
    {  
        int data;
        Node *next;
        
        Node(){}
        
        Node(int value, Node *n = NULL)  
		{
            data = value;
            next = n;
        }
        
    };
    
    Node *head;
    Node *tail;
    
public:

    MyLinkedList();
	MyLinkedList(const MyLinkedList&);
    ~MyLinkedList();
    
    bool isEmpty() const;
    void insertIfEmpty(int);
    void insertAtHead(int);
    void insertAtTail(int);
    int deleteFromHead();
    int deleteFromTail();
    
	//getters
    int getSize();
    int getHeadValue() const;
    int getTailValue() const;
    void getList();

};
