// https://www.geeksforgeeks.org/efficiently-implement-k-queues-single-array/

#include <bits/stdc++.h>
using namespace std;

class Queue
{
private:
    int *arr;
    int *next;
    int *front;
    int *back;
    int freespot;

public:
    // constructor
    Queue(int parts, int size = 100)
    {
        arr = new int[size];
        next = new int[size];
        front = new int[parts];
        back = new int[parts];

        for (int i = 0; i < parts; i++)
        {
            front[i] = -1;
            back[i] = -1;
        }

        for (int i = 0; i < size; i++)
        {
            next[i] = i + 1;
        }

        next[size - 1] = -1;

        freespot = 0;
    }

    // push operation
    void push(int qn, int element)
    {
        if (freespot == -1)
        {
            cout << "Queue is full !!" << endl;
            return;
        }

        int index = freespot;
        freespot = next[freespot];

        // first element of queue
        if (front[qn - 1] == -1)
        {
            front[qn - 1] = index;
        }
        // next elements of queue
        else
        {
            next[back[qn - 1]] = index;
        }

        next[index] = -1;
        back[qn - 1] = index;
        arr[index] = element;
    }
    // pop operation
    void pop(int qn)
    {
        if (front[qn - 1] == -1)
        {
            cout << "Queue is empty !!" << endl;
            return;
        }

        int index = front[qn - 1];

        front[qn - 1] = next[front[qn - 1]];

        next[index] = freespot;
        freespot = index;

        arr[index] = 0;
    }
    // front element
    int front_ele(int qn)
    {
        if (front[qn - 1] == -1)
        {
            return -1;
        }
        else
        {
            return arr[front[qn - 1]];
        }
    }

    // back element
    int back_ele(int qn)
    {
        if (front[qn - 1] == -1)
        {
            return -1;
        }
        else
        {
            return arr[back[qn - 1]];
        }
    }

    void print_me(int n)
    {
        cout << "array : ";
        for (int i = 0; i < n; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;

        cout << "next : ";
        for (int i = 0; i < n; i++)
        {
            cout << next[i] << " ";
        }
        cout << endl;
    }
};

int main()
{

    Queue qt(3, 6);
    qt.push(1, 30);
    qt.push(2, 40);
    qt.push(3, 50);
    qt.push(1, 60);
    qt.push(2, 70);
    qt.push(3, 80);
    qt.push(1, 90);

    qt.print_me(6);

    qt.pop(1);
    qt.pop(2);
    qt.pop(3);

    qt.print_me(6);

    qt.pop(1);
    qt.pop(2);
    qt.pop(3);

    qt.print_me(6);

    return 0;
}

// Queue is full !!

// array : 30 40 50 60 70 80
// next : 3 4 5 -1 -1 -1

// array : 0 0 0 60 70 80
// next : -1 0 1 -1 -1 -1

// array : 0 0 0 0 0 0
// next : -1 0 1 2 3 4