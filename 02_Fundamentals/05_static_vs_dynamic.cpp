#include <bits/stdc++.h>
using namespace std;

int main()
{
    // case - I
    // Here due to static memory allocation, everytime after block terminates memory of stack will get release
    while (true)
    {
        int a = 5;
    }

    // case - II
    // Here due to dynamic memory allocation, we have to release the memory using 'delete' keyword
    // It will not automatically get release
    while (true)
    {
        int *ptr = new int;
        delete ptr;
    }
}