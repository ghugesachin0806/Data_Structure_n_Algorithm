// stack implementation using array

#include <bits/stdc++.h>
using namespace std;

class Stack
{

public:
    int *arr;
    int size;
    int pointer;

    // constructor
    Stack(int size = 1000)
    {
        this->size = size;
        this->arr = new int[size]; // arr = new int[size];
        this->pointer = -1;
    }

    // push fuction
    void push(int element)
    {
        if (size - pointer > 1)
        {
            pointer++;
            arr[pointer] = element;
        }
        else
        {
            cout << "stack is overflow !" << endl;
        }
    }

    // pop function
    void pop()
    {
        if (this->pointer == -1)
        {
            cout << "stack is empty !" << endl;
        }
        else
        {
            pointer--;
        }
    }

    // top function
    int top()
    {
        if (this->pointer >= 0)
        {
            return arr[pointer];
        }
        else
        {
            cout << "Stack is empty !" << endl;
            return -1;
        }
    }

    // size function
    int size_of_stack()
    {
        if (pointer == -1)
        {
            return 0;
        }
        else
        {
            return pointer + 1;
        }
    }

    // isempty function
    bool empty()
    {
        if (pointer == -1)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
};

int main()
{
    // Creation of stack
    Stack st(3);

    // Push operation
    st.push(2);
    st.push(22);
    st.push(17);
    st.push(27);
    st.push(37);
    st.push(47);

    // top element in stack
    cout << "top element : " << st.top() << endl;
    cout << "size of stack : " << st.size_of_stack() << endl;

    // pop the element
    st.pop();
    cout << "top element : " << st.top() << endl;
    cout << "size of stack : " << st.size_of_stack() << endl;

    // stack is empty or not
    if (st.empty())
    {
        cout << "stack is empty" << endl;
    }
    else
    {
        cout << "stack is not empty" << endl;
    }

    // pop the element
    st.pop();
    cout << "top element : " << st.top() << endl;
    cout << "size of stack : " << st.size_of_stack() << endl;

    st.pop();
    cout << "top element : " << st.top() << endl;
    cout << "size of stack : " << st.size_of_stack() << endl;

    // stack is empty or not
    if (st.empty())
    {
        cout << "stack is empty" << endl;
    }
    else
    {
        cout << "stack is not empty" << endl;
    }
    return 0;
}

// stack is overflow !
// stack is overflow !
// stack is overflow !

// top element : 17
// size of stack : 3

// top element : 22
// size of stack : 2
// stack is not empty

// top element : 2
// size of stack : 1

// top element : Stack is empty !
// -1
// size of stack : 0
// stack is empty