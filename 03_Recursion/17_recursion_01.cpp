// https://www.codingninjas.com/codestudio/problems/count-ways-to-reach-nth-stairs_798650?utm_source=youtube&utm_medium=affiliate&utm_campaign=love_babbar_10

#include <bits/stdc++.h>
using namespace std;

int stairs(int n)
{
    // Base case
    if (n < 0)
    {
        return 0;
    }
    if (n == 0)
    {
        return 1;
    }

    // Recursive relation

    return stairs(n - 1) + stairs(n - 2);
}

int main()
{
    int t;
    cin >> t;

    cout << endl;

    cout << stairs(t) << endl;
}

// -> 5

// 8