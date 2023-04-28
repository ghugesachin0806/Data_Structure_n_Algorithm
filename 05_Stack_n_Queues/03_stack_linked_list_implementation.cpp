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

class Stack
{
private:
    Node *top;
    int cnt;

public:
    // constructor
    Stack()
    {
        this->top = NULL;
        this->cnt = 0;
    }

    // Push function
    void push(int data)
    {
        // Create new node temp and allocate memory in heap
        Node *temp = new Node(data);

        // Check if stack (heap) is full.
        // Then inserting an element would
        // lead to stack overflow

        if (!temp) // means if(! NULL)
        {
            cout << "stack over flow" << endl;

            exit(1); // Abnormal termination of the program -> exit(1)
                     // Succesful termination of the program -> exit(0)
        }

        temp->next = top;
        top = temp;
        this->cnt++;
    }

    // pop function
    void pop()
    {
        if (top == NULL)
        {
            cout << "Stack is empty !" << endl;
            exit(1);
        }

        Node *temp = top;
        top = top->next;
        temp->next = NULL;
        delete temp;
        cnt--;
    }

    // empty function
    bool empty()
    {
        return top == NULL;
    }

    // top element
    int top_ele()
    {
        if (top == NULL)
        {
            cout << "Stack is empty !" << endl;
            return -1;
        }

        return top->data;
    }

    // size function
    int size()
    {
        return cnt;
    }

    // display all the elements
    void display()
    {
        if (top != NULL)
        {
            Node *temp;
            temp = top;
            cout << "stack elements are : ";
            while (temp != NULL)
            {
                cout << temp->data << " ";
                temp = temp->next;
            }
            cout << endl;
        }
        else
        {
            cout << "stack is empty !" << endl;
        }
    }

    // stack deletion
    void delete_stack()
    {
        delete top;
    }
};

int main()
{
    Stack st;

    st.push(8);
    st.push(18);
    st.push(78);

    cout << "top element : " << st.top_ele() << endl;
    cout << "size of stack : " << st.size() << endl;

    st.pop();

    cout << "top element : " << st.top_ele() << endl;
    cout << "size of stack : " << st.size() << endl;

    // display all the elements from stack
    st.display();

    // memory free
    st.delete_stack();

    return 0;
}

// top element : 78
// size of stack : 3

// Memory is free for 78

// top element : 18
// size of stack : 2

// stack elements are : 18 8 

// Memory is free for 8
// Memory is free for 18