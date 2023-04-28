// Circular linked list

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

//  Insertion of data after given element
void Insert_Data_After(Node *&tail, int element, int data)
{
    // If list is empty
    if (tail == NULL)
    {
        Node *temp = new Node(data);
        temp->next = temp;
        tail = temp; // updating tail
    }
    // Non empty list
    else
    {
        Node *curr = tail;
        int cnt = 0;
        while (curr->data != element)
        {
            curr = curr->next;

            if (curr == tail)
            {
                cnt++;
                break;
            }
        }
        if (cnt == 1)
        {
            cout << "Element not Found for data : " << data << endl;
        }
        else
        {
            Node *temp = new Node(data);
            temp->next = curr->next;
            curr->next = temp;
            tail = temp; // Updating tail
        }
    }
}

// Traversing through Linked List
void print_linked_list(Node *&tail)
{
    Node *temp = tail;
    if (tail == NULL)
    {
        cout << "Linked List is empty !" << endl;
    }
    else
    {
        do
        {
            cout << temp->data << " ";
            temp = temp->next;
        } while (temp != tail);
        cout << endl;
    }

    if (tail != NULL)
    {
        cout << "tail :" << tail->data << endl;
    }
}

// Deletion Node
void Deletion_Node(Node *&tail, int data)
{
    if (tail == NULL)
    {
        cout << "Linked list is empty !" << endl;
    }

    else if (tail == tail->next)
    {
        Node *temp = tail;

        // Memory Free
        temp->next = NULL;
        tail = NULL;
        delete temp;
    }
    else
    {
        Node *curr = tail->next;
        Node *prev = tail;
        int cnt = 0;
        while (curr->data != data)
        {
            prev = curr;
            curr = curr->next;

            if (curr == tail->next)
            {
                cnt++;
                break;
            }
        }
        if (cnt == 1)
        {
            cout << "Given Element is not present for deletion ! " << endl;
        }
        else
        {
            prev->next = curr->next;

            if (tail == curr)
            {
                tail = curr->next;
            }
            // Memory Free
            curr->next = NULL;
            delete curr;
        }
    }
}

int main()
{
    Node *tail = NULL;

    print_linked_list(tail);

    // Data Insertion
    Insert_Data_After(tail, 8, 1);
    Insert_Data_After(tail, 1, 2);
    Insert_Data_After(tail, 2, 3);
    Insert_Data_After(tail, 3, 4);
    Insert_Data_After(tail, 4, 5);
    Insert_Data_After(tail, 80, 15); // Given element is not present in previous linked list
    Insert_Data_After(tail, 3, 25);
    // Printing Linked list
    print_linked_list(tail);

    ///////////////////////////////////////////////////////////////////////////////

    // Node Deletion
    Deletion_Node(tail, 45);
    print_linked_list(tail);

    Deletion_Node(tail, 3);
    print_linked_list(tail);

    Deletion_Node(tail, 25); // tail pointing node deletion
    print_linked_list(tail);

    /////////////////////////////////////////////////////////////////////////////////////////////////

    Insert_Data_After(tail, 4, 1);
    Insert_Data_After(tail, 1, 11);
    Insert_Data_After(tail, 2, 21);
    Insert_Data_After(tail, 5, 13);

    print_linked_list(tail);

    // Free Memory of Circular Linked list
    // Here before deletion of all the nodes , we have to point any one node to NUll such that all nodes will get delete.
    Node *temp = tail->next;
    tail->next = NULL;
    delete temp;
}

// Linked List is empty !

// Element not Found for data : 15

// 25 4 5 1 2 3
// tail :25

// Given Element is not present for deletion !
// 25 4 5 1 2 3
// tail :25

// Memory is free for value : 3
// 25 4 5 1 2
// tail :25

// Memory is free for value : 25
// 4 5 1 2
// tail :4

// 13 1 2 21 4 1 11 5
// tail :13
// Memory is free for value : 13
// Memory is free for value : 5
// Memory is free for value : 11
// Memory is free for value : 1
// Memory is free for value : 4
// Memory is free for value : 21
// Memory is free for value : 2
// Memory is free for value : 1