// https://www.youtube.com/redirect?event=video_description&redir_token=QUFFLUhqbHhWeXYzTFItWWdqemtsY09nSjRmdnBNN19BQXxBQ3Jtc0tsQk9UMENPVUFKaDQ5R3BrX0NzdGVKbG1OVVN3blFYenUyZWJmcFlMNlQ2aGUtSzVxNVdqcVBPMDRCbUtnMW9DSmJETHY5QmhIamlZclhFdGdlM0MxTERtaF9vWXJueFAyUGJVdWR1MGZtQmM2emIyQQ&q=https%3A%2F%2Fpractice.geeksforgeeks.org%2Fproblems%2Fcheck-if-linked-list-is-pallindrome%2F1%2F&v=aD7mBVnKFEU

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
Node *reverse(Node *head)
{
    Node *curr = head;
    Node *prev = NULL;
    Node *temp = NULL;

    while (curr != NULL)
    {
        temp = curr->next;
        curr->next = prev;
        prev = curr;
        curr = temp;
    }
    return prev;
}

void palindrome_ll(Node *head)
{
    if (head == NULL || head->next == NULL)
    {
        cout << "Linked List in palindrome !!" << endl;
        return;
    }
    Node *curr = head;
    Node *tail = head;

    int cnt = 0;
    while (tail != NULL)
    {
        cnt++;
        tail = tail->next;
    }

    cnt = cnt / 2;

    tail = head;

    int k = 1;

    while (k < cnt)
    {
        tail = tail->next;
        k++;
    }

    tail->next = reverse(tail->next);
    tail = tail->next;

    Node *fix = tail;

    while (curr != fix)
    {
        if (curr->data != tail->data)
        {
            cout << "Linked List is not in palindrome !" << endl;
            return;
        }
        curr = curr->next;
        tail = tail->next;
    }

    cout << "Linked List in palindrome !!" << endl;
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
    InsertAtTail(head, 44);
    InsertAtTail(head, 33);
    InsertAtTail(head, 22);
    InsertAtTail(head, 11);

    print_linked_list(head);

    palindrome_ll(head);

    print_linked_list(head);
}

// Linked List : 11 22 33 44 55 44 33 22 11
// Head : 11

// Linked List in palindrome !!

// Linked List : 11 22 33 44 11 22 33 44 55
// Head : 11