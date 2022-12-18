#include <bits/stdc++.h>
using namespace std;

int main()
{
    int a = 90;
    void *ptr; // Void pointer
    ptr = &a;  // It can hold address of any datatype
    // Typecasting
    cout << *((int *)ptr) << endl; // To get the data from stored address , typecasting is done on void pointer
}
// 90