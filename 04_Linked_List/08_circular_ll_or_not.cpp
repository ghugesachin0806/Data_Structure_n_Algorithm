// https://bit.ly/3qY0KcF

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

///////////////////////////////////////// Solution //////////////////////////////////////////////////////////////
bool circular_ll(Node *head)
{
    Node *curr = head;

    if (head == NULL)
        return false;
    while (1)
    {
        curr = curr->next;

        if (curr == head)
            return true;

        if (curr == NULL)
            return false;
    }
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////

int main()
{
    Node *tail = NULL;

    // Data Insertion
    Insert_Data_After(tail, 8, 1);
    Insert_Data_After(tail, 1, 2);
    Insert_Data_After(tail, 2, 3);
    Insert_Data_After(tail, 3, 4);
    Insert_Data_After(tail, 4, 5);
    Insert_Data_After(tail, 3, 25);

    print_linked_list(tail);

    cout << "Circular ? :" << circular_ll(tail) << endl;

    Node *temp = tail;
    tail = tail->next;
    temp->next = NULL;
    cout << "Circular ? :" << circular_ll(tail) << endl;
}

// 25 4 5 1 2 3
// tail :25

// Circular ? :1

// Circular ? :0
