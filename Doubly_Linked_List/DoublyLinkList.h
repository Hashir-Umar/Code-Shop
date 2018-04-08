#pragma once

#include <iostream>

using namespace std;

struct Node
{
    int x;
    Node *next;
    Node *pre;

    /*Non Parameterized Constructor*/
    Node() {}

    /*Overloaded Constructor*/
    Node(int val, Node* P = NULL, Node* N = NULL)   //P and N has default values 
    {
        x = val;
        pre = P;
        next = N;
    }
};

class DoublyLinkList
{
    Node *head, *tail;
 
public:
    DoublyLinkList();
    ~DoublyLinkList();
    bool isEmpty();
    void firstNode(int);
    void insertAtHead(int);
    void insertAtTail(int);
    int deleteFromHead();
    int deleteFromTail();
    void display();
};