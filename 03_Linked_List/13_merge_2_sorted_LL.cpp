// https://bit.ly/3rfFdfV

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

Node *merge_ll(Node *head1, Node *head2)
{
    Node *head = NULL;
    Node *curr1 = head1;
    Node *curr2 = head2;
    Node *tail = NULL;

    if (curr1->data <= curr2->data)
    {
        head = curr1;
        tail = curr1;
        curr1 = curr1->next;
    }
    else
    {
        head = curr2;
        tail = curr2;
        curr2 = curr2->next;
    }

    while (curr1 != NULL && curr2 != NULL)
    {
        if (curr1->data <= curr2->data)
        {
            tail->next = curr1;
            tail = curr1;
            curr1 = curr1->next;
        }
        else
        {
            tail->next = curr2;
            tail = curr2;
            curr2 = curr2->next;
        }

        if (curr1 == NULL)
        {
            tail->next = curr2;
        }
        else
        {
            tail->next = curr1;
        }
    }

    return head;
}
///////////////////////////////////////////////////////////////////////////////////////////

int main()
{
    Node *head1 = NULL;
    Node *head2 = NULL;

    InsertAtTail(head1, 7);
    InsertAtTail(head1, 17);
    InsertAtTail(head1, 27);
    InsertAtTail(head1, 37);
    InsertAtTail(head1, 47);
    InsertAtTail(head1, 57);
    InsertAtTail(head1, 67);
    InsertAtTail(head1, 77);

    print_linked_list(head1);

    InsertAtTail(head2, 3);
    InsertAtTail(head2, 13);
    InsertAtTail(head2, 27);
    InsertAtTail(head2, 29);
    InsertAtTail(head2, 36);
    InsertAtTail(head2, 48);

    print_linked_list(head2);

    Node *head = merge_ll(head1, head2);
    print_linked_list(head);
}

// 1st linked list
// Linked List : 7 17 27 37 47 57 67 77
// Head : 7

// 2nd linked list
// Linked List : 3 13 27 29 36 48
// Head : 3

// merged linked list
// Linked List : 3 7 13 17 27 27 29 36 37 47 48 57 67 77
// Head : 3