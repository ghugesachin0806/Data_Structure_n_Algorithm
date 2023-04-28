// https://practice.geeksforgeeks.org/problems/add-two-numbers-represented-by-linked-lists/1

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
Node *reverse(Node *head)
{
    Node *curr = head;
    Node *temp = NULL;
    Node *prev = NULL;

    while (curr != NULL)
    {
        temp = curr->next;
        curr->next = prev;
        prev = curr;
        curr = temp;
    }

    return prev;
}

Node *add(Node *head1, Node *head2)
{
    Node *curr1 = head1;
    Node *curr2 = head2;
    Node *sum = NULL;
    int carry = 0;
    int temp = 0;

    while (curr1 != NULL && curr2 != NULL)
    {
        temp = curr1->data + curr2->data + carry;
        InsertAtTail(sum, temp % 10);
        carry = temp / 10;

        curr1 = curr1->next;
        curr2 = curr2->next;
    }

    while (curr1 != NULL)
    {
        temp = curr1->data + carry;
        InsertAtTail(sum, temp % 10);
        carry = temp / 10;

        curr1 = curr1->next;
    }

    while (curr2 != NULL)
    {
        temp = curr2->data + carry;
        InsertAtTail(sum, temp % 10);
        carry = temp / 10;

        curr2 = curr2->next;
    }

    if (carry != 0)
    {
        InsertAtTail(sum, carry);
    }

    return sum;
}

Node *soln(Node *head1, Node *head2)
{
    head1 = reverse(head1);
    head2 = reverse(head2);

    Node *ans = add(head1, head2);
    ans = reverse(ans);

    return ans;
}

///////////////////////////////////////////////////////////////////////////////////////////

int main()
{
    Node *head1 = NULL;
    Node *head2 = NULL;

    InsertAtTail(head1, 7);
    InsertAtTail(head1, 8);
    InsertAtTail(head1, 9);
    InsertAtTail(head1, 9);

    print_linked_list(head1);

    InsertAtTail(head2, 3);
    InsertAtTail(head2, 7);
    InsertAtTail(head2, 5);
    InsertAtTail(head2, 7);
    InsertAtTail(head2, 5);

    print_linked_list(head2);

    Node *temp = soln(head1, head2);

    print_linked_list(temp);
}

// Linked List : 7 8 9 9
// Head : 7

// Linked List : 3 7 5 7 5
// Head : 3

// Linked List : 4 5 4 7 4
// Head : 4