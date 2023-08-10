#include <bits/stdc++.h>
using namespace std;

class compare1
{
public:
    bool operator()(pair<int, int> a, pair<int, int> b) // for max_heap for pair_name.second
    {
        return a.second < b.second;
    }
};

class compare2
{
public:
    bool operator()(pair<int, int> a, pair<int, int> b) // for min_heap for pair_name.second
    {
        return a.second > b.second;
    }
};

int main()
{
    priority_queue<pair<int, int>, vector<pair<int, int>>, compare1> qt1;

    qt1.push({3, 4});
    qt1.push({4, 5});
    qt1.push({4, 3});
    qt1.push({3, 3});
    qt1.push({4, 4});
    qt1.push({7, 3});

    cout << "max_heap for pair_name.second" << endl;

    while (!qt1.empty())
    {
        cout << qt1.top().first << " " << qt1.top().second << endl;
        qt1.pop();
    }

    cout << "--------------" << endl;

    //////////////////////////////////////////////////////////////////////////

    priority_queue<pair<int, int>, vector<pair<int, int>>, compare2> qt2;

    qt2.push({3, 4});
    qt2.push({4, 3});
    qt2.push({3, 3});
    qt2.push({4, 5});
    qt2.push({4, 4});
    qt2.push({7, 3});

    cout << "min_heap for pair_name.second" << endl;

    while (!qt2.empty())
    {
        cout << qt2.top().first << " " << qt2.top().second << endl;
        qt2.pop();
    }

    cout << "--------------" << endl;
}

// max_heap for pair_name.second
// 4 5
// 3 4
// 4 4
// 4 3
// 3 3
// 7 3
// --------------
// min_heap for pair_name.second
// 4 3
// 3 3
// 7 3
// 4 4
// 3 4
// 4 5
// --------------