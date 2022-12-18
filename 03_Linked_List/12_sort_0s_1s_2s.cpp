// https://bit.ly/3s3fAOu

#include <bits/stdc++.h>
using namespace std;
#include <bits/stdc++.h>
using namespace std;

// Node class
class Node
{
public:
    int data;
    Node *next;

    // constructor for node creation
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }

    // Destructor to delete all the remaining nodes after program ends
    ~Node()
    {
        int value = this->data;
        if (this->next != NULL)
        {
            delete this->next; // Recursive statement
            this->next = NULL;
        }
        cout << "Memory is free for value : " << value << endl;
    }
};

// Node insertion at tail
void InsertAtTail(Node *&head, int data) // call by reference
{
    if (head == NULL)
    {
        Node *temp = new Node(data);
        head = temp;
    }
    else
    {
        Node *curr = head;
        while (curr->next != NULL)
        {
            curr = curr->next;
        }
        Node *temp = new Node(data);
        curr->next = temp;
    }
}

//  traversing through linked list
void print_linked_list(Node *head) // call by value
{
    cout << "Linked List : ";

    Node *temp = head;

    while (head != NULL)
    {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;

    cout << "Head : " << temp->data << endl;
}

///////////////////////////// solution ////////////////////////////////////////////////////
void populate(Node *&tail, Node *curr)
{
    tail->next = curr;
    tail = curr;
}

void sorted_elements(Node *&head)
{
    Node *curr = head;

    Node *zero = new Node(-1);
    Node *zerotail = zero;

    Node *one = new Node(-1);
    Node *onetail = one;

    Node *two = new Node(-1);
    Node *twotail = two;

    while (curr != NULL)
    {
        if (curr->data == 0)
        {
            populate(zerotail, curr);
        }
        else if (curr->data == 1)
        {
            populate(onetail, curr);
        }
        else if (curr->data == 2)
        {
            populate(twotail, curr);
        }
        curr = curr->next;
    }

    // is List non-empty
    twotail->next = NULL;
    if (one->next == NULL)
    {
        one->next = two->next;
    }
    if (zero->next == NULL)
    {
        zero->next = one->next;
    }

    head = zero->next;
    zerotail->next = one->next;
    onetail->next = two->next;
}

///////////////////////////////////////////////////////////////////////////////////////////

int main()
{
    Node *head = NULL;

    InsertAtTail(head, 1);
    InsertAtTail(head, 0);
    InsertAtTail(head, 2);
    InsertAtTail(head, 1);
    InsertAtTail(head, 1);
    InsertAtTail(head, 2);
    InsertAtTail(head, 0);
    InsertAtTail(head, 0);
    InsertAtTail(head, 1);
    InsertAtTail(head, 0);
    InsertAtTail(head, 2);
    InsertAtTail(head, 0);

    print_linked_list(head);

    sorted_elements(head);

    print_linked_list(head);

    delete head;
}

// Linked List : 1 0 2 1 1 2 0 0 1 0 2 0
// Head : 1

// Linked List : 0 0 0 0 0 1 1 1 1 2 2 2
// Head : 0

// Memory is free for value : 2
// Memory is free for value : 2
// Memory is free for value : 2
// Memory is free for value : 1
// Memory is free for value : 1
// Memory is free for value : 1
// Memory is free for value : 1
// Memory is free for value : 0
// Memory is free for value : 0
// Memory is free for value : 0
// Memory is free for value : 0
// Memory is free for value : 0