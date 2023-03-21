#include <bits/stdc++.h>
using namespace std;

int Binary_Search(int arr[], int key, int start, int end)
{
    while (start <= end)
    {
        int mid = start + (end - start) / 2; // to avoid overflow of larger numbers

        if (arr[mid] == key)
            return mid;

        if (arr[mid] > key)
            end = mid - 1;

        else
            start = mid + 1;
    }

    return -1;
}

int main()
{

    int odd[] = {11, 22, 33, 44, 55, 66, 77};
    int even[] = {11, 22, 33, 44, 55, 66, 77, 88};

    int odd_in, even_in;
    cout << "Enter value for odd array : ";
    cin >> odd_in;
    cout << "Enter value for even array : ";
    cin >> even_in;

    int odd_val = Binary_Search(odd, odd_in, 0, 6);
    int even_val = Binary_Search(even, even_in, 0, 7);

    cout << "odd_val exists at position : " << odd_val << endl;
    cout << "even_val exists at position : " << even_val << endl;

    return 0;
}

// --> Enter value for odd array : 77
// --> Enter value for even array : 88

// odd_val exists at position : 6
// even_val exists at position : 7