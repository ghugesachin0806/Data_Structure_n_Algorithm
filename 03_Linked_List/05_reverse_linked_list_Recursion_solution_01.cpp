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

////////////////////////////// ONE WAY OF RECURSIVE SOLUTION /////////////////////////////////////////////////////////////////
void reverse(Node *&head, Node *curr, Node *prev)
{
    // Base condition
    if (curr->next == NULL)
    {
        curr->next = prev;
        head = curr;
        return;
    }

    // Recursive call
    reverse(head, curr->next, curr);
    curr->next = prev;
}

// Solved using Recursion
// Reversing the linked list
Node *reverse_linked_list(Node *head) // call by value
{
    Node *curr = head;
    Node *prev = NULL;

    reverse(head, curr, prev);

    return head;
}
///////////////////////////////// SECOND WAY OF RECURSIVE SOLUTION ///////////////////////////////////////////////////////////////

Node *reverse_ll_second(Node *head)
{
    // Base case
    if (head->next == NULL)
    {
        return head;
    }

    Node *updated_head = reverse_ll_second(head->next);
    head->next->next = head;
    head->next = NULL;

    return updated_head;
}

int main()
{
    Node *head = NULL;

    InsertAtTail(head, 11);
    InsertAtTail(head, 22);
    InsertAtTail(head, 33);
    InsertAtTail(head, 44);
    InsertAtTail(head, 55);
    InsertAtTail(head, 66);
    InsertAtTail(head, 77);
    print_linked_list(head);

    // One way of reversing the linked list
    head = reverse_linked_list(head);
    print_linked_list(head);

    // Second way of reversing the linked list
    head = reverse_ll_second(head);
    print_linked_list(head);
    // Free memory of heap
    delete head;
}

// Linked List : 11 22 33 44 55 66 77 
// Head : 11

// Linked List : 77 66 55 44 33 22 11 
// Head : 77

// Linked List : 11 22 33 44 55 66 77 
// Head : 11

// Memory is free for value : 77      
// Memory is free for value : 66      
// Memory is free for value : 55      
// Memory is free for value : 44      
// Memory is free for value : 33      
// Memory is free for value : 22
// Memory is free for value : 11