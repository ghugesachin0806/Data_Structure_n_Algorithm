// Circular Queue

#include <bits/stdc++.h>
using namespace std;

class Queue
{
private:
    int *arr;
    int front;
    int rear;
    int total_size;
    int cnt;

public:
    // constructor
    Queue(int size = 100)
    {
        this->total_size = size;
        this->cnt = 0;
        arr = new int[total_size];
        this->front = 0;
        this->rear = 0;
    }

    // push operation
    void push(int element)
    {
        if (cnt == total_size)
        {
            cout << "Queue is Full !!" << endl;
            return;
        }

        arr[rear] = element;
        rear++;
        cnt++;

        if (rear == total_size)
        {
            rear = 0;
        }
    }
    // pop operation
    void pop()
    {
        if (cnt == 0)
        {
            cout << "Queue is Empty !!" << endl;
            return;
        }
        front++;
        cnt--;

        if (front == total_size)
        {
            front = 0;
        }
    }

    // front element
    int front_ele()
    {
        if (cnt == 0)
        {
            cout << "Queue is empty !!" << endl;
            return -1;
        }
        else
            return arr[front];
    }

    // back element
    int back_ele()
    {
        if (cnt == 0)
        {
            cout << "Queue is empty !!" << endl;
            return -1;
        }
        else
        {
            if (rear == 0)
                return arr[total_size - 1];

            else
                return arr[rear - 1];
        }
    }

    // size of queue
    int size()
    {
        return cnt;
    }

    // empty function or not
    bool empty()
    {
        if (cnt == 0)
            return true;
        else
            return false;
    }
};

int main()
{
    Queue qt(5);

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

    cout << "size of queue : " << qt.size() << endl;
    cout << "front of queue : " << qt.front_ele() << endl;
    cout << "back of queue : " << qt.back_ele() << endl;

    qt.push(70);
    qt.push(80);
    qt.push(90);
    qt.push(10);

    cout << "size of queue : " << qt.size() << endl;
    cout << "front of queue : " << qt.front_ele() << endl;
    cout << "back of queue : " << qt.back_ele() << endl;

    if (!qt.empty())
    {
        cout << "empty is not queue" << endl;
    }

    return 0;
}

// empty queue

// Queue is Full !!

// size of queue : 5
// front of queue : 10
// back of queue : 50

// size of queue : 3
// front of queue : 30
// back of queue : 50

// Queue is Full !!
// Queue is Full !!

// size of queue : 5
// front of queue : 30
// back of queue : 80

// empty is not queue