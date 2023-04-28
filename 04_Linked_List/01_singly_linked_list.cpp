// Singly Linked List

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

// Node insertion at head
void InsertAtHead(Node *&head, Node *&tail, int data) //  ( &head ) <- by reference call
{
    if (head == NULL)
    {
        Node *temp = new Node(data);
        head = temp;
        tail = temp;
    }
    else
    {
        Node *temp;
        temp = new Node(data);
        temp->next = head;
        head = temp;
    }
}

// Node insertion at tail
void InsertAtTail(Node *&head, Node *&tail, int data) //  ( &tail ) <- call by reference
{
    if (tail == NULL)
    {
        Node *temp = new Node(data);
        head = temp;
        tail = temp;
    }
    else
    {
        Node *temp = new Node(data);
        tail->next = temp;
        tail = tail->next; // tail = temp;
    }
}

// Node insertion in any middle index
void InsertAtMiddle(Node *&head, Node *&tail, int position, int data)
{
    // Inserting node at first position
    if (position == 1)
    {
        InsertAtHead(head, tail, data);
        return;
    }

    int cnt = 1;
    Node *temp = head;
    while (cnt < position - 1)
    {
        temp = temp->next;
        cnt++;
    }

    // Inserting node at last position
    if (temp->next == NULL)
    {
        InsertAtTail(head, tail, data);
        return;
    }

    // Insertion at middle
    Node *newnode = new Node(data);
    newnode->next = temp->next;
    temp->next = newnode;
}

// Node Deletion
void DeletionNode(Node *&head, Node *&tail, int position)
{
    // Deletion of first node
    if (position == 1)
    {
        Node *temp = head;
        head = head->next;

        // Memory Free
        temp->next = NULL; // <- before deletion of any node always remember to point its next to NULL
        delete temp;
        return;
    }

    // Deletion of last or middle node

    Node *curr = head;
    Node *prev = NULL;

    int cnt = 1;
    while (cnt < position)
    {
        prev = curr;
        curr = curr->next;
        cnt++;
    }

    prev->next = curr->next;

    if (curr->next == NULL)
    {
        tail = prev;
    }

    // Memory Free
    curr->next = NULL; // <- before deletion of any node always remember to point its next to NULL
    delete curr;
}

//  traversing through linked list
void print_linked_list(Node *head) // call by value
{
    cout << "Linked List : ";

    while (head != NULL)
    {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

int main()
{
    // One way of creating linked list

    // Node created in heap
    Node *node1 = new Node(110);

    // Node head pointer
    Node *head1 = node1;

    // Node tail pointer
    Node *tail1 = node1;

    cout << "Data of node : " << head1->data << endl;
    cout << "Address of node : " << head1->next << endl;

    InsertAtHead(head1, tail1, 119);
    InsertAtHead(head1, tail1, 118);
    // Printing Linked List
    print_linked_list(head1);
    cout << "head : " << head1->data << endl;
    cout << "tail : " << tail1->data << endl;

    InsertAtTail(head1, tail1, 111);
    InsertAtTail(head1, tail1, 112);
    InsertAtTail(head1, tail1, 118);
    print_linked_list(head1);
    cout << "head : " << head1->data << endl;
    cout << "tail : " << tail1->data << endl;

    //////////////////////////////////////////////////////////////////////////////////\


    // Mostly used way of creating linked list

    Node *head = NULL;
    Node *tail = NULL;

    // Insertion at head
    InsertAtHead(head, tail, 9);
    InsertAtHead(head, tail, 8);
    print_linked_list(head);
    cout << "head : " << head->data << endl;
    cout << "tail : " << tail->data << endl;

    // Insertion at tail
    InsertAtTail(head, tail, 11);
    InsertAtTail(head, tail, 12);
    InsertAtTail(head, tail, 18);
    print_linked_list(head);
    cout << "head : " << head->data << endl;
    cout << "tail : " << tail->data << endl;

    // Insertion at middle
    InsertAtMiddle(head, tail, 3, 78);
    InsertAtMiddle(head, tail, 1, 100);
    InsertAtMiddle(head, tail, 8, 88);
    print_linked_list(head);
    cout << "head : " << head->data << endl;
    cout << "tail : " << tail->data << endl;

    // Deletion by position
    print_linked_list(head);

    DeletionNode(head, tail, 3); // Middle element
    print_linked_list(head);
    cout << "head : " << head->data << endl;
    cout << "tail : " << tail->data << endl;

    DeletionNode(head, tail, 1); // First element
    print_linked_list(head);
    cout << "head : " << head->data << endl;
    cout << "tail : " << tail->data << endl;

    DeletionNode(head, tail, 6); // last element
    print_linked_list(head);
    cout << "head : " << head->data << endl;
    cout << "tail : " << tail->data << endl;

    delete head; // need to delete all the nodes , because they are in heap memory , manual heap removal is needed

    delete head1;
}

// Data of node : 110
// Address of node : 0

// Linked List : 118 119 110
// head : 118
// tail : 110

// Linked List : 118 119 110 111 112 118
// head : 118
// tail : 118

//////////////////////////////////////////////////////////////////////////////////////

// Linked List : 8 9
// head : 8
// tail : 9

// Linked List : 8 9 11 12 18
// head : 8
// tail : 18

// Linked List : 100 8 9 78 11 12 18 88
// head : 100
// tail : 88

// Linked List : 100 8 9 78 11 12 18 88

// Memory is free for value : 9
// Linked List : 100 8 78 11 12 18 88
// head : 100
// tail : 88

// Memory is free for value : 100
// Linked List : 8 78 11 12 18 88
// head : 8
// tail : 88

// Memory is free for value : 88
// Linked List : 8 78 11 12 18
// head : 8
// tail : 18

// Memory is free for value : 18
// Memory is free for value : 12
// Memory is free for value : 11
// Memory is free for value : 78
// Memory is free for value : 8

// Memory is free for value : 118
// Memory is free for value : 112
// Memory is free for value : 111
// Memory is free for value : 110
// Memory is free for value : 119
// Memory is free for value : 118