#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    // constructor
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }

    // destructor
    ~Node()
    {
        int value = this->data;
        if (this->next != NULL)
        {
            delete this->next;
            this->next = NULL;
        }
        cout << "Memory is free for " << value << endl;
    }
};

class Queue
{
private:
    Node *front;
    Node *back;
    int cnt;

public:
    // constructor
    Queue()
    {
        front = NULL;
        back = NULL;
        this->cnt = 0;
    }

    // push operation
    void push(int element)
    {
        Node *temp = new Node(element);

        if (front == NULL)
        {
            front = temp;
            back = temp;
            cnt++;
            return;
        }
        back->next = temp;
        back = temp;
        cnt++;
    }

    // pop operation
    void pop()
    {
        if (front == NULL)
        {
            cout << "Queue is empty !!" << endl;
            return;
        }
        Node *temp = front;
        front = front->next;
        temp->next = NULL;
        delete temp;
        cnt--;
    }

    // front element
    int front_ele()
    {
        if (cnt == 0)
        {
            cout << "Queue is empty !!" << endl;
            return -1;
        }

        return front->data;
    }

    // back element
    int back_ele()
    {
        if (cnt == 0)
        {
            cout << "Queue is empty !!" << endl;
            return -1;
        }

        return back->data;
    }

    // size of linked list
    int size()
    {
        return cnt;
    }

    // empty or not
    bool empty()
    {
        if (front == NULL)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    void delete_full()
    {
        delete front;
    }
};

int main()
{

    Queue qt;

    if (qt.empty())
    {
        cout << "empty queue" << endl;
    }

    qt.push(10);
    qt.push(20);
    qt.push(30);
    qt.push(40);
    qt.push(50);
    qt.push(60);

    cout << "size of queue : " << qt.size() << endl;
    cout << "front of queue : " << qt.front_ele() << endl;
    cout << "back of queue : " << qt.back_ele() << endl;

    qt.pop();
    qt.pop();
    qt.pop();
    qt.pop();
    qt.pop();
    qt.pop();
    qt.pop();

    cout << "size of queue : " << qt.size() << endl;
    cout << "front of queue : " << qt.front_ele() << endl;
    cout << "back of queue : " << qt.back_ele() << endl;

    qt.push(70);

    cout << "size of queue : " << qt.size() << endl;
    cout << "front of queue : " << qt.front_ele() << endl;
    cout << "back of queue : " << qt.back_ele() << endl;

    qt.push(10);
    qt.push(20);
    qt.push(30);
    qt.push(40);
    qt.push(50);
    qt.push(60);

    cout << "size of queue : " << qt.size() << endl;
    cout << "front of queue : " << qt.front_ele() << endl;
    cout << "back of queue : " << qt.back_ele() << endl;

    if (!qt.empty())
    {
        cout << "empty is not queue" << endl;
    }

    qt.delete_full();

    return 0;
}

// empty queue

// size of queue : 6
// front of queue : 10
// back of queue : 60

// Memory is free for 10
// Memory is free for 20
// Memory is free for 30
// Memory is free for 40
// Memory is free for 50
// Memory is free for 60
// Queue is empty !!

// size of queue : 0
// front of queue : Queue is empty !!
// -1
// back of queue : Queue is empty !!
// -1

// size of queue : 1
// front of queue : 70
// back of queue : 70

// size of queue : 7
// front of queue : 70
// back of queue : 60

// empty is not queue

// Memory is free for 60
// Memory is free for 50
// Memory is free for 40
// Memory is free for 30
// Memory is free for 20
// Memory is free for 10
// Memory is free for 70