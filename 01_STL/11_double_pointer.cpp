// double pointer
#include<bits/stdc++.h>
using namespace std;

int main()
{
    int x=4;
    int *p=&x;  // pointer to int value
    //p=&x;
    int **ptr=&p; // pointer to pointer(double pointer)
    //ptr=&p;
    cout<<"address of x..."<<&x<<endl;
    cout<<"address of x..."<<p<<endl;
    cout<<"address of x..."<<*ptr<<endl;
    cout<<"address of p..."<<&p<<endl;
    cout<<"address of p..."<<ptr<<endl;
    cout<<"value of x......"<<x<<endl;
    cout<<"value of x......"<<*p<<endl;
    cout<<"value of x......"<<**ptr<<endl;
    return 0;
}
// address of x...0xb3519ffce4
// address of x...0xb3519ffce4
// address of x...0xb3519ffce4
// address of p...0xb3519ffcd8
// address of p...0xb3519ffcd8
// value of x......4
// value of x......4
// value of x......4