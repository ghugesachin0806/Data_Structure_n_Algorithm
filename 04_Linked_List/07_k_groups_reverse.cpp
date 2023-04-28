// https://bit.ly/3tRF3ga

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

Node *reverse_k_node(Node *head, int k)
{
    if (head == NULL)
    {
        return head;
    }

    // prcossesing data
    Node *curr = head;
    Node *prev = NULL;
    Node *nextptr = NULL;

    int cnt = 0;

    while (cnt < k && curr != NULL)
    {
        nextptr = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nextptr;
        cnt++;
    }

    // Base condition
    if (curr != NULL)
    {
        head->next = reverse_k_node(curr, k);
    }

    return prev;
}

///////////////////////////////////////////////////////////////////////////////////////////

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

    head = reverse_k_node(head, 3);
    print_linked_list(head);
}

// Linked List : 11 22 33 44 55 66 77
// Head : 11

// Linked List : 33 22 11 66 55 44 77
// Head : 33
