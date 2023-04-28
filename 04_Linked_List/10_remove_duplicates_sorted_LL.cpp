// https://bit.ly/3rjMQC5

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

void sorted_duplicates(Node *head)
{
    Node *curr = head;
    Node *temp = NULL;
    while (curr->next != NULL)
    {
        if (curr->data == (curr->next)->data)
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

    sorted_duplicates(head);

    print_linked_list(head);
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