// https://practice.geeksforgeeks.org/problems/clone-a-linked-list-with-next-and-random-pointer/1

#include <bits/stdc++.h>
using namespace std;

// Node class
class Node
{
public:
    int data;
    Node *next;
    Node *random;

    // constructor for node creation
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
        this->random = NULL;
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
        cout << head->data << "=";
        if (head->random == NULL)
        {
            cout << "NULL=";
        }
        else
        {
            cout << head->random->data << "=" << head->random << " ";
        }
        head = head->next;
    }
    cout << endl;

    cout << "Head : " << temp->data << endl;
}

///////////////////////////// solution using map ////////////////////////////////////////////////////

Node *clone_ll(Node *head)
{
    cout << "Using map soln  " << endl;
    Node *curr = head;
    Node *temp = new Node(-1);
    Node *traverse = temp;

    map<Node *, Node *> mapped_ll;

    while (curr != NULL)
    {
        InsertAtTail(temp, curr->data);
        traverse = traverse->next;
        mapped_ll[curr] = traverse;
        curr = curr->next;
    }

    curr = head;
    Node *rnd = temp->next;
    while (rnd != NULL)
    {
        if (curr->random != NULL)
            rnd->random = mapped_ll[curr->random];

        rnd = rnd->next;
        curr = curr->next;
    }

    return temp->next;
}

///////////////////////////////////////  optimized solution ////////////////////////////////////////////////////
Node *clone_opti(Node *head)
{
    cout << "Using optimised soln " << endl;
    Node *curr = head;
    Node *temp = new Node(-1);
    Node *traverse = temp;

    while (curr != NULL)
    {
        InsertAtTail(temp, curr->data);
        curr = curr->next;
    }

    temp = temp->next;
    traverse = temp;
    curr = head;
    Node *rnd1 = NULL;

    while (traverse != NULL)
    {
        rnd1 = curr->next;
        curr->next = traverse;
        curr = rnd1;
        rnd1 = traverse->next;
        traverse->next = curr;
        traverse = rnd1;
    }

    rnd1 = head;
    while (rnd1 != NULL)
    {
        if (rnd1->random != NULL)
            rnd1->next->random = rnd1->random->next;
        rnd1 = rnd1->next->next;
    }

    rnd1 = head;
    Node *rnd2 = NULL;
    Node *rrt = head->next;
    while (rnd1 != NULL)
    {
        rnd2 = rnd1->next;
        rnd1->next = rnd1->next->next;
        rnd1 = rnd1->next;

        if (rnd2->next != NULL)
            rnd2->next = rnd2->next->next;
        else
            rnd2->next = NULL;
    }

    return rrt;
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////

int main()
{
    Node *head = NULL;

    InsertAtTail(head, 17);
    Node *temp1 = head;
    InsertAtTail(head, 28);
    Node *temp2 = temp1->next;
    InsertAtTail(head, 39);
    Node *temp3 = temp2->next;
    InsertAtTail(head, 49);
    Node *temp4 = temp3->next;
    InsertAtTail(head, 53);
    Node *temp5 = temp4->next;
    InsertAtTail(head, 67);
    Node *temp6 = temp5->next;

    temp1->random = temp3;
    temp2->random = temp4;
    // temp3->random = temp6;
    temp4->random = temp5;
    temp5->random = temp1;
    temp6->random = temp2;

    print_linked_list(head);

    // // using map

    Node *clonehead1 = clone_ll(head);
    print_linked_list(clonehead1);

    // using optimised solution

    Node *newhead1 = clone_opti(head);
    print_linked_list(newhead1);
}

// Linked List : 17=39=0x21c3fe11ae0 28=49=0x21c3fe11b00 39=NULL=49=53=0x21c3fe11b20 53=17=0x21c3fe11770 67=28=0x21c3fe11790
// Head : 17

// Using map soln
// Linked List : 17=39=0x21c3fe15eb0 28=49=0x21c3fe15f10 39=NULL=49=53=0x21c3fe15f70 53=17=0x21c3fe11b80 67=28=0x21c3fe11be0
// Head : 17

// Using optimised soln
// Linked List : 17=39=0x21c3fe160a0 28=49=0x21c3fe160c0 39=NULL=49=53=0x21c3fe160e0 53=17=0x21c3fe16320 67=28=0x21c3fe162a0
// Head : 17