// https://www.codingninjas.com/codestudio/problems/calculate-xor_630606

#include <bits/stdc++.h>
using namespace std;

int calculateXOR(int n)
{
    // Write your code here.

    // There is pattern

    if (n % 4 == 0)
        return n;
    else if (n % 4 == 1)
        return 1;
    else if (n % 4 == 2)
        return n + 1;
    else
        return 0;
}
