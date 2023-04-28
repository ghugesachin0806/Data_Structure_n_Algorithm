// Recursive relation of fibonnacci series -> f(n)=f(n-1)+f(n-2)
#include <bits/stdc++.h>
using namespace std;

int fibo(int n)
{
    // Base case
    if (n == 1)
        return 1;
    if (n == 0)
        return 0;

    // recursive relation
    return (fibo(n - 1) + fibo(n - 2));
}

int main()
{
    int t;
    cin >> t;
    cout << endl;
    int ans;

    ans = fibo(t-1);
    cout << ans << endl;
}
//-> 10

// 34