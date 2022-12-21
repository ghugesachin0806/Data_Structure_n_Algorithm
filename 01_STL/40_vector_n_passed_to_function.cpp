#include <bits/stdc++.h>
using namespace std;

void vector_fun(vector<int> vect) // vector always passed by value by default , there is copy is created
{
    cout << "vector in fun() : ";
    for (int i = 0; i < vect.size(); i++)
    {
        vect[i]++;
        cout << vect[i] << " ";
    }
    cout << endl;
}

void arr_fun(int arr[], int n) // array always passed by reference by default , whole array is passed by reference
{
    cout << "array in fun() : ";
    for (int i = 0; i < n; i++)
    {
        arr[i]++;
        cout << arr[i] << " ";
    }
    cout << endl;
}

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

    vector_fun(vect); // vector always passed by value by default

    cout << "vector in main fun() : ";
    for (int i = 0; i < n; i++)
    {
        cout << vect[i] << " ";
    }
    cout << endl;
    //////////////////////////////////////////////////////////
    int t = 5;
    int arr[5] = {1, 2, 3, 4, 5};

    arr_fun(arr, t); // array always passed by reference by default

    cout << "array in main fun() : ";
    for (int i = 0; i < t; i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}

// -> 5
// -> 1 2 3 4 5
// vector in fun() : 2 3 4 5 6
// vector in main fun() : 1 2 3 4 5

// array in fun() : 2 3 4 5 6
// array in main fun() : 2 3 4 5 6