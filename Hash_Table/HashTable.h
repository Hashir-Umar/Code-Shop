#include <iostream>

#ifndef HASHTABLE_H
#define HASHTABLE_H

class HashTable
{
    private:
        struct Node
		{
            int data;
            bool fill;
            Node *next;

            Node(): data(-1), fill(false), next(NULL){ }
            Node(int data): fill(true), data(data), next(NULL){ }
        };

        int size;
        Node *table;
  
    public:
        HashTable(int);
        void insert(int);
        int returnHash(int);
        void display();
        ~HashTable();
};

#endif