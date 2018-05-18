#include "HashTable.h"

HashTable::HashTable(int size)
{
    this->size = size;
    table = new Node[size];
}

void HashTable::insert(int number)
{
    int index = returnHash(number);

    if(!table[index].fill)
    {   
        table[index].data = number;
        table[index].fill = true;
        table[index].next = NULL;
    }
    else
    {
        Node* temp = &table[index];

        while(temp->next != NULL)
            temp = temp->next;
        
        temp->next = new Node(number);
    }
}

int HashTable::returnHash(int number)
{
    return number % size;
}

void HashTable::display()
{
    for (int i = 0; i < size; i++)
    {
		if (table[i].fill)
		{
			std::cout << "Index " << i << ": " << table[i].data;

			if (table[i].next)
			{
				Node* temp = table[i].next;

				while (temp != NULL)
				{
					std::cout << " -> " << temp->data;
					temp = temp->next;
				}

				std::cout << std::endl;
			}
			else
				std::cout << std::endl;
		}
		else
			std::cout << "Index " << i << ": NULL" << std::endl;
	}
}

HashTable::~HashTable()
{

	for (int i = 0; i < size; i++)
	{
		if (table[i].next)
		{
			while (table[i].next != NULL)
			{
				Node *temp = &table[i];
				Node *pre = temp;

				int i = 0;

				while (temp->next != NULL)
				{
					if (i++ == 0)
						temp = temp->next;
					else
					{
						pre = pre->next;
						temp = temp->next;
					}
				}

				delete temp;
				pre->next = NULL;
			}
		}
	}

    delete[] table;
	size = 0;
}