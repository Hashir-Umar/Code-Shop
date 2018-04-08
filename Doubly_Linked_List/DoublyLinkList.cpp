#include "DoublyLinkList.h"
  
DoublyLinkList::DoublyLinkList()
{
    head = NULL;
    tail = NULL;
}

DoublyLinkList::~DoublyLinkList()
{
    while (!isEmpty())
    {
        tail = head->next;
        delete head;

        if (tail == NULL)
        {
            head = NULL;
            break;
        }

        head = tail;
    }
}

bool DoublyLinkList::isEmpty()
{
    return head == NULL;
}

void DoublyLinkList::firstNode(int x)
{
    Node *ptr = new Node(x);

    head = ptr;
    tail = ptr;
}

void DoublyLinkList::insertAtHead(int x)
{
    if (isEmpty())
        firstNode(x);
    else
    {
        Node *ptr = new Node(x, NULL, head);

        head->pre = ptr;
        head = ptr;
    }
}

void DoublyLinkList::insertAtTail(int x)
{
    if (isEmpty())
        firstNode(x);
    else
    {
        Node *ptr = new Node(x, tail, NULL);

        tail->next = ptr;
        tail = ptr;
    }
}

int DoublyLinkList::deleteFromHead()
{
    int val = 0;
    if (!isEmpty())
    {
        if (head->next != NULL)
        {
            Node *temp = head;
            val = temp->x;
            head->next->pre = NULL;
            head = head->next;
            delete temp;
        }
        else
        {
            val = head->x;
            delete head;
            head = NULL;
        }
    }
    else
        cout << "\nList is Empty!!!";

    return val;
}

int DoublyLinkList::deleteFromTail()
{
    int val = 0;
    if (!isEmpty())
    {
        if (head->next != NULL)
        {
            Node *temp = tail;
            val = temp->x;
            tail->pre->next = NULL;
            tail = tail->pre;
            delete temp;
        }
        else
        {
            val = head->x;
            delete head;
            head = NULL;
        }
    }
    else
        cout << "\nList is Empty!!!";

    return val;
}

void DoublyLinkList::display()
{
    if (!isEmpty())
    {
        for (Node *ptr = head; ptr != NULL; ptr = ptr->next)
            cout << ptr->x << " ";

        cout << endl;
    }
    else
        cout << "\nList is Empty!!!" << endl;

}
