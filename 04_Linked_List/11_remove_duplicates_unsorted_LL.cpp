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

// using map
void unsorted_ll(Node *head)
{
    Node *curr = head;
    Node *temp = NULL;
    map<int, int> mapped;

    while (curr->next != NULL)
    {
        mapped[curr->data] = 1;
        if (mapped[curr->next->data] == 1)
        {
            temp = curr->next;
            curr->next = curr->next->next;

            temp->next = NULL;
            delete temp;
        }
        else
        {
            curr = curr->next;
        }
    }
}

///////////////////////////////////////////////////////////////////////////////////////////

int main()
{
    Node *head = NULL;

    InsertAtTail(head, 11);
    InsertAtTail(head, 11);
    InsertAtTail(head, 11);
    InsertAtTail(head, 22);
    InsertAtTail(head, 22);
    InsertAtTail(head, 22);
    InsertAtTail(head, 33);
    InsertAtTail(head, 44);
    InsertAtTail(head, 55);
    InsertAtTail(head, 66);
    InsertAtTail(head, 77);
    InsertAtTail(head, 77);

    print_linked_list(head);

    unsorted_ll(head);
    print_linked_list(head);

    /////////////////////////////////////////////////////////////////////////////////

    Node *head1 = NULL;

    InsertAtTail(head1, 44);
    InsertAtTail(head1, 11);
    InsertAtTail(head1, 77);
    InsertAtTail(head1, 11);
    InsertAtTail(head1, 66);
    InsertAtTail(head1, 11);
    InsertAtTail(head1, 22);
    InsertAtTail(head1, 55);
    InsertAtTail(head1, 22);
    InsertAtTail(head1, 22);
    InsertAtTail(head1, 33);
    InsertAtTail(head1, 44);
    InsertAtTail(head1, 55);
    InsertAtTail(head1, 66);

    print_linked_list(head1);

    unsorted_ll(head1);
    print_linked_list(head1);
}

// Linked List : 11 11 11 22 22 22 33 44 55 66 77 77
// Head : 11
// Memory is free for value : 11
// Memory is free for value : 11
// Memory is free for value : 22
// Memory is free for value : 22
// Memory is free for value : 77
// Linked List : 11 22 33 44 55 66 77
// Head : 11

// Linked List : 44 11 77 11 66 11 22 55 22 22 33 44 55 66
// Head : 44
// Memory is free for value : 11
// Memory is free for value : 11
// Memory is free for value : 22
// Memory is free for value : 22
// Memory is free for value : 44
// Memory is free for value : 55
// Memory is free for value : 66
// Linked List : 44 11 77 66 22 55 33
// Head : 44