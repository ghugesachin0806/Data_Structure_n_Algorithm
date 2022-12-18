#include<bits/stdc++.h>
using namespace std;
const int N=1e3+10;
int arr[N][N];
void fun()
{
    arr[0][1]=90;
}
int main()
{
    arr[0][1]=80;
    cout<<arr[0][1]<<endl;
    fun();
    cout<<arr[0][1]<<endl;
}
// 80
// 90