// https://www.codingninjas.com/codestudio/problems/two-stacks_983634?leftPanelTab=0

#include <bits/stdc++.h>
using namespace std;
class Stack
{

public:
    int *arr;
    int top1;
    int top2;
    int size;
    int pointer;

    // constructor
    Stack(int size = 1000)
    {
        this->size = size;
        this->top1 = -1;
        this->top2 = size;
        this->arr = new int[size]; // arr = new int[size];
    }

    // push functions
    void push1(int element)
    {
        if (top2 - top1 > 1)
        {
            top1++;
            arr[top1] = element;
        }
        else
        {
            cout << "stack is overflow !" << endl;
        }
    }

    void push2(int element)
    {
        if (top2 - top1 > 1)
        {
            top2--;
            arr[top2] = element;
        }
        else
        {
            cout << "stack is overflow !" << endl;
        }
    }

    // Pop functions
    int pop1()
    {
        if (top1 >= 0)
        {
            int ans = arr[top1];
            top1--;
            return ans;
        }
        else
        {
            cout << "Stack is empty !" << endl;
            return -1;
        }
    }

    int pop2()
    {
        if (top2 < size)
        {
            int ans = arr[top2];
            top2++;
            return ans;
        }
        else
        {
            cout << "Stack is empty !" << endl;
            return -1;
        }
    }

    // top function
    int top1_ele()
    {
        if (top1 >= 0)
        {
            return arr[top1];
        }
        else
        {
            cout << "stack is empty !" << endl;
            return -1;
        }
    }
    int top2_ele()
    {
        if (top2 < size)
        {
            return arr[top2];
        }
        else
        {
            cout << "stack is empty !" << endl;
            return -1;
        }
    }
};

int main()
{
    Stack st(5);
    st.push1(1);
    st.push2(10);
    st.push1(2);
    st.push2(20);
    st.push1(3);
    st.push2(30);

    cout << "stack-1 top element : " << st.top1_ele() << endl;
    cout << "stack-2 top element : " << st.top2_ele() << endl;

    cout << "pop1 element : " << st.pop1() << endl;
    cout << "pop2 element : " << st.pop2() << endl;

    cout << "stack-1 top element : " << st.top1_ele() << endl;
    cout << "stack-2 top element : " << st.top2_ele() << endl;

    return 0;
}

// stack is overflow !

// stack-1 top element : 3
// stack-2 top element : 20

// pop1 element : 3
// pop2 element : 20

// stack-1 top element : 2
// stack-2 top element : 10