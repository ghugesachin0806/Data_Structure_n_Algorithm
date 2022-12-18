#include<bits/stdc++.h>
using namespace std;

int main()
{
    int x=4;
    int *ptr_x=&x;// pointer to int value
    //ptr_x=&x;
    cout<<"address of x... "<<ptr_x<<endl;
    cout<<"address of x... "<<&x<<endl;
    cout<<"value of x ..... "<<*ptr_x<<endl;
    *ptr_x=7;
    cout<<"value of x ..... "<<x<<endl;
    return 0;
}
// address of x... 0xd3fcdff694
// address of x... 0xd3fcdff694
// value of x ..... 4
// value of x ..... 7