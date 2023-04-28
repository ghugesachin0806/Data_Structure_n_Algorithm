// https://www.codingninjas.com/codestudio/problems/n-stacks-in-an-array_1164271?topList=love-babbar-dsa-sheet-problems&leftPanelTab=0

#include <bits/stdc++.h>
using namespace std;

class Stack
{
private:
    int *arr;
    int *next;
    int *top;
    int freespot;
    int no_array;
    int stack_size;

public:
    Stack(int S, int N)
    {
        stack_size = S;
        no_array = N;
        arr = new int[S];
        next = new int[S];
        top = new int[N];

        // top initialization
        for (int i = 0; i < N; i++)
        {
            top[i] = -1;
        }

        // next array
        for (int i = 0; i < S; i++)
        {
            next[i] = i + 1;
        }

        next[S - 1] = -1;

        // freespot
        freespot = 0;
    }

    // push operation

    void push(int stack_no, int element)
    {
        // is stack overflowed
        if (freespot == -1)
        {
            cout << "stack overflowed !" << endl;
            return;
        }

        // find index for freespot available
        int index = freespot;

        // update freespot
        freespot = next[freespot];

        // insert element in array
        arr[index] = element;

        // update next array
        next[index] = top[stack_no - 1];

        // update top
        top[stack_no - 1] = index;
    }

    void pop(int stack_no)
    {

        // is given stack empty or not ?
        if (stack_no == -1)
        {
            cout << "stack is empty !" << endl;
            return;
        }

        // store the element of top in index
        int index = top[stack_no - 1];

        // update the top
        top[stack_no - 1] = next[index];

        // freed space pointing to freespot variable
        next[index] = freespot;

        // now freespot updated to freed space
        freespot = index;
    }

    int top_ele(int stack_no)
    {
        if (top[stack_no - 1] == -1)
            return -1;

        return arr[top[stack_no - 1]];
    }

    void print_arr()
    {
        for (int i = 0; i < stack_size; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
        for (int i = 0; i < stack_size; i++)
        {
            cout << next[i] << " ";
        }
        cout << endl;
    }
};

int main()
{
    Stack st(6, 3);
    st.push(1, 3);
    st.push(3, 4);
    st.push(2, 8);
    st.push(3, 9);
    st.push(1, 10);
    st.push(2, 11);
    st.push(2, 55);

    cout << st.top_ele(1) << " " << st.top_ele(2) << " " << st.top_ele(3) << endl;

    st.pop(1);
    st.pop(2);
    st.pop(3);

    cout << st.top_ele(1) << " " << st.top_ele(2) << " " << st.top_ele(3) << endl;

    st.pop(1);
    st.pop(2);
    st.pop(3);

    cout << st.top_ele(1) << " " << st.top_ele(2) << " " << st.top_ele(3) << endl;

    st.push(1, 3);
    st.push(3, 4);
    st.push(1, 8);
    st.push(3, 9);
    st.push(3, 10);
    st.push(1, 11);
    st.push(3, 55);

    cout << st.top_ele(1) << " " << st.top_ele(2) << " " << st.top_ele(3) << endl;

    st.pop(3);
    st.pop(1);

    cout << st.top_ele(1) << " " << st.top_ele(2) << " " << st.top_ele(3) << endl;

    st.pop(3);
    st.pop(1);

    cout << st.top_ele(1) << " " << st.top_ele(2) << " " << st.top_ele(3) << endl;

    return 0;
}

// stack overflowed !
// 10 11 9
// 3 8 4
// -1 -1 -1

// stack overflowed !
// 11 -1 10
// 8 -1 9
// 3 -1 4