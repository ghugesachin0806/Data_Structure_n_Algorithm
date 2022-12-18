#include<bits/stdc++.h>
using namespace std;

// Global variable can be modified by any function and it will remains in modified state 

int glob=15; // Global variable declared

void a()
{
    cout<<"In the a func "<<glob<<endl;
    glob++;
}

void b()
{
    cout<<"In the b func "<<glob<<endl;
}

int main()
{
    cout<<"In the main func "<<glob<<endl;
    a();
    cout<<"Again in the main func "<<glob<<endl;
    b();
}

// In the main func 15      
// In the a func 15
// Again in the main func 16
// In the b func 16