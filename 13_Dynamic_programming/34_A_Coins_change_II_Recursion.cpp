// https://leetcode.com/problems/coin-change-ii/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int solve(int index, int amount, vector<int> &coins)
    {
        if (index < 0)
        {
            if (amount == 0)
                return 1;
            else
                return 0;
        }


        // Include current index
        int temp1 = 0;
        if (amount >= coins[index])
            temp1 = solve(index, amount - coins[index], coins);

        // Exclude current index
        int temp2 = solve(index - 1, amount, coins);

        return temp1 + temp2;
    }
    int change(int amount, vector<int> &coins)
    {
        int curr_index = coins.size() - 1;

        return solve(curr_index, amount, coins);
    }
};