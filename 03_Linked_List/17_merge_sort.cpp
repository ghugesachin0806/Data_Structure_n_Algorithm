//  https://bit.ly/3GsXWsz

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

///////////////////////////// Merge sort ////////////////////////////////////////////////////
Node *findmid(Node *head)
{
    Node *slow = head;
    Node *fast = head->next;

    while (fast != NULL && fast->next != NULL)
    {
        fast = fast->next->next;
        slow = slow->next;
    }

    return slow;
}

Node *merge(Node *left, Node *right)
{
    Node *curr1 = left;
    Node *curr2 = right;

    Node *temp = NULL;
    if (curr1->data <= curr2->data)
    {
        temp = curr1;
        curr1 = curr1->next;
    }
    else
    {
        temp = curr2;
        curr2 = curr2->next;
    }

    Node *mainhead = temp;

    while (curr1 != NULL && curr2 != NULL)
    {
        if (curr1->data <= curr2->data)
        {
            temp->next = curr1;
            curr1 = curr1->next;
            temp = temp->next;
        }
        else
        {
            temp->next = curr2;
            curr2 = curr2->next;
            temp = temp->next;
        }
    }

    if (curr1 == NULL)
    {
        temp->next = curr2;
    }
    else
    {
        temp->next = curr1;
    }

    return mainhead;
}

Node *mergesort(Node *head)
{
    // Base condition
    if (head == NULL || head->next == NULL)
    {
        return head;
    }

    Node *mid = findmid(head);

    Node *left = head;
    Node *right = mid->next;
    mid->next = NULL;

    left = mergesort(left);
    right = mergesort(right);

    Node *result = merge(left, right);

    return result;
}

///////////////////////////////////////////////////////////////////////////////////////////

int main()
{
    Node *head = NULL;

    InsertAtTail(head, 77);
    InsertAtTail(head, 11);
    InsertAtTail(head, 77);
    InsertAtTail(head, 44);
    InsertAtTail(head, 55);
    InsertAtTail(head, 33);
    InsertAtTail(head, 66);
    InsertAtTail(head, 33);
    InsertAtTail(head, 22);
    InsertAtTail(head, 11);

    print_linked_list(head);

    Node *temp = mergesort(head);

    print_linked_list(temp);
}

// Linked List : 77 11 77 44 55 33 66 33 22 11
// Head : 77

// Linked List : 11 11 22 33 33 44 55 66 77 77
// Head : 11