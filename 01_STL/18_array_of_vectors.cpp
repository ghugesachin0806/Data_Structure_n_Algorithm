#include <bits/stdc++.h>
using namespace std;

void print_vect(vector<int> m)
{
    cout << "Size of vector - " << m.size() << endl;
    for (int i = 0; i < m.size(); i++)
    {
        cout << m[i] << " ";
    }
    cout << endl;
}

int main()
{
    int N;
    cin >> N;
    vector<int> vect[N]; // Here array of vectors is defined.
    // Above total 'N' vectors are declared with dynamic size.
    for (int i = 0; i < N; i++)
    {
        int n;
        cin >> n;
        for (int j = 0; j < n; j++)
        {
            int x;
            cin >> x;
            vect[i].push_back(x);
        }
    }

    ///////////////////////////////////////////////////////////////////////////////////////////
    cout << "One way of printing vectors" << endl;
    for (int i = 0; i < N; i++) // one way of printing vectors using function
    {
        print_vect(vect[i]);
    }
    //////////////////////////////////////////////////////////////////////////////////////////
    vector<int> vect2[N];
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            int x;
            cin >> x;
            vect2[i].push_back(x);
        }
    }
    cout << "Second way of printing vectors" << endl;
    for (int i = 0; i < N; i++) // second way of printing vectors directly
    {
        for (int j = 0; j < N; j++)
        {
            cout << vect2[i][j] << " ";
        }
        cout << endl;
    }
    ///////////////////////////////////////////////////////////////////////////////////////////////////
}
// 5
// 3
// 1 2 3
// 4
// 3 6 9 8
// 5
// 22 33 66 89 75
// 3
// 78 56 91
// 7
// 1 2 3 4 5 6 7
// One way of printing vectors
// Size of vector - 3
// 1 2 3
// Size of vector - 4
// 3 6 9 8
// Size of vector - 5
// 22 33 66 89 75
// Size of vector - 3
// 78 56 91
// Size of vector - 7
// 1 2 3 4 5 6 7

// 1
// 2
// 3
// 4
// 5
// 6
// 7
// 8
// 9
// 10
// 11
// 12
// 23
// 45
// 56
// 78
// 89
// 45
// 19
// 61
// 58
// 73
// 36
// 98
// 52
// Second way of printing vectors
// 1 2 3 4 5
// 6 7 8 9 10
// 11 12 23 45 56
// 78 89 45 19 61
// 58 73 36 98 52