#include <bits/stdc++.h>
using namespace std;

void arr_me(const int arr[], int n)
{
    // Here value of const argument is not allowed to be get changed.

    // if we change the value of the const argument, it thwrows an error.

    // for(int i=0;i<n;i++)
    // {
    //     arr[i]++;
    // }

    for (int i = 0; i < n; i++)
    {
        cout << arr[i] + 1 << " ";
    }
}
int Test(const int num)
{
    // if we change the value of the const argument, it thwrows an error.
    // num = num + 10;

    cout << " The value of num: " << num << endl;
    return 0;
}
int main()
{
    // call function
    Test(5);
    int arr[] = {5, 6, 7, 8, 10};
    arr_me(arr, 5);
}

//  The value of num: 5
//  6 7 8 9 11