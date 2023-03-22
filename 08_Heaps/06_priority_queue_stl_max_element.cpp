#include <bits/stdc++.h>
using namespace std;

int main()
{
    // Max heap
    priority_queue<int> max_heap;

    // Insertion
    max_heap.push(66);
    max_heap.push(11);
    max_heap.push(33);
    max_heap.push(101);
    max_heap.push(9);
    max_heap.push(7);
    max_heap.push(13);
    max_heap.push(80);

    // max element
    cout << max_heap.top() << endl;

    // pop the max element
    max_heap.pop();

    // max element
    cout << max_heap.top() << endl;

    // empty function
    if (max_heap.empty())
        cout << "empty priority queue :" << endl;
    else
        cout << "Non-empty priority queue :" << endl;

    return 0;
}

// 101
// 80
// Non-empty priority queue :