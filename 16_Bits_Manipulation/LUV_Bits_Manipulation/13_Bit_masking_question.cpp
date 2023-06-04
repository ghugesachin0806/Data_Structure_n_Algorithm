// https://codeforces.com/blog/entry/73558

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n; // No. of worker_availabily
    cin >> n;

    vector<int> worker_availabily(n, 0);

    for (int i = 0; i < n; i++)
    {
        int days;
        cin >> days; // how manys days available

        for (int j = 0; j < days; j++)
        {
            int curr_day;
            cin >> curr_day; // available day

            worker_availabily[i] = (worker_availabily[i] | (1 << curr_day));
        }
    }

    int worker1 = 0;
    int worker2 = 0;

    int max_days = INT_MIN;

    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            int temp = __builtin_popcount(worker_availabily[i] | worker_availabily[j]);
            if (max_days < temp)
            {
                max_days = temp;
                worker1 = i + 1;
                worker2 = j + 1;
            }
        }
    }

    cout << "max_days : " << max_days << endl;
    cout << "Worker_1 : " << worker1 << endl;
    cout << "Worker_2 : " << worker2 << endl;
}

// --> Input
// 5
// 3
// 1 2 3
// 4
// 21 23 28 3
// 8
// 1 2 3 4 11 23 25 7
// 5
// 2 4 8 6 10
// 7
// 3 4 5 6 7 8 25

//--> Output
// max_days : 11
// Worker_1 : 3
// Worker_2 : 4