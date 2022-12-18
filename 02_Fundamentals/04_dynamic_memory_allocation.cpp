#include <bits/stdc++.h>
using namespace std;

void answ(int arr1[], int n)
{
    for (int i = 0; i < n; i++)
    {
        arr1[i]++;
    }
}

int sum(int *arr2, int m)
{
    int sum = 0;
    for (int i = 0; i < m; i++)
    {
        sum += arr2[i];
    }
    return sum;
}

int main()
{
    char *ch = new char; // creating memory in heap
    cin >> ch;
    cout << "character is " << ch << endl;

    delete ch;  // It will release/free the memory allocation from heap

    //////////////////////////////////////////////////////////////////////

    int n;
    cin >> n;

    int *arr = new int[n]; // created array memory in heap
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    cout << "before " << sum(arr, n) << endl;

    answ(arr, n);

    cout << "after " << sum(arr, n) << endl;

    for (int i = 0; i < n; i++)
    {
        cout<<arr[i]<<" ";
    }

    delete []arr; // It will release/free the memory allocation from heap to array
}

// -> 5
// character is 5
// -> 10
// -> 1 2 3 4 5 6 7 8 9 10
// before 55
// after 65
// 2 3 4 5 6 7 8 9 10 11