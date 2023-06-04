// https://codeforces.com/problemset/problem/1097/B

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;

    vector<int> vect;
    for (int i = 0; i < n; i++)
    {
        int temp;
        cin >> temp;
        vect.push_back(temp);
    }

    // Total number of possible combinations are 2^n.
    int max_bit_num = (1 << n);

    int flag = 0;

    for (int i = 0; i < max_bit_num; i++)
    {
        int temp = i;
        int sum = 0;
        int cnt = 0;

        while (cnt != n)
        {
            if ((temp & 1) == 0)
                sum = sum + vect[cnt];
            else
                sum = sum - vect[cnt];

            temp = temp >> 1;

            cnt++;
        }

        if (sum % 360 == 0)
        {
            cout << "YES" << endl;
            flag++;
            break;
        }
    }

    if (flag == 0)
        cout << "NO" << endl;
}