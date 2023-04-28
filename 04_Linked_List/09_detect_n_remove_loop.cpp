//  https://bit.ly/3rSdTDo

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
void InsertAtTail(Node *&head, Node *&tail, int data) //  ( &tail ) <- call by reference
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
        tail->next = temp;
        tail = tail->next; // tail = temp;
    }
}

///////////////////////////////////////////////// Solved using map ////////////////////////////////////////////////////
void loop_found(Node *head)
{
    Node *temp = head;
    Node *curr = NULL;

    //  If value is not provided to key in map , then it by default have '0' value for initialized key
    map<Node *, int> mapped_ll;

    while (temp != NULL)
    {
        if (mapped_ll[temp] == 1) // Here map have initialized with only key and compared , so value of key is '0' by default
        {
            cout << "Looped found at value " << temp->data << endl;
            cout << " and removed ! " << endl;
            curr->next = NULL;
            return;
        }
        mapped_ll[temp] = 1;
        curr = temp;
        temp = temp->next;
    }
    cout << "No loop found !" << endl;
    return;
}

///////////////////////////////////// Floyd's cycle algo /////////////////////////////////////////////////////////////

void floyd_algo(Node *head)
{
    Node *slow = head;
    Node *fast = head;
    Node *temp = NULL;

    while (fast != NULL)
    {
        fast = fast->next;
        if (fast != NULL)
            fast = fast->next;
        else
        {
            cout << "Loop is not found !" << endl;
            return;
        }

        temp = slow;
        slow = slow->next;

        if (fast == slow)
        {
            cout << "Loop is found at : ";
            slow = head;
            while (1)
            {
                if (slow == fast)
                {
                    cout << slow->data << endl;
                    temp->next = NULL;
                    return;
                }

                // Now increament both the pointer by only one step
                temp = fast;
                slow = slow->next;
                fast = fast->next;
            }
        }
    }

    cout << "Loop is not found !" << endl;
    return;
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

//  traversing through linked list
void print_linked_list(Node *head) // call by value
{
    cout << "Linked List : ";

    while (head != NULL)
    {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

int main()
{
    Node *head = NULL;
    Node *tail = NULL;
    InsertAtTail(head, tail, 11);
    InsertAtTail(head, tail, 21);
    Node *temp = tail;

    tail->next = tail; // loop is created
    floyd_algo(head);
    print_linked_list(head);
    floyd_algo(head);

    InsertAtTail(head, tail, 21);
    InsertAtTail(head, tail, 31);
    InsertAtTail(head, tail, 41);
    InsertAtTail(head, tail, 61);
    temp = tail;
    InsertAtTail(head, tail, 71);
    InsertAtTail(head, tail, 81);
    InsertAtTail(head, tail, 91);

    print_linked_list(head);

    // Solved by map
    tail->next = temp; // loop is created
    loop_found(head);
    print_linked_list(head);

    // Solved by floyd's cycle algo
    tail->next = temp; // loop is created
    floyd_algo(head);
    print_linked_list(head);

    floyd_algo(head);

    // For circular linked list
    cout << "Circular Linked List " << endl;
    tail->next = head;
    floyd_algo(head);
    print_linked_list(head);

    floyd_algo(head);
}

// Loop is found at : 21
// Linked List : 11 21
// Loop is not found !

// Linked List : 11 21 21 31 41 61 71 81 91
// Looped found at value 61
//  and removed !

// Linked List : 11 21 21 31 41 61 71 81 91
// Loop is found at : 61
// Linked List : 11 21 21 31 41 61 71 81 91
// Loop is not found !

// Circular Linked List
// Loop is found at : 11
// Linked List : 11 21 21 31 41 61 71 81 91
// Loop is not found !