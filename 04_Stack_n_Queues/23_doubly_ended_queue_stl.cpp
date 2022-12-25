// doubly ended queue

#include <bits/stdc++.h>
using namespace std;

int main()
{
    deque<int> qt;

    if (qt.empty())
    {
        cout << "queue is empty !!" << endl;
    }

    qt.push_back(10);
    qt.push_front(11);
    qt.push_back(12);
    qt.push_back(13);
    qt.push_front(90);

    cout << "Front element : " << qt.front() << endl;
    cout << "Back element : " << qt.back() << endl;

    qt.pop_back();

    cout << "Front element : " << qt.front() << endl;
    cout << "Back element : " << qt.back() << endl;

    qt.pop_front();

    cout << "Front element : " << qt.front() << endl;
    cout << "Back element : " << qt.back() << endl;

    return 0;
}

// queue is empty !!

// Front element : 90
// Back element : 13

// Front element : 90
// Back element : 12

// Front element : 11
// Back element : 12