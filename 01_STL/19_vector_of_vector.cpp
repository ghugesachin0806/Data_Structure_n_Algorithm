#include <bits/stdc++.h>
using namespace std;

int main()
{
    /////////////////////////////////////////////////////////////////////////////////////////
    // One way of entering elements in vector of vector(2d vector) , by creating temp vector
    vector<vector<int>> vect;
    int n;
    cin >> n; // Here total vectors are defined means rows in vector
    for (int i = 0; i < n; i++)
    {
        vector<int> temp; // In this method using temp vector , we are copying vector in vector vect
        int x;            // we can not use directly vect[i].pust_back(x) here because the rows are not created already
        cin >> x;         // Here total elements in temp vector are defined
        for (int j = 0; j < x; j++)
        {
            temp.push_back(j * j);
        }
        vect.push_back(temp); // Here temp vector get placed in 2d vector vect here using push_back function
    }
    for (int i = 0; i < n; i++) // here vect vector is getting printed
    {
        for (int j = 0; j < vect[i].size(); j++)
        {
            cout << vect[i][j] << " ";
        }
        cout << endl;
    }
    ////////////////////////////////////////////////////////////////////////////////////////////////////
    // another way of entering elements in vector of vector (2d vector) , by pushing blank vector to vect2 vector

    vector<vector<int>> vect2;
    int m;
    cin >> m; // rows are defined here, means total vectors are defined here
    for (int i = 0; i < m; i++)
    {
        vect2.push_back(vector<int>()); // here by pushing blank vector , we are creating new row to enter other vector into it.
        int z;
        cin >> z; // column for each row is defined here
        for (int j = 0; j < z; j++)
        {
            int l = j * j;
            vect2[i].push_back(l);
        }
    }
    for (int i = 0; i < m; i++) // here vect2 is getting printed
    {
        for (int j = 0; j < vect2[i].size(); j++)
        {
            cout << vect2[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}

// -> 5
// -> 6 9 3 5 4
// 0 1 4 9 16 25
// 0 1 4 9 16 25 36 49 64
// 0 1 4
// 0 1 4 9 16
// 0 1 4 9
// -> 5
// -> 6 9 3 5 4
// 0 1 4 9 16 25
// 0 1 4 9 16 25 36 49 64
// 0 1 4
// 0 1 4 9 16
// 0 1 4 9