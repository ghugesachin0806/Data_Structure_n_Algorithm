// Doubly Linked List

#include <bits/stdc++.h>
using namespace std;

// Node creation
class Node
{
public:
    int data;
    Node *prev;
    Node *next;

    // Constructor
    Node(int data)
    {
        this->data = data;
        this->prev = NULL;
        this->next = NULL;
    }

    // destructor
    ~Node()
    {
        int value = this->data;
        if (this->next != NULL)
        {
            delete this->next; // Recursive statement
            this->next = NULL;
            this->prev = NULL;
        }
        else
        {
            this->prev = NULL;
        }

        cout << "Memory is free for value : " << value << endl;
    }
};

// Insertion at head
void InsertionAtHead(Node *&head, Node *&tail, int data)
{
    if (head == NULL)
    {
        Node *temp = new Node(data);
        head = temp;
        tail = temp;
    }
    else
    {
        Node *temp = new Node(data);
        temp->next = head;
        head->prev = temp;
        head = temp;
    }
}

// Insertion at Tail
void InsertionAtTail(Node *&head, Node *&tail, int data)
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
        temp->prev = tail;
        tail->next = temp;
        tail = temp;
    }
}

// Insertion at any position
void InsertAtPosition(Node *&head, Node *&tail, int position, int data)
{
    // Insert at head
    if (position == 1)
    {
        InsertionAtHead(head, tail, data);
        return;
    }

    int cnt = 1;

    Node *temp = head;

    while (cnt < position - 1)
    {
        temp = temp->next;
        cnt++;
    }

    // Insertion at tail
    if (temp->next == NULL)
    {
        InsertionAtTail(head, tail, data);
        return;
    }

    // Insertion at middle
    Node *newnode = new Node(data);

    newnode->next = temp->next;
    newnode->prev = temp;
    temp->next = newnode;
    (temp->next)->prev = newnode; // temp->next->prev = newnode;
}

// Node deletion
void DeletionNode(Node *&head, Node *&tail, int position)
{
    // Deletion of first node
    if (position == 1)
    {
        Node *temp = head;
        (temp->next)->prev = NULL; // temp->next->prev =NULL;
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

    // Memory deletion
    curr->next = NULL;
    curr->prev = NULL;
    delete curr;

    if (prev->next == NULL)
    {
        tail = prev;
    }
}

// Gives length of linked list
int getLength(Node *&head)
{
    int len = 0;
    Node *temp = head;
    while (temp != NULL)
    {
        len++;
        temp = temp->next;
    }
    return len;
}

// Traversing through linked list
void print_linkedlist(Node *&head, Node *&tail)
{
    Node *temp = head;

    cout << "Linked List : ";
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;

    cout << "Head : " << head->data << " "
         << "Tail : " << tail->data << endl;

    cout << "Toatal elements : " << getLength(head) << endl;
    cout << endl;
}

int main()
{

    // One way of creating doubly linked list

    Node *node = new Node(10);
    Node *head1 = node;
    Node *tail1 = node;

    InsertionAtHead(head1, tail1, 109);
    InsertionAtHead(head1, tail1, 119);
    print_linkedlist(head1, tail1);

    InsertionAtTail(head1, tail1, 111);
    InsertionAtTail(head1, tail1, 112);
    cout << "Toatal elements : " << getLength(head1) << endl;
    print_linkedlist(head1, tail1);

    ///////////////////////////////////////////////////////////////////

    // Mostly used way of creating linked list

    Node *head = NULL;
    Node *tail = NULL;

    // Insertion at head
    InsertionAtHead(head, tail, 9);
    InsertionAtHead(head, tail, 19);
    print_linkedlist(head, tail);

    InsertionAtHead(head, tail, 8);
    print_linkedlist(head, tail);

    InsertionAtHead(head, tail, 7);
    print_linkedlist(head, tail);

    // Insertion at tail
    InsertionAtTail(head, tail, 11);
    print_linkedlist(head, tail);

    InsertionAtTail(head, tail, 12);
    print_linkedlist(head, tail);

    // Insertion at any position
    InsertAtPosition(head, tail, 3, 90);
    print_linkedlist(head, tail);

    InsertAtPosition(head, tail, 1, 100); // First position
    print_linkedlist(head, tail);

    InsertAtPosition(head, tail, 3, 190);
    print_linkedlist(head, tail);

    InsertAtPosition(head, tail, 10, 200); // Last position
    print_linkedlist(head, tail);

    // Deletion by position
    DeletionNode(head, tail, 2);
    print_linkedlist(head, tail);

    DeletionNode(head, tail, 1);
    print_linkedlist(head, tail);

    DeletionNode(head, tail, 8);
    print_linkedlist(head, tail);

    delete head; // need to delete all the nodes , because they are in heap memory , manual heap removal is needed

    delete head1;
}

// Linked List : 119 109 10         
// Head : 119 Tail : 10
// Toatal elements : 3

// Toatal elements : 5
// Linked List : 119 109 10 111 112 
// Head : 119 Tail : 112
// Toatal elements : 5

// Linked List : 19 9 
// Head : 19 Tail : 9
// Toatal elements : 2

// Linked List : 8 19 9
// Head : 8 Tail : 9
// Toatal elements : 3

// Linked List : 7 8 19 9
// Head : 7 Tail : 9
// Toatal elements : 4

// Linked List : 7 8 19 9 11
// Head : 7 Tail : 11
// Toatal elements : 5

// Linked List : 7 8 19 9 11 12
// Head : 7 Tail : 12
// Toatal elements : 6

// Linked List : 7 8 90 19 9 11 12
// Head : 7 Tail : 12
// Toatal elements : 7

// Linked List : 100 7 8 90 19 9 11 12
// Head : 100 Tail : 12
// Toatal elements : 8

// Linked List : 100 7 190 8 90 19 9 11 12
// Head : 100 Tail : 12
// Toatal elements : 9

// Linked List : 100 7 190 8 90 19 9 11 12 200 
// Head : 100 Tail : 200
// Toatal elements : 10

// Memory is free for value : 7
// Linked List : 100 190 8 90 19 9 11 12 200
// Head : 100 Tail : 200
// Toatal elements : 9

// Memory is free for value : 100
// Linked List : 190 8 90 19 9 11 12 200
// Head : 190 Tail : 200
// Toatal elements : 8

// Memory is free for value : 200
// Linked List : 190 8 90 19 9 11 12
// Head : 190 Tail : 12
// Toatal elements : 7

// Memory is free for value : 12
// Memory is free for value : 11
// Memory is free for value : 9
// Memory is free for value : 19
// Memory is free for value : 90
// Memory is free for value : 8
// Memory is free for value : 190


// Memory is free for value : 112
// Memory is free for value : 111
// Memory is free for value : 10
// Memory is free for value : 109
// Memory is free for value : 119