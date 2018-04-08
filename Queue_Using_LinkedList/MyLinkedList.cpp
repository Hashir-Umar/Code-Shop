#include "MyLinkedList.h"

MyLinkedList::MyLinkedList()
{
    head = NULL;
    tail = NULL;
}

MyLinkedList::MyLinkedList(const MyLinkedList& list)
{
	head = NULL;
	tail = NULL;

	Node *temp = list.head;
	
	while (temp)
	{
		insertAtTail(temp->data);
		temp = temp->next;
	}

}

 bool MyLinkedList::isEmpty() const
 {
     return head == NULL;
 }

void MyLinkedList::insertIfEmpty(int value)
{
    head = new Node(value);
    tail = head;
}

void MyLinkedList::insertAtHead(int value)
{
     if(isEmpty())
        insertIfEmpty(value);
    else
    {
        Node *temp = new Node(value, head);
        head = temp;
    }
}

void MyLinkedList::insertAtTail(int value)
{
    if(isEmpty())
        insertIfEmpty(value);
    else
    {
        Node *temp = new Node(value);
        tail->next = temp;
        tail = temp;
    }
}

MyLinkedList::~MyLinkedList()
{
    while(tail != NULL)
    {
        tail = head->next;
        delete head;
        head = tail;
    }
}

int MyLinkedList::deleteFromHead()
{
    if(!isEmpty())
    {
        Node *temp = head->next;
        int tempValue = head->data;
        delete head;
        head = temp;
		if (head == NULL)	tail = NULL;
        return tempValue;
    }
    else
    {
        std::cout << "\nList is Empty..!!" << std::endl;
        system("pause>nul");
        return -1;
    }
}

int MyLinkedList::deleteFromTail()
{

    if(!isEmpty())
    {
        if(head == tail)
        {
            int tempValue = tail->data;
            delete tail;
            head = tail = NULL;
            return tempValue;
        }
        
        Node *temp = head;
    
        while(temp->next != tail)
            temp = temp->next;
    
        int tempValue = tail->data;
        delete tail;
        tail = temp;
        tail->next = NULL;
        return tempValue;
    }
    else
    {
        std::cout << "\nList is Empty..!!" << std::endl;
        system("pause>nul");
        return -1;
    }
}

int MyLinkedList::getHeadValue() const
{
    if(!isEmpty())
        return head->data;
    else
    {
        std::cout << "\nList is Empty..!!" << std::endl;
        system("pause>nul");
        return -1;
    }
        
}

int MyLinkedList::getTailValue() const
{
    if(!isEmpty())
        return tail->data;
    else
    {
        std::cout << "\nList is Empty..!!" << std::endl;
        system("pause>nul");
        return -1;
    }
        
}

int MyLinkedList::getSize()
{
    Node *temp = head;
    int size = 0;
    while(temp != NULL && ++size)
        temp = temp->next;
    return size;
}

void MyLinkedList::display()
{
    if(!isEmpty())
    {
        Node *temp = head;

        std::cout << "[ ";
        while(1)
        {
            std::cout << temp->data;
            if(temp == tail)
                break;
            else
                std::cout << ", ";
            temp = temp->next;
        }
        std::cout << " ]";
    }
    else
    {
        std::cout << "\nList is Empty..!!" << std::endl;
    }
}