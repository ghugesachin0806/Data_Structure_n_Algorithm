#include <bits/stdc++.h>
using namespace std;

int main()
{
    // min heap
    priority_queue<int, vector<int>, greater<int>> min_heap;

    // Insertion
    min_heap.push(66);
    min_heap.push(11);
    min_heap.push(33);
    min_heap.push(101);
    min_heap.push(9);
    min_heap.push(7);
    min_heap.push(13);
    min_heap.push(80);

    // min element
    cout << min_heap.top() << endl;

    // pop the min element
    min_heap.pop();

    // min element
    cout << min_heap.top() << endl;

    // empty function
    if (min_heap.empty())
        cout << "empty priority queue :" << endl;
    else
        cout << "Non-empty priority queue :" << endl;

    return 0;
}

// 7
// 9
// Non-empty priority queue :