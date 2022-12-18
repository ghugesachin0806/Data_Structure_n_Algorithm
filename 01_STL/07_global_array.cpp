#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int arr[N];
void fun()
{
    arr[0]=90;
}
int main()
{
    arr[0]=80;
    cout<<arr[0]<<endl;
    fun();
    cout<<arr[0]<<endl;
}
// 80
// 90