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

        if (rear == total_size && front != 0)
        {
            int temp = 0;
            while (front != rear)
            {
                arr[temp] = arr[front];
                temp++;
                front++;
            }
            rear = temp;
            front = 0;
        }

        arr[rear] = element;
        rear++;
        cnt++;
    }
    // pop operation
    void pop()
    {
        if (front == rear)
        {
            cout << "Queue is Empty !!" << endl;
            return;
        }

        front++;

        if (front == rear)
        {
            front = 0;
            rear = 0;
        }
        cnt--;
    }
    // front element
    int front_ele()
    {
        if (front == rear)
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
        if (front == rear)
        {
            cout << "Queue is empty !!" << endl;
            return -1;
        }
        else
            return arr[rear - 1];
    }

    // size of queue
    int size()
    {
        return cnt;
    }

    bool empty()
    {
        if (front == rear)
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

// size of queue : 4
// front of queue : 30
// back of queue : 70

// empty is not queue