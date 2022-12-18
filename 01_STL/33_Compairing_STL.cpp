#include <bits/stdc++.h>
using namespace std;

int main()
{
    pair<int, int> p1, p2, p3;
    p1 = {7, 3};
    p2 = {3, 7};
    p3 = {3, 9};
    cout << (p1 > p2) << endl; // Here first elements get compaired
    cout << (p2 > p3) << endl; // If first element is same then second element get compaired

    set<int> s1, s2, s3, s4;
    s1 = {11, 34, 67, 89, 1};
    s2 = {9, 78, 45, 3};
    s3 = {2, 13, 90};
    s4 = {87, 89, 2, 5};
    // In sets first elements are ordered in sorted manner and then comparision is done
    // Comparison is done from first element of both the sets , if both are same then next element is choosen from both sets
    cout << (s1 > s2) << endl;
    cout << (s3 < s1) << endl;
    cout << (s3 > s4) << endl;
    
}