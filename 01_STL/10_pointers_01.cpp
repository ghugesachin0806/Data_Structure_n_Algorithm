#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n=10;
    int arr[n];// here 'arr' -->address of the first element of array
    for(int i=0;i<n;i++)
    {
        arr[i]=i+1;
    }
    cout<<"Address of first element of array... "<<arr<<endl;
    cout<<"Address of first element of array... "<<&arr[0]<<endl; 
    cout<<"Address of second element of array... "<<arr+1<<endl;
    cout<<"second element of array... "<<*(arr+1)<<endl;
    cout<<"second element of array... "<<arr[1]<<endl;
    return 0;
}

// Address of first element of array... 0x85e2dffd20
// Address of first element of array... 0x85e2dffd20
// Address of second element of array... 0x85e2dffd24
// second element of array... 2
// second element of array... 2