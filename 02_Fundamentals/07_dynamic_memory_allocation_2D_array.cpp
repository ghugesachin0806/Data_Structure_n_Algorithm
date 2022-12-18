#include <bits/stdc++.h>
using namespace std;

int main()
{
    int row, col;
    cin >> row >> col;

    // Creating 2D array by Dynamic memory allocation

    int **arr = new int *[row]; // Here array of pointer is created

    for (int i = 0; i < row; i++)
    {
        arr[i] = new int[col];  // Here for every row pointer , new block of code is assigned from Heap
    }

    /////////////////////////////////////////////////////////

    // taking input

    for(int i=0;i<row;i++)
    {
        for(int j=0;j<col;j++)
        {
            cin>>arr[i][j];
        }
    }

    // taking output

    for(int i=0;i<row;i++)
    {
        for(int j=0;j<col;j++)
        {
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }

    // releasing memory of heap

    for(int i=0;i<row;i++)
    {
        delete []arr[i];
    }

    delete []arr;

}

// -> 3 4
// -> 1 2 3 4 5 6 7 8 9 10 11 12
// 1 2 3 4 
// 5 6 7 8    
// 9 10 11 12 