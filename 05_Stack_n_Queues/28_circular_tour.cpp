// https://practice.geeksforgeeks.org/problems/circular-tour-1587115620/1

#include <bits/stdc++.h>
using namespace std;

struct combined_data
{
    int petrol;
    int distance;
};

int solve(combined_data arr[], int n)
{
    int balance = 0;
    int deficit = 0;

    int start = 0;

    for (int i = 0; i < n; i++)
    {
        balance = arr[i].petrol + balance - arr[i].distance;
        if (balance < 0)
        {
            deficit = deficit + balance;
            start = i + 1;
            balance = 0;
        }
    }
    if (deficit + balance >= 0)
        return start;

    else
        return -1;
}

int main()
{
    int n;
    cin >> n;
    combined_data arr[n];
    for (int i = 0; i < n; i++)
    {
        int pl;
        int nt;
        cin >> pl >> nt;

        arr[i].petrol = pl;
        arr[i].distance = nt;
    }

    int output = solve(arr, n);

    cout << "starting point : " << output << endl;
    return 0;
}

// 4
// 4 6 6 5 7 3 4 5
// starting point : 1

// 4
// 55 52 33 100 77 61 40 69
// starting point : -1